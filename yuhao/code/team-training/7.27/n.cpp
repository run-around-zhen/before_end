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
const int N=2e7+5; 
const int mod=1e9+7;
int a[N],b[N]; 
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
int main()
{
	int sum=2;
	a[1]=1;
	for(int i=2;i<N;i++){
		a[i]=1ll*a[i-1]*sum%mod;
		sum+=sum;
		if(sum>=mod)
		sum-=mod;
	}
	b[1]=1;
	sum=4;
	for(int i=2;i<N;i++){
		if(sum>=1)
		b[i]=1ll*b[i-1]*(sum-1)%mod;
		else if(sum==0)
		b[i]=1ll*b[i-1]*(mod-1)%mod;
		sum+=sum;
		if(sum>=mod)
		sum-=mod;
		
//		dd(i),de(b[i]);
		
		a[i]=1ll*a[i]*b[i]%mod;
	}
	for(int i=1;i<N;i++){
		a[i]=a[i]*qpow(2,i*i,mod);
		a[i]^=a[i-1];
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
}