#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 10;

struct node{
	int l,r;
	int sum,pre,end;
	int lazy;
}a[maxn*4];

int v[maxn],w[maxn];
vector<int> g[maxn];

void update(int x)
{
	a[x].pre = a[2*x].pre,a[x].end = a[2*x+1].end;
	a[x].sum = a[2*x].sum + a[2*x+1].sum;
	if( a[2*x].end == a[2*x+1].pre ) a[x].sum --;
}

void pushdown(int x)
{
	int t = a[x].lazy;
	a[x].lazy = 0;
	a[2*x].lazy = t;
	a[2*x].pre = a[2*x].end = t;
	a[2*x].sum = 1;
	a[2*x+1].lazy = t;
	a[2*x+1].pre = a[2*x+1].end = t;
	a[2*x+1].sum = 1;
}

void build(int x,int l,int r)
{
	a[x].l = l,a[x].r = r;
	a[x].lazy = 0;
	if( l == r )
	{
		a[x].pre = a[x].end = w[l];
		a[x].sum = 1;
		return;
	}
	int m = (l + r) >> 1;
	build(2*x,l,m),build(2*x+1,m+1,r);
	update(x);
}

void modify(int x,int l,int r,int c)
{
	if( a[x].l == l && a[x].r == r )
	{
		a[x].pre = a[x].end = c;
		a[x].lazy = c;
		a[x].sum = 1;
		return;
	}
	if( a[x].lazy ) pushdown(x);
	int m = (a[x].l + a[x].r) >> 1; 
	if( r <= m ) modify(2*x,l,r,c);
	else if( l > m ) modify(2*x+1,l,r,c);
	else
	{
		modify(2*x,l,m,c);
		modify(2*x+1,m+1,r,c);
	}
	update(x);
}

int query(int x,int l,int r)
{
	if( a[x].l == l && a[x].r == r ) return a[x].sum;
	if( a[x].lazy ) pushdown(x);
	int m = (a[x].l+a[x].r) >> 1;
	if( l > m ) return query(2*x+1,l,r);
	else if( r <= m ) return query(2*x,l,r);
	else
	{
		int ans = query(2*x,l,m) + query(2*x+1,m+1,r);
		if( a[2*x].end == a[2*x+1].pre ) ans--;
		return ans;
	}
}

int findc(int x,int p)
{
	if( a[x].l == a[x].r ) return a[x].pre;
	if( a[x].lazy ) pushdown(x);
	int m = (a[x].l+a[x].r) >> 1;
	if( p <= m ) return findc(2*x,p);
	else return findc(2*x+1,p);
} 

int fa[maxn],son[maxn],dep[maxn],siz[maxn],top[maxn],dfn[maxn];
int cnt = 0;

void dfs1(int x,int fath)
{
	fa[x] = fath,dep[x] = dep[fath] + 1;
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
	dfn[x] = ++cnt;
	w[cnt] = v[x];
	top[x] = z;
	if( son[x] == 0 ) return;
	dfs2(son[x],z);
	for (int i = 0; i < g[x].size(); i++)
	{
		int t = g[x][i];
		if( t == son[x] || t == fa[x] ) continue;
		dfs2(t,t);
	}
}

void mchain(int x,int y,int z)
{
	while( top[x] != top[y] )
	{
		if( dep[top[x]] < dep[top[y]] ) swap(x,y);
		modify(1,dfn[top[x]],dfn[x],z);
		x = fa[top[x]];
	}
	if( dep[x] < dep[y] ) swap(x,y);
	modify(1,dfn[y],dfn[x],z);
}

int qchain(int x,int y)
{
	int ans = 0;
	int c = 0;
	while( top[x] != top[y] )
	{
		if( dep[top[x]] < dep[top[y]] ) swap(x,y);
		ans += query(1,dfn[top[x]],dfn[x]);
		if( findc(1,dfn[top[x]]) == findc(1,dfn[fa[top[x]]]) ) ans--;
		x = fa[top[x]];
	}
	if( dep[x] < dep[y] ) swap(x,y);
	ans += query(1,dfn[y],dfn[x]);
	if( findc(1,dfn[x]) == c ) ans--;
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
		cin >> v[i];
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
	build(1,1,n);
	for (int i = 1; i <= m; i++)
	{
		char k;
		cin >> k;
		if( k == 'Q' )
		{
			int x,y;
			cin >> x >> y;
			cout << qchain(x,y) << '\n';
		}else
		{
			int x,y,v;
			cin >> x >> y >> v;
			mchain(x,y,v);
		}
	}
	return 0;
}

/*
6 1
2 2 1 2 1 1
1 2
1 3
2 4
2 5
2 6
Q 3 5
*/

