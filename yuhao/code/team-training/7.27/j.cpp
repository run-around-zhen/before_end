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
const int mod=1e9+7;
const int N=1e5+5;
int n,m,a[N],b[N],vis[N],cnt[8*N],c[N];
int query(int x)
{
    int ans=0;
    for(int i=x;i;i-=(i&(-i)))
        ans+=cnt[i];
    return ans;
}
void update(int x)
{
    for(int i=x;i<=n;i+=(i&(-i)))
        cnt[i]++;
}
void solve1(int k){
    for(int i=1;i<=n;i++){
        cnt[i] = 0;
    }
    int now=1;
    for(int i=1;i<=n;i++){
        now = (now + k - 2)%(n - i + 1) + 1;
        int l = 1,r = n;
        int pos = n;
        while(l <= r){
        	int mid = (l + r) / 2;
         	if(mid - query(mid) >= now){
        		r = mid - 1;
        		pos = min(pos, mid);
        	}
        	else{
        		l = mid + 1;
        	}
        }
        b[i] = pos;
        update(pos);
    }
}
void solve2(int x){
    while(x)
    {
        if(x&1)
        {
            for(int i=1;i<=n;i++)
                 c[i]=a[b[i]];
              for(int i=1;i<=n;i++)
                 a[i]=c[i];
         }
        for(int i=1;i<=n;i++)
             c[i]=b[b[i]];
        for(int i=1;i<=n;i++)
            b[i]=c[i];
         x>>=1;
    }
    
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    for(int i=1;i<=m;i++){
        int k,x;
        scanf("%d%d",&k,&x);
        solve1(k);
        solve2(x);
    }
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
}