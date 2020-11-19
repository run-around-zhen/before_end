#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5;

vector<int> g[maxn];
int fa[maxn][20],val[maxn][20][10],dep[maxn];
int v[maxn];

void merge(int a[10],int b[10],int c[10])
{
	int l1 = 0,l2 = 0;
	int res[10];
	for (int i = 0; i < 10; i++)
	{
		if( a[l1] > b[l2] )
		{
			res[i] = b[l2];
			l2 ++;
		}else
		{
			res[i] = a[l1];
			l1 ++;
		}
	}
	for (int i = 0; i <10; i++) c[i] = res[i];
}

void dfs(int x,int fath)
{
	dep[x] = dep[fath] + 1;
	fa[x][0] = fath;
	for (int i = 1; (1<<i) <= dep[x]; i++)
	{
		for (int j = 0; j < 10; j++) val[x][i][j] = 1e9;
		fa[x][i] = fa[fa[x][i-1]][i-1];
		int t = fa[x][i-1];
		merge(val[x][i-1],val[t][i-1],val[x][i]);
	}
	for (int i = 0; i < g[x].size(); i++)
	{
		if( g[x][i] != fath ) dfs(g[x][i],x);
	}
}

int res[10];

void lca(int x,int y)
{
	if( dep[x] < dep[y] ) swap(x,y);
	while( dep[x] != dep[y] )
	{
		int c = log2(dep[x]-dep[y]);
		merge(val[x][c],res,res);
		x = fa[x][c];
	}
	if( x == y ) 
	{
		merge(val[x][0],res,res);
		return;
	}
	for (int i = log2(dep[x]); i >= 0; i--)
	{
		if( fa[x][i] != fa[y][i] )
		{
			merge(val[x][i],res,res);
			merge(val[y][i],res,res);
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	merge(val[x][0],res,res);
	merge(val[y][0],res,res);
	merge(val[fa[x][0]][0],res,res);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k; 
	cin >> n >> m >> k;
	for (int i = 0; i <= n; i++) 
	{
		for (int j = 0; j < 10; j++) val[i][0][j] = 1e9;
	}
	for (int i = 1; i < n; i++)
	{
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int z[10];
	for (int i = 0; i < 10; i++) z[i] = 1e9; 
	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		z[0] = i;
		merge(z,val[x][0],val[x][0]);
	}
	dfs(1,0);
	for (int i = 1; i <= k; i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		for (int j = 0; j < 10; j++) res[j] = 1e9;
		lca(x,y);
		vector<int> ans; 
		for (int j = 0; j < z; j++)
		{
			if( res[j] == 1e9 ) break;
			ans.push_back(res[j]);
		}
		cout << ans.size();
		for (int j = 0; j < ans.size(); j++)
		{
			cout << " " << ans[j];
		}
		cout << '\n'; 
	}
	return 0;
}

