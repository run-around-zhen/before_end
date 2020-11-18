#include<bits/stdc++.h>
#define PI acos(-1)
#define pb push_back
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define dd(x) cout<<#x<<" = "<<x<<","
#define de(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
const int M=20;
inline int read(void)
{
    char c;
    register int x=0;
    c=getchar();
    while (c<'0'||c>'9')
    {
        c=getchar();
    }
    while ( c>='0' && c<='9')
    {
        x*=10;
        x+=c-'0';
        c=getchar();
    }
    return x;
}

struct tree{
    int rt[N],ls[50*N],rs[50*N],v[2][50*N],cnt;
    inline void init(){
        for(register int i=1;i<N;i++){
            rt[i]=i;
        }
        cnt=N-1;
    }
    void update(int x,int &y,int z,int val,int l,int r){
        if(y==0)
        y=++cnt,v[0][y]=v[1][y]=ls[y]=rs[y]=0;
        
        v[z][y]+=val;
        if(l==r)
        return;
        register int mid=(l+r)/2;
        if(x<=mid){
            update(x,ls[y],z,val,l,mid);
        }
        else{
            update(x,rs[y],z,val,mid+1,r);
        }
    }
    int query(int ql,int qr,int &y,int z,int l,int r){
        if(y==0)
        return 0;
        if(ql>r||qr<l){
            return 0;
        }
        else if(ql<=l&&qr>=r){
            return v[z][y];
        }
        register int mid=(l+r)/2;
        return query(ql,qr,ls[y],z,l,mid)+query(ql,qr,rs[y],z,mid+1,r);
    }
};
tree T;
vector<int> v[N];
int col[N],val[N];

int fa[N],s[N],son[N];
void dfs1(int now,int pre){
    s[now]=1;fa[now]=pre;
    int mx=0;
    for(register int i=0;i<v[now].size();i++){
        if(v[now][i]==pre)
        continue;
        dfs1(v[now][i],now);
        s[now]+=s[v[now][i]];
        if(s[v[now][i]]>mx){
            mx=s[v[now][i]];
            son[now]=v[now][i];
        }
    }
}
int top[N],id[N],rk[N],cnt;
void dfs2(int now,int pre){
    top[now]=pre;
    id[now]=++cnt;
    rk[cnt]=now;
    if(son[now]==0)
    return;
    dfs2(son[now],pre);
    for(int i=0;i<v[now].size();i++){
        if(v[now][i]==fa[now]||v[now][i]==son[now])
        continue;
        dfs2(v[now][i],v[now][i]);
    }
}
ll sum=0;
int n;
inline void add(int x,int y,int z){
    T.update(id[x],T.rt[y],z,1,1,n);
    sum+=T.query(1,n,T.rt[y],z^1,1,n);
    sum-=T.query(id[x],id[x]+s[x]-1,T.rt[y],z^1,1,n);
    
    x=fa[x];
    while(x!=0){
        sum-=T.query(id[top[x]],id[x],T.rt[y],z^1,1,n);
        x=fa[top[x]];
    }
}
inline void del(int x,int y,int z){
//    dd(x),dd(y),de(z);
    //?y??????x???z -1 
    T.update(id[x],T.rt[y],z,-1,1,n);
    sum-=T.query(1,n,T.rt[y],z^1,1,n);
    sum+=T.query(id[x],id[x]+s[x]-1,T.rt[y],z^1,1,n);
    
    x=fa[x];
    while(x!=0){
        sum+=T.query(id[top[x]],id[x],T.rt[y],z^1,1,n);
        x=fa[top[x]];
    }
}
ll ans[N];
int val2[N],col2[N],x[N],y[N],z[N];
int main()
{    
    int t;
    while(cin >> t){
    while(t--){
        cnt=0;sum=0;
        T.init();
 //       scanf("%d",&n);
         n=read();
        for( int i=1;i<=n;i++){
        //    scanf("%d",&col[i]);
            col[i]=read();
        }
        for( int i=1;i<=n;i++){
        //    scanf("%d",&val[i]);
            val[i]=read();
        }
        for( int i=1;i<n;i++){
             int x=read(),y=read();
        //    scanf("%d%d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
        }
        dfs1(1,0);
        dfs2(1,1); 
         int q=read();
        //scanf("%d",&q);
        for(int i=1;i<=q;i++){
        //    scanf("%d%d%d",&x[i],&y[i],&z[i]);
            x[i]=read();y[i]=read();z[i]=read();
        }
        for(int i=0;i<20;i++){
            for(int j=1;j<=n;j++){
                val2[j]=val[j]>>i&1;
                col2[j]=col[j];
                add(j,col2[j],val2[j]);
//                de(val2[j]),de(sum);
            }
            ans[0]+=sum*(1<<i);
            for(int j=1;j<=q;j++){
                if(x[j]==1){
                    if(val2[y[j]]!=(z[j]>>i&1)){
                        del(y[j],col2[y[j]],val2[y[j]]);
                        val2[y[j]]^=1;
                        add(y[j],col2[y[j]],val2[y[j]]);
                    }
                }
                else if(x[j]==2){
                    if(col2[y[j]]!=z[j]){
                        del(y[j],col2[y[j]],val2[y[j]]);
                        col2[y[j]]=z[j];
                        add(y[j],col2[y[j]],val2[y[j]]);
                    }
                }
//                dd(j),dd(sum),de((1<<i));
                ans[j]+=sum*(1<<i);
            }
            for(int j=1;j<=n;j++){
                del(j,col2[j],val2[j]);
            }
        }
        for(int i=0;i<=q;i++){
            printf("%lld\n",ans[i]);
        }
        
        for(int i=0;i<=n;i++){
            son[i]=ans[i]=0;
            v[i].clear();
        }
    }
}
}