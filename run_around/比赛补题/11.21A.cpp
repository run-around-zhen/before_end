#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct node{
	ll sum;
	ll cnt;
	node(ll a=0,ll b=0) 
	{
		sum = a;
		cnt = b;
	}
}v1[maxn],v2[maxn];

ll a[maxn],b[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	int cas = 0;
	while( t-- )
	{
		cas ++;
		int n,m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= m; i++) cin >> b[i];
		int len1 = 0,len2 = 0;
		for (int i = 1; i <= n; i++)
		{
			node tmp = node(a[i],1);
			while( len1 && tmp.sum * v1[len1].cnt >= v1[len1].sum * tmp.cnt )
			{
				tmp.sum += v1[len1].sum;
				tmp.cnt += v1[len1].cnt; 
				len1 --;
			}
			v1[++len1] = tmp;
		}
		for (int i = 1; i <= m; i++)
		{
			node tmp = node(b[i],1);
			while( len2 && tmp.sum * v2[len2].cnt >= v2[len2].sum * tmp.cnt )
			{
				tmp.sum += v2[len2].sum;
				tmp.cnt += v2[len2].cnt; 
				len2 --;
			}
			v2[++len2] = tmp;
		}
		//cout << len1 << ' ' << len2 << '\n';
		int i = 1,j = 1;
		ll now = 1,pre1 = 1,pre2 = 1;
		ll ans = 0;
		while( i <= len1 || j <= len2 )
		{
			if( i > len1 ) 
			{
				for (int k = pre2; k < pre2 + v2[j].cnt; k++)
				{
					ans += now * b[k];
					now ++;
				}
				pre2 += v2[j].cnt;
				j ++;
			}else if( j > len2 )
			{
				for (int k = pre1; k < pre1 + v1[i].cnt; k++)
				{
					ans += now * a[k];
					now ++;
				}
				pre1 += v1[i].cnt;
				i ++;
			}else if( v1[i].sum * v2[j].cnt > v2[j].sum * v1[i].cnt )
			{
				for (int k = pre1; k < pre1 + v1[i].cnt; k++)
				{
					ans += now * a[k];
					now ++;
				}
				pre1 += v1[i].cnt;
				i ++;
			}else
			{
				for (int k = pre2; k < pre2 + v2[j].cnt; k++)
				{
					ans += now * b[k];
					now ++;
				}
				pre2 += v2[j].cnt;
				j ++;
			}
			//cout << ans << ' ' << i << ' ' << j << '\n';
		}
		cout << "Case " << cas << ": " << ans << '\n';
	}
	return 0;
}

