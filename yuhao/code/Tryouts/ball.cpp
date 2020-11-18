#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
const ll Inf=1e18;
ll fac[N],inv[N];
ll C(int m,int n){
	return fac[m]*inv[n]%mod*inv[m-n]%mod;
} 
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main(){
	int n;
	fac[0]=1;inv[0]=1;inv[1]=1;
	rep(i,2,N)inv[i]=-mod/i*inv[mod%i]%mod+mod;
	rep(i,1,N)fac[i]=fac[i-1]*i%mod,inv[i]=inv[i]*inv[i-1]%mod;
	while(scanf("%d",&n)!=EOF){
		ll ans=0;
		for(int i=0;i<=n;i+=2){
			ans+=qpow(2,n-i)*C(i,i>>1)%mod*C(n,i)%mod*C((2*n+i)/2-1,n-1)%mod;
		}
		for(int i=0;i<n;i+=2){
			ans+=qpow(2,n-1-i)*C(i,i>>1)%mod*C(n-1,i)%mod*C((2*n+i)/2-1,n-2)%mod;
		}
		ans=ans*3%mod;
		printf("%lld\n",ans);
	}
} 