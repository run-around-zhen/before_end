#include <iostream>
#include <cstring>
#include <vector> 
using namespace std;

typedef long long ll;

ll dp[20][15][2];
vector<int> num;

ll dfs(int pos,int pre,int x,int flag,int lead)
{
	if( pos < 0 ) return x == 1;
	if( !flag && !lead && dp[pos][pre][x] != -1 ) return dp[pos][pre][x];
	ll max_num,res = 0;
	if( !flag ) max_num = 9;
	else max_num = num[pos];
	for (int i = 0; i <= max_num; i++)
	{
		if( lead && i == 0 ) res += dfs(pos-1,-1,0,flag&&(i==max_num),lead&&(i==0));
		else
		{
			if( i == 9 && pre == 4 ) res += dfs(pos-1,i,1,flag&&(i==max_num),lead&&(i==0));
			else res += dfs(pos-1,i,x,flag&&(i==max_num),lead&&(i==0));
		}
	}
	if( !flag && !lead ) dp[pos][pre][x] = res;
	return res;
} 

ll solve(ll x)
{
	num.clear();
	while( x )
	{
		num.push_back(x%10);
		x /= 10;
	}
	return dfs(num.size()-1,-1,0,1,1);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp,-1,sizeof(dp));
	int t;
	cin >> t;
	while( t-- )
	{
		ll n;
		cin >> n;
		cout << solve(n) << '\n';
	}
	return 0;
}

