#include <iostream>
#include <vector>
using namespace std;
#define dd(x) cout << #x << '=' << x << '\n';
typedef long long ll;
const int maxn = 2e5 + 5;

struct Matrix{
	ll d[3][3];
	Matrix operator*(const Matrix&n)const
	{
		Matrix tmp;
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= 2; j++) tmp.d[i][j] = 1e18;
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= 2; j++)
				for (int k = 1; k <= 2; k++)
					tmp.d[i][j] = min(tmp.d[i][j],d[i][k]+n.d[k][j]);
		return tmp;
	}
}; 

ll w1[maxn],w2[maxn];

struct node{
	int l,r;
	Matrix m;
}a[maxn*4];

void update(int x)
{
	a[x].m = a[2*x].m * a[2*x+1].m;
}

void build(int x,int l,int r)
{
	a[x].l = l,a[x].r = r;
	if( l == r )
	{
		a[x].m.d[1][1] = w1[l],a[x].m.d[1][2] = w2[l];
		a[x].m.d[2][1] = 1e18,a[x].m.d[2][2] = 0;
		return;
	}
	int m = (l+r)>>1;
	build(2*x,l,m),build(2*x+1,m+1,r);
	update(x);
}

void modify(int x,int p,ll v1,ll v2)
{
	if( a[x].l == a[x].r )
	{
		a[x].m.d[1][1] = v1,a[x].m.d[1][2] = v2;
		return;
	}
	int m = (a[x].l+a[x].r)>>1;
	if( p <= m ) modify(2*x,p,v1,v2);
	else modify(2*x+1,p,v1,v2);
	update(x);
}

Matrix query(int x,int l,int r)
{
	if( a[x].l == l && a[x].r == r ) return a[x].m;
	int m = (a[x].l+a[x].r)>>1;
	if( l > m ) return query(2*x+1,l,r);
	else if( r <= m ) return query(2*x,l,r);
	else return query(2*x,l,m) * query(2*x+1,m+1,r); 
}

vector<int> g[maxn];
int fa[maxn],son[maxn],dep[maxn],siz[maxn],top[maxn],dfn[maxn],butt[maxn];
ll v1[maxn],v2[maxn],cnt;
ll dp[maxn];

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
	top[x] = z;
	w2[dfn[x]] = v2[x];
	if( son[x] == 0 ) 
	{
		butt[x] = x;
		w1[dfn[x]] = 0;
		dp[x] = v2[x];
		return;
	}
	ll tmp = 0;
 	dfs2(son[x],z);
 	butt[x] = butt[son[x]];
 	tmp += dp[son[x]];
	for (int i = 0; i < g[x].size(); i++)
 	{
 		int t = g[x][i];
 		if( t == son[x] || t == fa[x] ) continue;
 		dfs2(t,t);
		tmp += dp[t];
		w1[dfn[x]] += dp[t];
	}
	dp[x] = min(v2[x],tmp);
}

void mchain(int x,ll v)
{
	w2[dfn[x]] += v;
	modify(1,dfn[x],w1[dfn[x]],w2[dfn[x]]);
	while( top[x] != 1 )
	{
		int z = fa[top[x]];
		Matrix tmp = query(1,dfn[top[x]],dfn[butt[x]]);
		ll newx = tmp.d[1][2];
		w1[dfn[z]] += newx - dp[top[x]];
		dp[top[x]] = newx;
		modify(1,dfn[z],w1[dfn[z]],w2[dfn[z]]);
		x = z;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> v2[i];
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
	int q;
	cin >> q;
	while( q-- )
	{
		char op;
		cin >> op;
		if( op == 'Q' )
		{
			int x;
			cin >> x;
			Matrix ans;
			ans = query(1,dfn[x],dfn[butt[x]]);
			cout << ans.d[1][2] << '\n';
		}else
		{
			int x;
			ll y;
			cin >> x >> y;
			mchain(x,y);
		}
	}
	return 0;
}

/*
4
4 3 2 1
1 2
1 3
4 2
1
Q 1
*/
