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
const int N=3e5+5;
ll a[N],sum1[N],sum2[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+n+1);
		ll ans=0;
		if(n%4==0){
			for(int i=2;i<=n;i+=2){
				ans+=a[i]-a[i-1];
			}
			for(int i=4;i<=n;i+=4){
				ans+=a[i]-a[i-2];
				ans+=a[i-1]-a[i-3];
			}
		}
		else{
			for(int i=n+1;i<=n+10;i++){
				a[i]=sum1[i]=sum2[i]=0;
			}
			for(int i=2;i<=n;i+=2){
				ans+=a[i]-a[i-1];
			} 
			for(int i=4;i<=n;i+=4){
				sum1[i]=sum1[i-4]+a[i]-a[i-2]+a[i-1]-a[i-3];
			}
			for(int i=n-3;i>=1;i-=4){
				sum2[i]=sum2[i+4]+a[i+3]-a[i+1]+a[i+2]-a[i];
			}
			ll mn=1e18;
			for(int i=6;i<=n;i+=4){
//				de(sum1[i-6]),de(sum2[i+1]);
				mn=min(mn,sum1[i-6]+sum2[i+1]+a[i]-a[i-3]+a[i-1]-a[i-4]+a[i-2]-a[i-5]);
			}
			for(int i=4;i<=n;i+=4){
//				dd(sum1[i]),de(sum2[i+3]);
			//	mn=min(mn,sum1[i]+sum2[i+3]+a[i+2]-a[i]+a[i+1]-a[i-1]+a[i-1]-a[i]);
			}
			ans+=mn;
		}
		printf("%lld\n",ans);
	}
}