#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <set>
#include <stdio.h>
#include <time.h>
using namespace std;
#define LL __int64
#define pi acos(-1.0)
#pragma comment(linker, "/STACK:1024000000")
const int mod=9901;
const int INF=0x3f3f3f3f;
const double eqs=1e-9;
const int MAXN=300000+10;
int head[MAXN], cnt, ha[MAXN], vis[MAXN];
LL d[MAXN];
struct node
{
        int u, v, next;
        LL w;
}edge[MAXN<<1];
void add(int u, int v, LL w)
{
        edge[cnt].v=v;
        edge[cnt].w=w;
        edge[cnt].next=head[u];
        head[u]=cnt++;
}
void spfa(int st)
{
        queue<int>q;
        q.push(st);
        memset(vis,0,sizeof(vis));
        d[st]=0;
        while(!q.empty()){
                int u=q.front();
                q.pop();
                vis[u]=0;
                for(int i=head[u];i!=-1;i=edge[i].next){
                        int v=edge[i].v;
                        if(d[v]>d[u]+edge[i].w){
                                d[v]=d[u]+edge[i].w;
                                if(!vis[v]){
                                        vis[v]=1;
                                        q.push(v);
                                }
                        }
                }
        }
}
struct node1
{
        int u, v, id;
        LL w;
}fei[MAXN];
int tot=0, bin[MAXN], in[MAXN];
int find1(int x)
{
        return bin[x]==x?x:bin[x]=find1(bin[x]);
}
bool cmp(node1 f1, node1 f2)
{
        return f1.w<f2.w;
}
void init(int n)
{
        for(int i=1;i<=n;i++) bin[i]=i;
        memset(in,0,sizeof(in));
}
void krus(int n, int m)
{
        sort(fei,fei+tot,cmp);
        int i;
        LL ans=0;
        init(n);
        for(i=0;i<tot;i++){
                int u=fei[i].u;
                int v=fei[i].v;
                if(in[v]) continue ;
                int f1=find1(bin[fei[i].u]);
                int f2=find1(bin[fei[i].v]);
                if(f1!=f2){
                        bin[f2]=f1;
                        ans+=fei[i].w;
                        ha[fei[i].id]=1;
                        in[v]++;
                }
        }
        printf("%I64d\n",ans);
                for(int i=1;i<=m;i++){
                        if(ha[i]){
                                printf("%d ",i);
                        }
                }
                puts("");
}
int main()
{
        int n, m, i, j, u, v;
        LL w, ans;
        while(scanf("%d%d",&n,&m)!=EOF){
                memset(head,-1,sizeof(head));
                cnt=0;
                for(i=1;i<=n;i++){
                        d[i]=(LL)1e16;
                }
                for(i=1;i<=m;i++){
                        scanf("%d%d%I64d",&u,&v,&w);
                        add(u,v,w);
                        add(v,u,w);
                }
                scanf("%d",&u);
                spfa(u);
                memset(ha,0,sizeof(ha));
                ans=0;
                for(i=1;i<=n;i++){
                        for(j=head[i];j!=-1;j=edge[j].next){
                                int v =edge[j].v;
                                if(d[i]+edge[j].w==d[v]){
                                        fei[tot].u=i;
                                        fei[tot].v=v;
                                        fei[tot].w=edge[j].w;
                                        fei[tot++].id=j/2+1;
                                }
                        }
                }
                krus(n,m);
        }
        return 0;
}