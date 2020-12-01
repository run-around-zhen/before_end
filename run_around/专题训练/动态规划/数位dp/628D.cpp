#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;
ll m,d;
vector<int> num;
ll dp[2005][2005][2];

ll dfs(int pos,int p,int sign,int flag,int lead)
{
	ll max_num;
	if( pos == -1 )
	{
		if( p % m == 0 ) return 1;
		return 0;
	}
	if( !flag && !lead && dp[pos][p][sign] != -1 ) return dp[pos][p][sign];
	if( flag ) max_num = num[pos];
	else max_num = 9;
	ll res = 0;
	for (int i = 0; i <= max_num; i++)
	{
		if( sign && i != d ) continue;
		if( !sign && i == d ) continue;
		if( lead && i == 0 )
		{
			res += dfs(pos-1,(p*10+i)%m,sign,flag&&(i==max_num),lead&&(i==0));
			res %= mod;
			continue; 
		}
		res += dfs(pos-1,(p*10+i)%m,sign^1,flag&&(i==max_num),lead&&(i==0));
		res %= mod;
	}
	if( !flag && !lead ) dp[pos][p][sign] = res;
	return res;
}

ll solve(string a)
{
	num.clear();
	for (int i = a.length() - 1; i >= 0; i--) num.push_back(a[i]-'0');
	return dfs(num.size()-1,0,0,1,1);
}

bool check(string a)
{
	ll base = 0;
	for (int i = 0; i < a.length(); i++)
	{
		base = base * 10 + (a[i] - '0');
		base %= m;
		if( (i&1) && a[i] != d + '0' ) return false;
		if( !(i&1) && a[i] == d + '0' ) return false; 
	}
	if( base ) return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp,-1,sizeof(dp));
	cin >> m >> d;
	string a,b;
	cin >> a >> b;
	cout << (((solve(b) - solve(a))%mod+mod)%mod + check(a))%mod << '\n';
}

