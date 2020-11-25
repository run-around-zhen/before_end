#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int maxn = 5e4 + 5;

struct Matrix{
	ll data[4][4];
	Matrix operator*(const Matrix&n)const
	{
		Matrix tmp;
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++) tmp.data[i][j] = -1e18;
		for (int i = 1; i <= 3; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				for (int k = 1; k <= 3; k++)
					tmp.data[i][j] = max(tmp.data[i][j],data[i][k]+n.data[k][j]);
			}
		}
		return tmp;
	}
};

struct node{
	int l,r;
	Matrix m;
}a[maxn*4]; 

int p[maxn];

void update(int x)
{
	a[x].m = a[2*x].m * a[2*x+1].m;
}

void build(int x,int l,int r)
{
	a[x].l = l,a[x].r = r;
	if( l == r )
	{
		a[x].m.data[1][1] = a[x].m.data[1][3] = a[x].m.data[2][1] = a[x].m.data[2][3] = p[l];
		a[x].m.data[1][2] = a[x].m.data[3][2] = a[x].m.data[3][1] = -1e18;
		a[x].m.data[2][2] = a[x].m.data[3][3] = 0;
		return;
	}
	int m = (l+r) >> 1;
	build(2*x,l,m),build(2*x+1,m+1,r);
	update(x);
}

void modify(int x,int p,int v)
{
	if( a[x].l == a[x].r )
	{
		a[x].m.data[1][1] = a[x].m.data[1][3] = a[x].m.data[2][1] = a[x].m.data[2][3] = v;
		return;
	}
	int m = (a[x].l + a[x].r) >> 1;
	if( p <= m ) modify(2*x,p,v);
	else modify(2*x+1,p,v);
	update(x);
}

Matrix query(int x,int l,int r)
{
	if( a[x].l == l && a[x].r == r ) return a[x].m;
	int m = (a[x].l+a[x].r) >> 1; 
	if( l > m ) return query(2*x+1,l,r);
	else if( r <= m ) return query(2*x,l,r);
	else return query(2*x,l,m) * query(2*x+1,m+1,r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	build(1,1,n);
	int q;
	cin >> q;
	while( q-- )
	{
		int op,x,y;
		cin >> op >> x >> y;
		if( op == 1 )
		{
			Matrix ans; 
			if( x > y ) swap(x,y);
			ans = query(1,x,y);
			cout << ans.data[2][3] << '\n';
		}else modify(1,x,y); 
	}
	return 0;
}

