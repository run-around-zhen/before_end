#include <iostream>
#include <map> 
#include <vector>
using namespace std;

typedef long long ll;

map<ll,ll> dp[20];
ll sta;
int tmp[20],cnt[20];
int t;

string change(ll x)
{
	string res;
	while( x )
	{
		int z = x % 16;
		if( z >= 10 ) res += z - 10 + 'a';
		else res += z + '0';
		x /= 16;
	}
	string ans;
	for (int i = res.length() - 1; i >= 0; i--) ans += res[i];
	return ans;
}

int cal(char x)
{
	if( x >= 'a' && x <= 'f' ) return x - 'a' + 10;
	else return x - '0';
}

vector<int> num;

ll hs()
{
	ll res = 0;
	for (int i = 0; i < 16; i++) tmp[i] = 0;
	for (int i = 0; i < 16; i++) tmp[cnt[i]] ++;
	for (int i = 0; i < 16; i++)
	{
		res = res * 16 + tmp[i];
	}
	return res;
}

ll dfs(int pos,int flag,int lead)
{
	ll max_num;
	ll sta = hs();
	if( pos < 0 ) 
	{
		if( lead ) return 0;
		return 1; 
	}
	if( !flag && !lead && dp[pos].find(sta) != dp[pos].end() ) return dp[pos][sta];
	if( !flag ) max_num = 15;
	else max_num = num[pos];
	ll res = 0;
	for (int i = 0; i <= max_num; i++)
	{
		if( lead && i == 0 )
		{
			res += dfs(pos-1,flag&&(i==max_num),lead&&(i==0));
			continue;
		}
		if( cnt[i] == t ) continue;
		cnt[i] ++;
		res += dfs(pos-1,flag&&(i==max_num),lead&&(i==0));
		cnt[i] --;
	}
	if( !flag && !lead ) dp[pos][sta] = res;
	return res;
}

ll slove(string a)
{
	num.clear();
	for (int i = a.length()-1; i >= 0; i--) num.push_back(cal(a[i]));
	return dfs(num.size()-1,1,1); 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll k;
	cin >> k >> t;
	ll l = 1,r = 2e18;
	string ans;
	while( l <= r )
	{
		ll mid = (l+r)>>1;
		string z = change(mid);
		//cout << mid << ' ' << slove(z) << '\n';
		if( slove(z) >= k )
		{
			ans = z;
			r = mid - 1;
		}else l = mid + 1;
		//cout << l << ' ' << r << '\n';
	}
	cout << ans << '\n';
	return 0;
} 
