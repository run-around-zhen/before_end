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
const int maxn=2005;
typedef pair<pii,pii> ppp;
map<ppp,ll> m;

pii point[maxn];


pii solve(ll a,ll b)
{
	ll gcd=__gcd(abs(a),abs(b));
	a/=gcd;
	b/=gcd;
	if(a==0)
	{
		b=1;
		return mp(a,b);
	}
	if(a<0) a=-a,b=-b;

	return mp(a,b);
}

ppp call(ll x1,ll y1,ll x2,ll y2)
{
	pii a=solve(y2*x1*x1+y1*y1*y2-x2*x2*y1-y2*y2*y1,x2*y1-y2*x1);
	pii b=solve(x2*y1*y1+x1*x1*x2-y2*y2*x1-x2*x2*x1,y2*x1-x2*y1);
	return mp(a,b);
}
ll get(ll a, ll b, ll c, ll d){
	return (a % mod * 213 * 213 * 213 % mod  + b % mod * 213 * 213 % mod + c % mod * 213 % mod + d % mod) % mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool flag=0;
	int n;
	cin>>n;
	rept(i,1,n)
	{
		cin>>point[i].fi>>point[i].se;
		if(point[i].fi==0&&point[i].se==0) flag=1;
	}
	ll ans=0;
	m.clear();
	rept(i,1,n)
	{
		rept(j,i+1,n)
		{
			if(point[i].se*point[j].fi==point[i].fi*point[j].se) continue;
			flag=1;
			ppp p=call(point[i].fi,point[i].se,point[j].fi,point[j].se);
		//	dd(i);dd(j);dd(p.fi.fi);dd(p.fi.se);dd(p.se.fi);de(p.se.se);
			ans=max(ans,++m[p]);
		}
	}
	if(!flag)
	{
		cout<<1<<"\n";
	}
	else
	{
		rept(i,1,n) if(i*(i-1)/2>=ans)
		{
			cout<<i<<"\n";
			return 0;
		}
	}
	return 0;
}