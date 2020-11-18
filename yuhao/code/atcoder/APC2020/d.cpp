#include <iostream>
using namespace std;

typedef long long ll;

ll a[100005],b[100005];
ll siz[100005],sum[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		cin >> a[i];
		if( i != 0 ) sum[i] = sum[i-1] + a[i];
	}
	ll sumx = 0;
	b[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if(b[i - 1] > 1e17) b[i] = 1e17;
		b[i] = b[i - 1] * 2;
		cout << b[i] <<" ";
	}
	for (int i = n; i >= 0; i --)
	{
		if( a[i] + sumx > b[i] ) 
		{
			cout << "-1" << endl;
			return 0;
		}
		sumx = (sumx + a[i] + 1) / 2;
	}
	if( a[0] != 0 )
	{
		cout << -1 << '\n';
		return 0;
	}
	ll ans = 1;
	ll temp = 0;
	siz[0] = 2;
	int index = 0;
	ll help = 0;
	for (int i = 1; i <= n; )
	{
		if( a[i] == 0 )
		{
			i ++;
			continue;
		}
		if( index >= i )
		{
			cout << -1 << '\n';
			return 0;
		}
		ll t = min(a[i],siz[index]);
		ans += t * (i - index);
		help += t;
		a[i] -= t;
		siz[index] -= t;
		if( siz[index] == 0 )
		{
			index ++;
			siz[index] = help - sum[index];
		}
		if( a[i] == 0 ) i++;
	}
	cout << ans << '\n';
	return 0;
}