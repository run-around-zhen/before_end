#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
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
int a[N],b[N],ans[N],vis[N],cnt;
int q[N];
void dfs(int now){
    if(!vis[now]){
        vis[now]=1;
        q[++cnt]=now;
        dfs(a[now]);
    }
}
int pos[N];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]){
            continue;
        }
        if(a[i]==i){
            ans[i]=i;
        }
        else{
            cnt=0;
            dfs(i);
            for(int i=1;i<=cnt;i++){
                b[i]=0;
            }
            int t=k%cnt;
            int now=1;
            int v=a[i];
            b[1]=a[i];
            while(1){
                if(b[(now+t-1)%cnt+1]!=0){
                    break;
                }
                v=pos[v];
                b[(now+t-1)%cnt+1]=v;
                now=(now+t-1)%cnt+1;
            }
            for(int i=1;i<=cnt;i++){
                ans[pos[b[i]]]=b[i%cnt+1];
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
}