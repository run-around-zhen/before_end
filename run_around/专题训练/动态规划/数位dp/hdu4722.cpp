#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

ll dp[20][15];
vector<int> num;

ll dfs(int pos,int sta,int flag,int lead)
{
	if( pos < 0 ) 
	{
		if( sta == 0 ) return 1;
		return 0;
	}
	if( !flag && !lead && dp[pos][sta] != -1 ) return dp[pos][sta];
	int max_num;
	if( !flag ) max_num = 9;
	else max_num = num[pos];
	ll res = 0;
	for (int i = 0; i <= max_num; i++)
	{
		if( lead && i == 0 ) res += dfs(pos-1,sta,flag&&(i==max_num),lead&&(i==0));
		else
		{
			res += dfs(pos-1,(sta+i)%10,flag&&(i==max_num),lead&&(i==0));
		}
	}
	if( !flag && !lead ) dp[pos][sta] = res;
	return res;
}

ll solve(ll x)
{
	if( x < 0 ) return 0;
	num.clear();
	while( x )
	{
		num.push_back(x%10);
		x /= 10;
	}
	return dfs(num.size()-1,0,1,1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	memset(dp,-1,sizeof(dp));
	int cnt = 0;
	while( t-- )
	{
		cnt ++;
		ll a,b;
		cin >> a >> b;
		cout << "Case #" << cnt << ": " << solve(b) - solve(a-1) << '\n';
	}
	return 0;
}

