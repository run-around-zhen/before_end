#include <iostream>
#include <map>
using namespace std; 

#define dd(x) cout << #x << " = " << x << '\n';

const int maxn = 1e5 + 10;

int id;
map<string,int> ma;

struct nodex{
	int l,r;
	int sum;
	node()
	{
		l = r = sum = 0;
	}
}hjt[maxn*80],t[maxn*40];

int root[maxn],rootx[maxn],cnt1,cnt2;

void insertx(int l,int r,int pre,int &now,int pos,int v)
{
	now = ++cnt2;
	t[now] = t[pre];
	if( l == r ) 
	{
		t[now].sum = v;
		return;
	}
	int m = ( l + r ) >> 1;
	if( pos <= m ) insertx(l,m,t[pre].l,t[now].l,pos,v);
	else insertx(m+1,r,t[pre].r,t[now].r,pos,v);
}

int queryx(int l,int r,int now,int pos)
{
	if( l == r ) 
	{
		if( pos < l ) return 0;
		else return t[now].sum;
 	}
	int m = ( l + r ) >> 1;
	if( pos <= m ) return queryx(l,m,t[now].l,pos);
	else return queryx(m+1,r,t[now].r,pos); 
}

void insert(int l,int r,int pre,int &now,int pos,int v)
{
	now = ++cnt1;
	hjt[now] = hjt[pre];
	hjt[now].sum += v;
	if( l == r ) return;
	int m = ( l + r ) >> 1;
	if( pos <= m ) insert(l,m,hjt[pre].l,hjt[now].l,pos,v);
	else insert(m+1,r,hjt[pre].r,hjt[now].r,pos,v);
}

int query(int l,int r,int now,int pos)
{
	if( l == r ) 
	{
		if( pos < l ) return 0;
		return hjt[now].sum;
	}
	int m = ( l + r ) >> 1;
	if( pos <= m ) return query(l,m,hjt[now].l,pos);
	else return hjt[hjt[now].l].sum + query(m+1,r,hjt[now].r,pos);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int top = 1e9+1;
	for (int i = 1; i <= n; i++)
	{
		string kind,a; 
		cin >> kind;
		if( kind == "set" )
		{
			string a;
			int p;
			cin >> a >> p;
			int pri = queryx(1,n,rootx[i-1],ma[a]);
			if( ma[a] == 0 || pri == 0 )
			{
				if( ma[a] == 0 ) ma[a] = ++id;
				insertx(1,n,rootx[i-1],rootx[i],ma[a],p);
				insert(1,top,root[i-1],root[i],p,1);
			}else
			{
				int pri = queryx(1,n,rootx[i-1],ma[a]);
				insert(1,top,root[i-1],root[i],pri,-1);
				insertx(1,n,rootx[i-1],rootx[i],ma[a],p);
				insert(1,top,root[i],root[i],p,1);
			}
		}else if( kind == "remove" )
		{
			string a;
			cin >> a;
			int pri = queryx(1,n,rootx[i-1],ma[a]);
			if( ma[a] == 0 || pri == 0 ) 
			{
				root[i] = root[i-1];
				rootx[i] = rootx[i-1];
				continue;
			}
			insertx(1,n,rootx[i-1],rootx[i],ma[a],0);
			insert(1,top,root[i-1],root[i],pri,-1);
		}else if( kind == "query" )
		{
			string a;
			cin >> a;
			rootx[i] = rootx[i-1];
			root[i] = root[i-1];
			int pri = queryx(1,n,rootx[i],ma[a]);
			//dd(ma[q[i].a]);
			//dd(pri);
			if( ma[a] == 0 || pri == 0 ) cout << -1 <<'\n';
			else cout << query(1,top,root[i],pri-1) << '\n';
			cout << flush;
		}else 
		{
			int x;
			cin >> x;
			rootx[i] = rootx[i-x-1];
			root[i] = root[i-x-1];
		}
	} 
	return 0;
}
