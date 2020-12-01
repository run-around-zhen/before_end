#include <iostream>
#include <vector>
#include <cstring> 
using namespace std;

typedef long long ll;

ll dp[20][15][10][2];
vector<int> num;

ll dfs(int pos,int sta,int pre,int x,int flag,int lead)
{
	if( pos < 0 ) return sta==0&&x==1;
	if( !flag && !lead && dp[pos][sta][pre][x] != -1 ) return dp[pos][sta][pre][x];
	ll max_num,res = 0;
	if( !flag ) max_num = 9;
	else max_num = num[pos];
	for (int i = 0; i <= max_num; i++)
	{
		if( lead && i == 0 ) res += dfs(pos-1,sta,pre,x,flag&&(i==max_num),lead&&(i==0));
		else
		{
			if( i == 3 && pre == 1 ) res += dfs(pos-1,(sta*10+i)%13,i,1,flag&&(i==max_num),lead&&(i==0));
			else res += dfs(pos-1,(sta*10+i)%13,i,x,flag&&(i==max_num),lead&&(i==0));
		}
	} 
	if( !lead && !flag ) dp[pos][sta][pre][x] = res;
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
	return dfs(num.size()-1,0,-1,0,1,1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp,-1,sizeof(dp));
	ll n;
	while( cin >> n )
	{
		cout << solve(n) << '\n';
	} 
	return 0;
}

