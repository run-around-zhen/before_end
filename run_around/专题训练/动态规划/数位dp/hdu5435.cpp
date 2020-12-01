#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

ll dp[100005][20];
ll mod = 1e9 + 7;
vector<int> num;

ll dfs(int pos,int sta,int flag,int lead)
{
	if( pos < 0 ) return sta;
	if( !flag && !lead && dp[pos][sta] != -1 ) return dp[pos][sta];
	int max_num;
	if( !flag ) max_num = 9;
	else max_num = num[pos];
	ll res = 0;
	for (int i = 0; i <= max_num; i++)
	{
		res += dfs(pos-1,sta^i,flag&&(i==max_num),lead&&(i==0));
		res %= mod;
	}
	if( !flag && !lead ) dp[pos][sta] = res;
	return res;
}

ll cal(string a)
{
	int ans = 0;
	for (int i = 0; i < a.length(); i++)
	{
		ans = ans ^ (a[i]-'0');
	}
	return ans;
}

ll solve(string a)
{
	num.clear();
	for (int i = a.length()-1; i >= 0; i--) num.push_back(a[i]-'0');
	return dfs(num.size()-1,0,1,1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp,-1,sizeof(dp));
	int t;
	cin >> t;
	int cnt = 0;
	while( t-- )
	{
		cnt ++;
		string a,b;
		cin >> a >> b;
		cout << "Case #" << cnt << ": " << (((solve(b) - solve(a))%mod+mod)%mod + cal(a))%mod << '\n';
	}
	return 0;
}

