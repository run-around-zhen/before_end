#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

ll dp[20][2550][100];
vector<int> num,s;
int mod = 2520;

int gcd(int a,int b)
{
	if( b == 0 ) return a;
	return gcd(b,a%b);
}

ll dfs(int pos,int p1,int p2,int flag,int lead)
{
	int max_num;
	if( pos == -1 ) 
	{
		if( p1 % s[p2] == 0 ) return 1;
		else return 0;
	}
	if( !flag && dp[pos][p1][p2] != -1 ) return dp[pos][p1][p2];
	if( flag ) max_num = num[pos];
	else max_num = 9;
	ll res = 0;
	for (int i = 0; i <= max_num; i++)
	{
		if( i == 0 ) res += dfs(pos-1,(p1*10+i)%mod,p2,flag&&(i==max_num),lead&&(i==0));
		else 
		{
			int z = s[p2];
			int r = z * i / gcd(z,i);
			res += dfs(pos-1,(p1*10+i)%mod,lower_bound(s.begin(),s.end(),r)-s.begin(),flag&&(i==max_num),lead&&(i==0));
		}
	}
	if( !flag && !lead ) dp[pos][p1][p2] = res;
	return res;
}

ll slove(ll x)
{
	num.clear();
	while( x )
	{
		num.push_back(x%10);
		x /= 10;
	}
	return dfs(num.size()-1,0,0,1,1); 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1; i <= 2520; i++)
	{
		if( 2520 % i == 0 ) s.push_back(i);
	}
	int t;
	cin >> t;
	memset(dp,-1,sizeof(dp));
	while( t-- )
	{
		ll l,r;
		cin >> l >> r;
		cout << slove(r) - slove(l-1) << '\n';
	}
	return 0;
}
