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
const int inf=1e5+5;
const int maxn=55;
int e[maxn][maxn];
bool del[maxn][maxn];
int n;
int ans;
int dis[maxn];
bool vis[maxn];

void dfs(int k)
{
	int f[maxn];
	mes(f,0);
	rept(i,1,n) vis[i]=0;
	rept(i,2,n) dis[i]=inf;
	dis[1]=0;
	f[1]=-1;
	rept(i,2,n)
	{
		if(del[1][i]==0)
		{
			dis[i]=e[1][i];
			f[i]=1;
		}
	}
	vis[1]=1;
	rep(k,1,n)
	{
		int id=-1;
		rept(i,2,n)
		{
			if(!vis[i])
			{
				if(id==-1||dis[id]>dis[i]) id=i;
			}
		}
		vis[id]=1;
		rept(i,2,n)
		{
			if(id==i) continue;
			if(vis[i]==0&&del[id][i]==0&&dis[id]+e[id][i]<=dis[i])
			{
				f[i]=id;
				dis[i]=dis[id]+e[id][i];
			}
		}
	}
	if(k==0)
	{
		ans=max(ans,dis[n]);
		return ;
	}
	int p=n;
	while(p!=1)
	{
		del[p][f[p]]=del[f[p]][p]=1;
		dfs(k-1);
		del[p][f[p]]=del[f[p]][p]=0;
		p=f[p];
	}
}

void test()
{
	int k;
	n = 50;
	k = 5;
	rep(i, 0, n){
		rep(j, i + 1, n){
			e[i][j] = e[j][i] = rand() % 40000 + 1;
		}
	}
	/*rep(i,0,n*(n-1)/2)
	{
		int a,b,d;
		cin>>a>>b>>d;
		e[a][b]=e[b][a]=d;
	}*/
	ans=0;
	rept(i,1,n) rept(j,1,n) del[i][j]=0;
	dfs(k);
	cout<<ans<<"\n";
}

int main()
{
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q = 50;
	while(q--)
	{
		test();
	}
	return 0;
}
/*
1
5 1
1 2 2990
1 3 2414
1 4 4018
1 5 6216
2 3 9140
2 4 4169
2 5 550
3 4 6618
3 5 3206
4 5 105

*/