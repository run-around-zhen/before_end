#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e4 + 5;

struct node{
	int l,r;
	int sum;
}hjt[maxn*1000];

int root[maxn],a[maxn],cnt;
int n;

void insert(int l,int r,int pre,int &now,int p,int v)
{
	now = ++cnt;
	hjt[now] = hjt[pre];
	hjt[now].sum += v;
	if( l == r ) return;
	int m = ( l + r ) >> 1;
	if( p <= m ) insert(l,m,hjt[pre].l,hjt[now].l,p,v);
	else insert(m+1,r,hjt[pre].r,hjt[now].r,p,v);  
}

int lowbit(int x)
{
	return x & -x;
}

void update(int x,int pos,int v)
{
	for (int i = x; i <= n; i += lowbit(i))
	{
		insert(0,1e9,root[i],root[i],pos,v);
	}
}

vector<int> id[2];

int cal(int index,int flag)
{
	int res = 0;
	for (int i = 0; i < id[index].size(); i++)
	{
		if( flag == 0 ) res += hjt[hjt[id[index][i]].l].sum;
		else res += hjt[hjt[id[index][i]].r].sum;
	}
	return res;
}

int query(int l,int r,int k)   //��ǰ����Ϊ[l,r],Ҫ��ѯ����������Ҷ˵�ΪL��R,��ѯ��kС 
{
	if( l == r ) return l;   //�����������,ֻʣһ������
	int m = (l + r) >> 1;
	int tmp = cal(0,0) - cal(1,0);  //������������Ԫ�ظ���
	//cout << hjt[R].l << ' ' << queryx(rx,hjt[R].l) << '\n';
	//cout << tmp << '\n';
	if( k <= tmp ) 
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < id[i].size(); j++) id[i][j] = hjt[id[i][j]].l;
		}
		return query(l,m,k);
	}
	else 
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < id[i].size(); j++) id[i][j] = hjt[id[i][j]].r;
		}
		return query(m+1,r,k-tmp); 
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		update(i,a[i],1);
	}
	//cout << queryx(5,root[5]) << '\n'; 
	for (int i = 1; i <= m; i++)
	{
		char op;
		cin >> op;
		if( op == 'Q' )
		{
			int l,r,k;
			cin >> l >> r >> k;
			id[0].clear();
			id[1].clear();
			for (int j = r; j > 0; j-=lowbit(j) ) id[0].push_back(root[j]);
			for (int j = l-1; j > 0; j -= lowbit(j) ) id[1].push_back(root[j]);
			cout << query(0,1e9,k) << '\n';
		}else
		{
			int x,y;
			cin >> x >> y;
			update(x,a[x],-1);
			update(x,y,1);
			a[x] = y;
		}
	}
	return 0;
}
