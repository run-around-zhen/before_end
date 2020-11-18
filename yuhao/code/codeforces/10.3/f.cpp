#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 0x3f3f3f3f;
int f[N],g[N],h[N],p[4],q[4],n,rt;
vector<int> G[N];
void dfs(int u,int fa){
    f[u]=g[u]=INF;
    if(fa&&G[u].size()==1){
        f[u]=1; h[u]=1; g[u]=0;
        return ;
    }
    int dp=0,tp=0,fp=0,hp=0;
    for(auto v:G[u]){
        if(v==fa) continue;
        dfs(v,u);
        dp+=min(min(f[v],g[v]),h[v]);
        tp+=min(f[v],h[v]);
        fp+=f[v]; hp+=h[v];
    }
    f[u]=min(dp+1,fp); g[u]=tp; h[u]=dp+1;
    p[0]=0; for(int i=1;i<4;++i) p[i]=N;
    for(auto v:G[u]){
        if(v==fa) continue;
        g[u]=min(g[u],tp-min(f[v],h[v])+g[v]);
        f[u]=min(f[u],tp-min(f[v],h[v])+f[v]);
        memcpy(q,p,sizeof(p));
        p[0]=q[0]+min(f[v],h[v]);
        p[1]=min(q[1]+min(f[v],h[v]),q[0]+f[v]);
        p[2]=min(q[2]+min(f[v],h[v]),q[0]+g[v]);
        p[3]=min(q[3]+min(f[v],h[v]),q[2]+f[v]);
        p[3]=min(p[3],q[1]+g[v]);
    }
    h[u]=min(h[u],p[1]); h[u]=min(h[u],p[3]);
    cout << u << " " << h[u] << " " << g[u] << " " << f[u] << endl;
} 
int main(){
    scanf("%d",&n);
    for(int i=1,u,v;i<n;++i){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        if(G[i].size()==1){
            rt=i; break;
        }
    }
    dfs(rt,0); printf("%d\n",min(f[rt],h[rt]));
}
