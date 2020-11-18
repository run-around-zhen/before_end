#include <iostream>
using namespace std;

const int maxn = 1e5+5; 

struct node{
	int l,r,sum;
}hjt[maxn*40];

int a[maxn],root[maxn],cnt;
int last[maxn];

void insert(int l,int r,int pre,int &now,int p,int v)  
{
	hjt[++cnt] = hjt[pre];          
	now = cnt;
	hjt[now].sum = hjt[pre].sum + v;    
	if( l == r ) return;
	int m = ( l + r ) >> 1;
	if( p <= m ) insert(l,m,hjt[pre].l,hjt[now].l,p,v); 
	else insert(m+1,r,hjt[pre].r,hjt[now].r,p,v); 
} 

int query(int now,int l,int r,int k)
{
	if( l == r )
	{
		if( k < hjt[now].sum ) return l - 1;
		return l; 
	}
	int mid = (l + r) >> 1;
	int tmp = hjt[hjt[now].l].sum;
	if( tmp > k ) return query(hjt[now].l,l,mid,k);
	else return query(hjt[now].r,mid+1,r,k-tmp);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--)
	{
		if( last[a[i]] ) 
		{
			insert(1,n,root[i+1],root[i],last[a[i]],-1);
			insert(1,n,root[i],root[i],i,1);
		}else insert(1,n,root[i+1],root[i],i,1);
		last[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int ans = 0,l = 1,r = 0;
		while( l <= n )
		{
			r = query(root[l],1,n,i);
			l = r + 1; 
			ans ++;
		}
		cout << ans;
		if( i == n ) cout << '\n';
		else cout << ' ';
	}
	return 0;
}

