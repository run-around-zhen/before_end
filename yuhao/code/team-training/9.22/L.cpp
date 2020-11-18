#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rept(i,x,y) for(int i=x;i<=y;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define dd(x) cout<<#x<<"="<<x<<" "
#define de(x) cout<<#x<<"="<<x<<"\n"
#define pb push_back
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const int maxn=2005;
map<int,int> m;
set<int> s;
pii lr[maxn];
vector<int> v[maxn];
int dp[maxn][maxn<<1],dp2[maxn];

void dfs(int id,int f)
{
	rept(i,lr[id].fi,lr[id].se) dp[id][i]=0;
	dp2[id]=inf;
	rep(i,0,v[id].size())
	{
		if(v[id][i]!=f) dfs(v[id][i],id);
	}
	rep(i,0,v[id].size())
	{
		if(v[id][i]==f) continue;
		rept(j,lr[id].fi,lr[id].se)
		{
	//		if(id==3) de(v[id][i]);
			if(j<lr[v[id][i]].fi||j>lr[v[id][i]].se) dp[id][j]+=dp2[v[id][i]]+1;
			else dp[id][j]+=min(dp2[v[id][i]]+1,dp[v[id][i]][j]);
		}
	}
	rept(i,lr[id].fi,lr[id].se) dp2[id]=min(dp2[id],dp[id][i]);
}

void test()
{
	int n;
	cin>>n;
	rept(i,1,n) v[i].clear();
	s.clear();
	m.clear();
	rep(i,1,n)
	{
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	rept(i,1,n)
	{
		cin>>lr[i].fi>>lr[i].se;
		s.insert(lr[i].fi);
		s.insert(lr[i].se);
	}
	s.insert(0);
	int x=0;
	for(set<int>::iterator pos=s.begin();pos!=s.end();pos++) m[*pos]=x++;
	rept(i,1,n)
	{
		lr[i].fi=m[lr[i].fi];
		lr[i].se=m[lr[i].se];
//		dd(i);dd(lr[i].fi);de(lr[i].se);
	}
	dfs(1,-1);
//	de(dp[3][2]);
	if(m[0]>=lr[1].fi&&m[0]<=lr[1].se) cout<<min(dp[1][m[0]],dp2[1]+1)<<"\n";
	else cout<<dp2[1]+1<<"\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>q;
	while(q--)
		test();
	return 0;
}
