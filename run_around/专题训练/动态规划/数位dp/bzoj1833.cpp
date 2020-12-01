#include <iostream>
#include <vector> 
#include <cstring>
using namespace std;

typedef long long ll;

ll dp[15][10][15],ans[10];
vector<int> num; 

ll dfs(int pos,int numx,int p1,int flag,int lead)
{
	ll max_num;
	if( pos < 0 ) 
	{
		if( lead && numx == 0 ) return 1;
		return p1;
	}
	if( !flag && !lead && dp[pos][numx][p1] != -1 ) 
	{
		//cout << pos << ' ' << numx << ' ' << p1 << ' ' << dp[pos][numx][p1] << '\n';
		return dp[pos][numx][p1];
	}
	if( !flag ) max_num = 9;
	else max_num = num[pos];
	ll res = 0;
	for (int i = 0; i <= max_num; i++)
	{
		if( lead && i == 0 ) res += dfs(pos-1,numx,p1,flag&&(i==max_num),lead&&(i==0));
		else
		{
			if( i == numx ) res += dfs(pos-1,numx,p1+1,flag&&(i==max_num),lead&&(i==0));
			else res += dfs(pos-1,numx,p1,flag&&(i==max_num),lead&&(i==0));
		}
	}
	if( !flag && !lead ) dp[pos][numx][p1] = res;
	//cout << pos << ' ' << res << '\n';
	return res;
}

ll slove(ll x,ll p)
{
	if( x < 0 ) return 0;
	num.clear();
	while( x )
	{
		num.push_back(x%10);
		x /= 10;
	}
	return dfs(num.size()-1,p,0,1,1);
}

int main()
{
	memset(dp,-1,sizeof(dp));
	ll a,b;
	cin >> a >> b;
	//cout << slove(b,0) << '\n';// << ' ' << slove(a,0) << '\n';
	for (int i = 0; i < 10; i++)
	{
		ans[i] = slove(b,i) - slove(a-1,i);
		cout << ans[i];
		if( i == 9 ) cout << '\n';
		else cout << ' ';
	}
	return 0;
}

