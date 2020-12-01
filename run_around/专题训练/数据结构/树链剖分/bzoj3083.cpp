#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5; 

struct node{
	int l,r;
	ll lazy;
	ll minx;
}a[maxn*4]; 

vector<int> g[maxn];
int fa[maxn],son[maxn],dep[maxn],siz[maxn],w[maxn],top[maxn],dfn[maxn];
int v[maxn]; 
int cnt = 0; 

void update(int x)
{
	a[x].minx = min(a[2*x].minx,a[2*x+1].minx);
}

void pushdown(int x)
{
	ll t = a[x].lazy;
	a[x].lazy = 0;
	a[2*x].lazy = t;
	a[2*x].minx = t;
	a[2*x+1].lazy = t;
	a[2*x+1].minx = t;
}

void build(int x,int l,int r)
{
	a[x].l = l,a[x].r = r;
	if( l == r )
	{
		a[x].minx = w[l];
		return;
	}
	int m = (l+r)>>1;
	build(2*x,l,m),build(2*x+1,m+1,r);
	update(x);
}

void modify(int x,int l,int r,int v)
{
	if( a[x].l == l && a[x].r == r )
	{
		a[x].lazy = v;
		a[x].minx = v;
		return;
	}
	if( a[x].lazy ) pushdown(x);
	int m = ( a[x].l + a[x].r ) >> 1;
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
	if( l > r ) return 1e18;
	if( a[x].l == l && a[x].r == r ) return a[x].minx;
	if( a[x].lazy ) pushdown(x);
	int m = ( a[x].l + a[x].r ) >> 1;
	if( r <= m ) return query(2*x,l,r);
	else if( l > m ) return query(2*x+1,l,r);
	else return min(query(2*x,l,m),query(2*x+1,m+1,r)); 
}

void dfs1(int x,int fath)   //第一次dfs处理出大小,深度,父亲及重儿子 
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

void mchain(int x,int y,ll z) 
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) cin >> v[i];
	int root;
	cin >> root;
	dfs1(root,root);
	dfs2(root,root);
	build(1,1,n);
	for (int i = 1; i <= m; i++)
	{
		int op;
		cin >> op;
		if( op == 1 )
		{
			int id;
			cin >> id;
			root = id;
		}else if( op == 2 )
		{
			int x,y;
			ll v;
			cin >> x >> y >> v;
			mchain(x,y,v);
		}else
		{
			int id;
			cin >> id;
			if( dfn[root] > dfn[id] && dfn[root] < dfn[id]+siz[id] )
			{
				int z = root;
				while( dep[z] > dep[id] ) 
				{
					z = top[z];
					if( fa[z] == id ) break;
					z = fa[z];
				}
				if( dep[z] <= dep[id] ) z = son[id];
				cout << min(query(1,1,dfn[z]-1),query(1,dfn[z]+siz[z],n)) << '\n';
			}else if( id == root ) cout << query(1,1,n) << '\n';
			else cout << query(1,dfn[id],dfn[id]+siz[id]-1) << '\n';
		}
	}
	return 0;
}

