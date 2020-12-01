#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

ll dp[15][11][11][2][2][2];
vector<int> num;

ll dfs(int pos,int pre1,int pre2,int x1,int x2,int x3,int flag,int lead)
{
	if( pos < 0 ) 
	{
		if( x3 ) return 1;
		else return 0;
	}
	ll max_num;
	if( !flag && !lead && dp[pos][pre1][pre2][x1][x2][x3] != -1 ) return dp[pos][pre1][pre2][x1][x2][x3];
	if( !flag ) max_num = 9;
	else max_num = num[pos];
	ll res = 0;
	for (int i = 0; i <= max_num; i++)
	{
		if( lead && i == 0 ) res += dfs(pos-1,pre1,pre2,x1,x2,x3,flag&&(i==max_num),lead&&(i==0));
		else
		{
			if( x1 == 1 && i == 8 ) continue;
			if( x2 == 1 && i == 4 ) continue;
			if( pre1 == pre2 && i == pre1 )
				res += dfs(pos-1,pre2,i,x1|(i==4),x2|(i==8),1,flag&&(i==max_num),lead&&(i==0));
			else res += dfs(pos-1,pre2,i,x1|(i==4),x2|(i==8),x3,flag&&(i==max_num),lead&&(i==0));
		}
	}
	if( !flag && !lead ) dp[pos][pre1][pre2][x1][x2][x3] = res;
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
	return dfs(num.size()-1,10,10,0,0,0,1,1); 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp,-1,sizeof(dp));
	ll a,b;
	cin >> a >> b;
	cout << solve(b) - solve(a-1) << '\n';
	return 0;
}

