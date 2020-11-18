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
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
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
int a[N],b[N],ans[N],vis[20],cnt;
int q[N];
void dfs(int now){
    if(!vis[now]){
        vis[now]=1;
        q[++cnt]=now;
//      de(now);
        dfs(a[now]);
    }
}
int pos[N];
int main()
{
	srand(time(0));
    
    while(1){int n = rand() % 10 + 1,k = 998244353;
    	memset(vis, false,sizeof(vis));
    	rep(i, 1, n + 1) a[i] = i;
    	random_shuffle(a + 1, a + 1 + n);
    for(int i=1;i<=n;i++){
       // scanf("%d",&a[i]);
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
//          de(cnt);
            int t=k%cnt;
            int now=1;
            int v=a[i];
            b[1]=a[i];
            while(1){
                if(b[(now+t-1)%cnt+1]!=0){
                    break;
                }
//              dd(now),dd((now+t-1)%cnt+1),de(q[now]);
                v=pos[v];
                b[(now+t-1)%cnt+1]=v;
                 
//              dd(v),de(pos[v]);
                now=(now+t-1)%cnt+1;
            }
            for(int i=1;i<=cnt;i++){
//              dd(b[i]),de(q[i]);
                ans[pos[b[i]]]=b[i%cnt+1];
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    cout << endl ;
}
}