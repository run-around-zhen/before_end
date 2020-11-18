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
const int maxn=1005;
pii p[maxn];

ll cal(int i,int j,int k)
{
	ll ans=0;
	return abs((p[j].fi-p[i].fi)*(p[k].se-p[i].se)-(p[k].fi-p[i].fi)*(p[j].se-p[i].se));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>q;
	ll ans=0;
	while(q--)
	{
		int n;
		cin>>n;
		rep(i,0,n) cin>>p[i].fi>>p[i].se;
		rep(i,1,n-1) ans+=cal(0,i,i+1);
	}
	cout<<ans/2<<"\n";
	return 0;
}