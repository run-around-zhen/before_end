#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 5e5 + 5;

vector<int> g[maxn];
int fa[maxn],son[maxn],dep[maxn],siz[maxn],top[maxn],dfn[maxn];
int cnt = 0;
int p = 201314;

struct node{
	int l,r;
	ll sum,lazy;
}a[maxn*4];

void update(int x) 
{
	a[x].sum = a[2*x].sum + a[2*x+1].sum;
}

void pushdown(int x)
{
	int t = a[x].lazy;
	a[x].lazy = 0;
	a[2*x].lazy += t;
	a[2*x].sum += (a[2*x].r-a[2*x].l+1) * t;
	a[2*x+1].lazy += t;
	a[2*x+1].sum += (a[2*x+1].r-a[2*x+1].l+1) * t; 
}

void build(int x,int l,int r)
{
	a[x].l = l,a[x].r = r;
	a[x].lazy = 0;
	if( a[x].l == a[x].r )
	{
		a[x].sum = 0;
		return;
	}
	int m = (l + r) >> 1;
	build(2*x,l,m),build(2*x+1,m+1,r);
	update(x);
}

void modify(int x,int l,int r,ll v)
{
	if( a[x].l == l && a[x].r == r )
	{
		a[x].lazy += v;
		a[x].sum += (r - l + 1) * v;
		return;
	}
	if( a[x].lazy ) pushdown(x);
	int m = (a[x].l+a[x].r)>>1;
	if( r <= m ) modify(2*x,l,r,v);
	else if( l > m ) modify(2*x+1,l,r,v);
	else
	{
		modify(2*x,l,m,v);
		modify(2*x+1,m+1,r,v);
	}
	update(x);
}

ll query(int x,int l,int r)
{
	if( a[x].l == l && a[x].r == r ) return a[x].sum;
	if( a[x].lazy ) pushdown(x);
	int m = (a[x].l+a[x].r)>>1;
	if( r <= m ) return query(2*x,l,r)%p;
	else if( l > m ) return query(2*x+1,l,r)%p;
	else return (query(2*x,l,m)+query(2*x+1,m+1,r))%p;
}

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
	dfn[x] = ++cnt;
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
	z %= p;
	while( top[x] != top[y] )
	{
		if( dep[top[x]] < dep[top[y]] ) swap(x,y);
		modify(1,dfn[top[x]],dfn[x],z);
		x = fa[top[x]];
	}
	if( dep[x] < dep[y] ) swap(x,y);
	modify(1,dfn[y],dfn[x],z);
}

ll qchain(int x,int y)
{
	ll ans = 0;
	while( top[x] != top[y] )
	{
		if( dep[top[x]] < dep[top[y]] ) swap(x,y);
		ans += query(1,dfn[top[x]],dfn[x]);
		ans %= p;
		x = fa[top[x]];
	}
	if( dep[x] < dep[y] ) swap(x,y);
	ans += query(1,dfn[y],dfn[x]);
	return ans % p;
}

struct query{
	int id,v,w;
	bool operator<(const query&n)const
	{
		return v < n.v;
	}
}qx[maxn*2];

ll ans[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin >> n >> q;
	for (int i = 1; i < n; i++)
	{
		int x;
		cin >> x;
		g[x].push_back(i);
	} 
	build(1,1,n);
	dfs1(0,0);
	dfs2(0,0);
	for (int i = 1; i <= q; i++)
	{
		int l,r,w;
		cin >> l >> r >> w;
		qx[i].v = l-1,qx[i].id = i,qx[i].w = w;
		qx[i+q].v = r,qx[i+q].id = i+q,qx[i+q].w = w;
	}
	sort(qx+1,qx+1+q+q);
	int index = 1;
	while( qx[index].v < 0 ) index ++;
	for (int i = 0; i < n; i++)
	{
		mchain(i,0,1);
		while( index <= 2*q && qx[index].v == i )
		{
			if( qx[index].id > q ) ans[qx[index].id-q] += qchain(qx[index].w,0);
			else ans[qx[index].id] -= qchain(qx[index].w,0);
			index ++;
		}
	}
	for (int i = 1; i <= q; i++) cout << (ans[i]%p+p)%p << '\n';
	return 0;
}

