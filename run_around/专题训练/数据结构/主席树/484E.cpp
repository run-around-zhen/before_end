#include <iostream>
#include <algorithm>
using namespace std;

#define dd(x) cout << #x << ' ' << x << '\n'; 

const int maxn = 1e5 + 10;

struct node{
	int id,v;
	bool operator<(const node&n)const
	{
		return v > n.v;
	}
}a[maxn];

struct nodex{
	int l,r;
	int pre,end,sum;
}hjt[maxn*40];

int root[maxn],cnt;

void update(int x,int len)
{
	int l = hjt[x].l,r = hjt[x].r;
	int len1 = (len + 1) / 2,len2 = len - len1;
	if( hjt[l].pre == len1 ) hjt[x].pre = hjt[l].pre + hjt[r].pre;
	else hjt[x].pre = hjt[l].pre;
	if( hjt[r].end == len2 ) hjt[x].end = hjt[r].end + hjt[l].end;
	else hjt[x].end = hjt[r].end;
	hjt[x].sum = max(max(hjt[l].sum,hjt[r].sum),hjt[l].end+hjt[r].pre); 
}

void insert(int l,int r,int pre,int &now,int p)
{
	now = ++cnt;
	hjt[now] = hjt[pre];
	if( l == r )
	{
		hjt[now].pre = hjt[now].end = hjt[now].sum = 1;
		return;
	}
	int mid = (l+r) >> 1;
	if( p <= mid ) insert(l,mid,hjt[pre].l,hjt[now].l,p);
	else insert(mid+1,r,hjt[pre].r,hjt[now].r,p); 
	update(now,r-l+1);
}

int query(int lx,int rx,int l,int r,int now)
{
	//dd(l);dd(r);
	//dd(lx);dd(rx);
	//return 0;
	if( lx == l && rx == r ) return hjt[now].sum;
	int mid = ( l + r ) >> 1;
	if( rx <= mid ) return query(lx,rx,l,mid,hjt[now].l);
	else if( lx > mid ) return query(lx,rx,mid+1,r,hjt[now].r);
	else
	{
		int res = max(query(lx,mid,l,mid,hjt[now].l),query(mid+1,rx,mid+1,r,hjt[now].r));
		res = max(res,min(hjt[hjt[now].l].end,mid-lx+1)+min(hjt[hjt[now].r].pre,rx-mid));
		return res;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].v;
		a[i].id = i;
	}
	sort(a+1,a+1+n);
	for (int i = 1; i <= n; i++)
	{
		insert(1,n,root[i-1],root[i],a[i].id);
	}
	//query(2,5,1,n,root[n]);
	int q;
	cin >> q;
	while( q-- )
	{
		int lx,rx,w;
		int ans = 0;
		cin >> lx >> rx >> w;
		int l = 1,r = n;
		while( l <= r )
		{
			int mid = (l + r) >> 1;
			int tmp = query(lx,rx,1,n,root[mid]);
			//dd(tmp);
			if( tmp >= w )
			{
				ans = a[mid].v;
				r = mid - 1;
			}else l = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}

