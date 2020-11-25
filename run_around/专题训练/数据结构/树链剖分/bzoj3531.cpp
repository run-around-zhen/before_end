#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;
typedef long long ll;

vector<int> g[maxn];
int w[maxn],c[maxn];

struct node{
	int l,r;
	ll sum,maxn;
}a[maxn*40];

int root[maxn],cntx = 0;

void update(int x)
{
	a[x].sum = a[a[x].l].sum + a[a[x].r].sum;
	a[x].maxn = max(a[a[x].l].maxn,a[a[x].r].maxn);
}

void insert(int l,int r,int pre,int &now,int p,int v)
{
	now = ++cntx;
	a[now] = a[pre];
	if( l == r )
	{
		a[now].sum = a[now].maxn = v;
		return;
	}
	int m = ( l + r ) >> 1;
	if( p <= m ) insert(l,m,a[pre].l,a[now].l,p,v);
	else insert(m+1,r,a[pre].r,a[now].r,p,v);
	update(now); 
}

ll query(int lx,int rx,int l,int r,int now,int flag)
{
	if( now == 0 ) return 0;
	if( lx == l && rx == r ) 
	{
		if( flag == 0 ) return a[now].sum;
		else return a[now].maxn;
	}
	int m = ( l + r ) >> 1;
	if( lx > m ) return query(lx,rx,m+1,r,a[now].r,flag);
	else if( rx <= m ) return query(lx,rx,l,m,a[now].l,flag);
	else
	{
		int t1 = query(lx,m,l,m,a[now].l,flag),t2 = query(m+1,rx,m+1,r,a[now].r,flag);
		if( flag == 0 ) return t1 + t2;
		else return max(t1,t2);
	}
}

int fa[maxn],son[maxn],dep[maxn],siz[maxn],top[maxn],dfn[maxn];
int cnt = 0; 

void dfs1(int x,int fath)  
{
	fa[x] = fath;
	dep[x] = dep[fath] + 1;
	siz[x] = 1;
	int maxtmp = 0;
	for (int i = 0; i < g[x].size(); i++)
	{
		int t = g[x][i];
		if( t == fath ) continue;
		dfs1(t,x);
		siz[x] += siz[t];
		if( maxtmp < siz[t] )
		{
			son[x] = t;
			maxtmp = siz[t];		
		} 
	}
}

void dfs2(int x,int z)  
{
	dfn[x] = ++cnt,top[x] = z;    
	if( son[x] == 0 ) return; 
	dfs2(son[x],z); 
	for (int i = 0; i < g[x].size(); i++)
	{
		int t = g[x][i];
		if( t == son[x] || t == fa[x] ) continue;
		dfs2(t,t);  
	}
}

ll qchain(int x,int y,int flag) 
{
	ll ans = 0;
	int z = c[x];
	while( top[x] != top[y] )
	{
		if( dep[top[x]] < dep[top[y]] ) swap(x,y);
		ll t = query(dfn[top[x]],dfn[x],1,1e5,root[z],flag);
		if( flag == 0 ) ans += t;
		else ans = max(ans,t);
		x = fa[top[x]];
	} 
	if( dep[x] < dep[y] ) swap(x,y);
	ll t = query(dfn[y],dfn[x],1,1e5,root[z],flag);
	if( flag == 0 ) ans += t;
	else ans = max(ans,t);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> c[i];
	}
	for (int i = 1; i < n; i++)
	{
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs1(1,1);
	dfs2(1,1);
	for (int i = 1; i <= n; i++) insert(1,1e5,root[c[i]],root[c[i]],dfn[i],w[i]);
	for (int i = 1; i <= m; i++)
	{
		string kind;
		int x,y;
		cin >> kind >> x >> y;
		if( kind == "CC" )
		{
			insert(1,1e5,root[c[x]],root[c[x]],dfn[x],0);
			c[x] = y;
			insert(1,1e5,root[c[x]],root[c[x]],dfn[x],w[x]);
		}else if( kind == "CW" )
		{
			insert(1,1e5,root[c[x]],root[c[x]],dfn[x],0);
			w[x] = y;
			insert(1,1e5,root[c[x]],root[c[x]],dfn[x],w[x]);
		}else if( kind == "QS" ) cout << qchain(x,y,0) << '\n';
		else cout << qchain(x,y,1) << '\n';
	}
	return 0;
}
