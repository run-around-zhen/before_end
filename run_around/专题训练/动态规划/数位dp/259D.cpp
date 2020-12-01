#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

ll dp[15][15];
ll ans[15];
ll mod = 1e9 + 7;
vector<int> num;

ll dfs(int pos,int cnt,int flag,int lead)
{
	if( cnt < 0 ) return 0;
	int max_num;
	if( pos == -1 ) 
	{
		if( lead ) return 0;
		if( cnt == 0 ) return 1;
		else return 0;
	}
	if( !flag && !lead && dp[pos][cnt] != -1 ) return dp[pos][cnt];
	if( flag ) max_num = num[pos];
	else max_num = 9;
	ll res = 0;
	for (int i = 0; i <= max_num; i++)
	{
		if( i == 4 || i == 7 ) res += dfs(pos-1,cnt-1,flag&&(i==max_num),lead&&(i==0));
		else res += dfs(pos-1,cnt,flag&&(i==max_num),lead&&(i==0));
	}
	if( !flag && !lead ) dp[pos][cnt] = res;
	return res;
}

ll slove(int x,int cnt)
{
	num.clear();
	while( x )
	{
		num.push_back(x%10);
		x /= 10;
	}
	return dfs(num.size()-1,cnt,1,1);
}

ll dfsx(int rest,int pos)
{
	ll res = 0;
	if( pos == 7 ) return 1;
	for (int i = 0; i < rest; i++)
	{
		ans[i] --;
		res = res + (ans[i]+1) * dfsx(rest-i,pos+1) % mod;
		ans[i] ++;
		res %= mod;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp,-1,sizeof(dp));
	int m;
	cin >> m;
	for (int i = 0; i <= 10; i++)
	{
		ans[i] = slove(m,i);
	}
	ll res = 0;
	for (int i = 1; i <= 10; i++)
	{
		res += ans[i] * dfsx(i,1) % mod; 
		res %= mod;
	}
	cout << res << '\n';
	return 0;
}
