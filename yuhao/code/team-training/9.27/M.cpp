#include<bits/stdc++.h>

using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rept(i,x,y) for(int i=x;i<=y;i++)
#define pb push_back
#define mp make_pair
const int inf=0x3f3f3f3f;
const int maxn=52;
int dis[maxn][maxn][10005];

void test()
{
	int n,m;
	cin>>n>>m;
	rept(i,1,n) rept(j,1,n) rept(k,1,10000) dis[i][j][k]=inf;
	rep(i,0,m)
	{
		int a,b,d;
		cin>>a>>b>>d;
		dis[a][b][1]=min(dis[a][b][1],d);
	}
	rept(len,2,10000)
	{
		rept(k,1,n)
			rept(i,1,n)
				rept(j,1,n)
					dis[i][j][len]=min(dis[i][j][len],dis[i][k][len-1]+dis[k][j][1]);
	}
	int q;
	cin>>q;
	while(q--)
	{
		int a,b,d;
		cin>>a>>b>>d;
		int ans=inf;
		rept(i,d,min(d+50,10000)) ans=min(ans,dis[a][b][i]);
		if(ans==inf) cout<<"-1\n";
		else cout<<ans<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>q;
	while(q--) test();
	return 0;
}
