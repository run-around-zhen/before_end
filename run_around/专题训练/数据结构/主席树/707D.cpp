#include <cstdio>
#include <bitset>
using namespace std;

const int maxn = 1e3 + 10;

struct node{
	int l,r;
	int sum;
	int state;
	bitset<maxn> s;
}hjt[100005*20];

int root[100005],cnt;
int m;

void insert(int l,int r,int pre,int &now,int p,int kind,int index)
{
	now = ++cnt;
	hjt[now] = hjt[pre];
	if( l == r )
	{	
		if( kind == 3 )
		{
			hjt[now].state ^= 1;
			hjt[now].sum = m - hjt[now].sum;
		}else
		{
			if( kind == 1 )
			{
				if( (hjt[now].s[index]^hjt[now].state) == 0 )
				{
					int x = 1;
					int z = hjt[now].s[index]^x;
					hjt[now].s[index]=z;
					hjt[now].sum ++;
				}
			}else
			{
				if( hjt[now].s[index]^hjt[now].state == 1 )
				{
					int x = 1;
					int z = hjt[now].s[index]^x;
					hjt[now].s[index]=z;
					hjt[now].sum --;
				}
			}
		}
		return;
	} 
	int mid = ( l + r ) >> 1;
	if( p <= mid ) insert(l,mid,hjt[pre].l,hjt[now].l,p,kind,index);
	else insert(mid+1,r,hjt[pre].r,hjt[now].r,p,kind,index);
	hjt[now].sum = hjt[hjt[now].l].sum + hjt[hjt[now].r].sum;
}

int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/
	int n,q;
	scanf("%d%d%d",&n,&m,&q);
	//cin >> n >> m >> q;
	//build(1,n,root[0]);
	for (int i = 1; i <= q; i++)
	{
		int kind;
		//cin >> kind;
		scanf("%d",&kind);
		if( kind == 3 )
		{
			int x;
			//cin >> x;
			scanf("%d",&x);
			insert(1,n,root[i-1],root[i],x,kind,0);
		}else if( kind == 4 )
		{
			int x;
			scanf("%d",&x);
			root[i] = root[x];
		}else
		{
			int p,index;
			scanf("%d%d",&p,&index);
			insert(1,n,root[i-1],root[i],p,kind,index);
		}
		printf("%d\n",hjt[root[i]].sum);
		//cout << hjt[root[i]].sum << '\n';
	}
	return 0;
}

