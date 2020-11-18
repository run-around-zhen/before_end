#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll,ll> pii;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rept(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define all(x) x.begin(),x.end()
#define pb push_back
#define fi first
#define se second
#define mes(a,b) memset(a,b,sizeof a)
#define mp make_pair
#define dd(x) cout<<#x<<"="<<x<<" "
#define de(x) cout<<#x<<"="<<x<<"\n"
#define debug() cout<<"I love Miyamizu Mitsuha forever.\n"
const int inf=0x3f3f3f3f;
int mod;

void solve(ll x)
{
	if(!x) return ;
	if(x%mod==0)
	{
		solve(x/mod-1);
		cout<<9;
	}
	else
	{
		solve(x/mod);
		cout<<x%mod-1+mod;
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>q;
	while(q--)
	{
		ll x;
		cin>>mod>>x;
		solve(x);
		cout<<"\n";
	}
	return 0;
}