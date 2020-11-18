#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ld,ld> pii;
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
const ld eps=1e-12;
const int maxn=105;
pii earn[maxn];

bool comp(const pii &s1,const pii &s2)
{
	//return s1.se/s1.fi>s2.se/s2.fi;
	return s2.se*s1.fi<s1.se*s2.fi;
}

bool check(int n)
{
	ld val=1000000000000.0,pay=0.0;
	rep(i,0,n) pay+=val*earn[i].fi/(earn[i].fi+earn[i].se);
//	dd(n);de(pay);
	return pay+eps<val;
}

void test()
{
	int n;
	char ch;
	cin>>n;
	rep(i,0,n)
	{
		cin>>earn[i].fi>>ch>>earn[i].se;
	}
	sort(earn,earn+n,comp);
	//rep(i,0,n) dd(i),dd(earn[i].fi),de(earn[i].se);
	int ans=0;
	rept(i,1,n) if(check(i)) ans=i;
	cout<<ans<<"\n";
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>q;
	rept(i,1,q)
	{
		cout<<"Case #"<<i<<": ";
		test();
	}
	return 0;
}