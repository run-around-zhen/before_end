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
const int N=2e6+5;
const int mod=1000000007;
int a[N],f[N];
map<int,int> mp;
ll qpow(ll a,ll n){
	ll re=1;
	while(n>0){
		if(n&1){
			re*=a;
			re%=mod;
		}
		a*=a;
		a%=mod;
		n>>=1;
	}
	return re;
}
int cal(int n){
	return 1ll*f[2*n]*qpow(f[n],mod-2)%mod*qpow(f[n],mod-2)%mod*qpow(n+1,mod-2)%mod;
}
int main()
{	
	f[0]=1;
	for(int i=1;i<N;i++){
		f[i]=1ll*f[i-1]*i%mod;
	}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		//mp[a[i]]++;
	}
	int ans=1;
	stack<int>st;
	for(int i=1;i<=n;i++){
		
			ans=1ll*ans*cal(mp[a[i]])%mod;
			mp[a[i]]=0;
		}
	}
	printf("%d",ans);
}