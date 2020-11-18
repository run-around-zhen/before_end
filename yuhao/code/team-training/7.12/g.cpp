#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll,ll> pii;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rept(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define all(x) x.begin(),x.end()
#define pb push_back
#define fi first
#define se second
#define mes(a,b) memset(a,b,sizeof a)
#define mp make_pair
#define dd(x) cout<<#x<<"="<<x<<" "
#define de(x) cout<<#x<<"="<<x<<"\n"
#define debug() cout<<"I love Miyamizu Mitsuha forever.\n"
const int inf=0x3f3f3f3f;
 
const int maxn=1e6+5;
int n,m;
int tax[maxn],rak[maxn],tp[maxn],sa[maxn];
char s[maxn];
int nex[maxn];
vector<int> v[maxn];
 
void sor(int a[],int b[]){
    for(int i=0;i<=m;i++)tax[i]=0;
    for(int i=1;i<=n;i++)tax[a[i]]++;
    for(int i=1;i<=m;i++)tax[i]+=tax[i-1];
    for(int i=n;i>=1;i--)sa[tax[a[b[i]]]--]=b[i];
     
}
 
bool comp(int r[],int a,int b,int k){
    return r[a]==r[b]&&r[a+k]==r[b+k];
}
 
void get_sa(int a[],int b[]){
    m=1e5+5;
    /*for(int i=1;i<=n;i++)
        a[i]=s[i],b[i]=i;
        */
    int lasta=-1,lastb=-1;
    rept(i,1,n)
    {
        if(s[i]=='a')
        {
            if(lasta==-1) a[i]=0;
            else a[i]=i-lasta;
            lasta=i;
        }
        else
        {
            if(lastb==-1) a[i]=0;
            else a[i]=i-lastb;
            lastb=i;
        }
        b[i]=i;
    }
    sor(a,b);
    for(int p=0,j=1;p<n;j<<=1,m=p)
    {
        p=0;
        for(int i=1;i<=j;i++) b[++p]=n-j+i;
        for(int i=1;i<=n;i++)
            if(sa[i]>j) b[++p]=sa[i]-j;
        sor(a,b);
        int *t=a;a=b;b=t;
        a[sa[1]]=p=1;
        for(int i=2;i<=n;i++)
            a[sa[i]]=comp(b,sa[i],sa[i-1],j)?p:++p;
    }
}
 
bool comp2(int a,int b)
{
    return rak[a]<rak[b];
}
 
int main()
{
   // ios::sync_with_stdio(false);
   // cin.tie(0);
	srand(time(0));
    int qq = 0;
    while(1)
    {
    	qq ++;
    	//cout << qq << endl;
    /*  mes(tax,0);
        mes(rak,0);
        mes(tp,0);
        mes(sa,0);*/
        n = rand() % 5 + 1;
        rept(i,0,n*3) tax[i]=rak[i]=tp[i]=sa[i]=0;
        bool flag=0;
        rep(i, 1, n + 1) s[i] = (char)(rand()% 2 + 'a');
        cout << n <<endl;
        rep(i,1, n + 1) cout << s[i];
        cout << endl;
        rept(i,0,n) v[i].clear();
        get_sa(rak,tp);
        //for(int i=1;i<=n;i++) cout<<sa[i]<<" ";cout<<"\n";
        for(int i=1;i<=n;i++) rak[sa[i]]=i;
        rak[n+1]=0;
        rak[n+2]=-1;
    //  rept(i,1,n) cout<<rak[i]<<" ";cout<<"\n";
        int nexta=-1,nextb=-1;
        for(int i=n;i>=1;i--)
        {
            if(s[i]=='a')
            {
                nex[i]=nextb;
                nexta=i;
            }
            else
            {
                nex[i]=nexta;
                nextb=i;
            }
            if(nex[i]==-1)
            {
                v[n-i].pb(i);
                //dd(i);de(n-i);
            }
            else
            {
                v[nex[i]-i-1].pb(i);
                //dd(i);de(nex[i]-i-1);
            }
        }
        flag=0;
        rept(i,0,n)
        {
            if(!v[i].size()) continue;
            rep(j,0,v[i].size())
            {
//              dd(i);de(v[i][j]);
                v[i][j]+=i+2;
            }
            sort(all(v[i]),comp2);
            rep(j,0,v[i].size())
            {
                if(flag) ;//cout<<" ";
                else flag=!flag;
               // cout<<v[i][j]-i-2;
            }
        }
        cout<<"\n";
    }
    return 0;
}