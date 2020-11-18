#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rept(i,x,y) for(int i=x;i<=y;i++)
#define pb push_back
#define dd(x) cout<<#x<<"="<<x<<" "
#define de(x) cout<<#x<<"="<<x<<"\n"
#define mp make_pair
const int maxn=15;
const int mod=1e9+7;
int cnt[maxn][maxn];
ll dp[1050];

vector<int> v;
ll ans[maxn];
ll fac[maxn],ni[maxn];

ll qpow(ll a,ll b)
{
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1) ans=ans*a%mod;
	return ans;
}
void init()
{
	fac[0]=1;
	rep(i,1,10)fac[i]=fac[i-1]*i%mod;
	rep(i,1,10) ni[i]=qpow(fac[i],mod-2);
}
void test()
{
	int n,q;
	cin>>n>>q;
	rept(i,0,n) rept(j,0,n) cnt[i][j]=0;
	while(q--)
	{
		dp[0]=1;
		char op;
		int a,b;
		cin>>op>>a>>b;
		a--,b--;
		if(op=='+') cnt[a][b]++,cnt[b][a]++;
		else cnt[a][b]--,cnt[b][a]--;
		rept(i,1,n/2) ans[i]=0;
		for(int i=1;i<(1<<n);i++)
		{
			dp[i]=0;
			v.clear();
			for(int j=0;j<n;j++) if(i&(1<<j)) v.pb(j);
			if(v.size()%2==1) continue;
			rep(j,0,v.size())
			{
				rep(k,j+1,v.size())
				{
					//if(i==12) de(i-(1<<k)-(1<<j));
					dp[i]=(dp[i]+dp[i-(1<<v[k])-(1<<v[j])]*cnt[v[k]][v[j]])%mod;
				}
			}
			ans[v.size()/2]=(ans[v.size()/2]+dp[i])%mod;
		//	if(v.size()/2==1) dd(i),de(dp[i]);
		}
	//	de(dp[3]);
		rept(i,1,n/2)
		{
		//	cout<<ans[i];
			cout<<ans[i]*ni[i]%mod;
			if(i==n/2) cout<<"\n";
			else cout<<" ";
		};
	}
}

int main()
{
	init();
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>q;
	while(q--) test();
	return 0;
}
