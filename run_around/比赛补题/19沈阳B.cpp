#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 205;

struct edge{
	int x,y;
	double v1,v2;
}a[2*maxn];

struct node{
	int x;
	double v;
	node(int a,double b)
	{
		x = a;
		v = b;
	}
	bool operator<(const node&n)const
	{
		return v > n.v;
	}
};

vector<node> g[maxn];
int vis[maxn];
double dist[maxn];

void dij(int begin,int n)
{
	priority_queue<node> q;
	for (int i = 1; i <= n; i++)
	{
		vis[i] = 0;
		dist[i] = 1e18;
	} 
	dist[begin] = 0;
	q.push(node(begin,0));
	while( !q.empty() )
	{
		node t = q.top();
		q.pop();
		if( vis[t.x] ) continue; 
		vis[t.x] = 1;
		for (int i = 0; i < g[t.x].size(); i++)
		{
			int x = g[t.x][i].x;
			if( dist[t.x] + g[t.x][i].v < dist[x] )
			{
				dist[x] = dist[t.x] + g[t.x][i].v;
				q.push(node(x,dist[x]));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,s,t;
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].v1 >> a[i].v2;
	}
	double ans = 0;
	double eps = 1e-5;
	for (double z = 0; z <= 1; z += eps)
	{
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= m; i++)
		{
			double v = a[i].v1 + a[i].v2 * z;
			g[a[i].x].push_back(node(a[i].y,v));
			g[a[i].y].push_back(node(a[i].x,v));  
		}
		dij(s,n);
		//cout << dist[t] << '\n';
		ans += eps*dist[t];
	}
	cout.precision(6);
	cout << fixed << ans << '\n';
	return 0;
}
