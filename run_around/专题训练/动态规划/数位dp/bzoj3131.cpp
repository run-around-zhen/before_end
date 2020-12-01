#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;

map<ll,ll> dp[20];
vector<ll> s,res;
vector<int> num;
int a[] = {2,3,5,7};
ll n;
ll mod = 1e9 + 7;

bool cmp(ll a,ll b)
{
	return a > b;
}

void dfsx(int pos,ll now)
{
	if( pos == 4 )
	{
		s.push_back(now);
		return;
	}
	ll base = 1;
	for (int i = 0; ; i++)
	{
		if( now * base > n ) return;
		dfsx(pos+1,now*base);
		base *= a[pos];
	}
}

ll dfs(int pos,ll rest,int flag,int lead)
{
	if( pos < 0 ) 
	{
		if( lead || rest != 1 ) return 0;
		return 1;
	}
	if( !flag && !lead && dp[pos].find(rest) != dp[pos].end() ) return dp[pos][rest];
	ll max_num;
	if( !flag ) max_num = 9;
	else max_num = num[pos];
	ll res = 0;
	for (int i = 0; i <= max_num; i++)
	{
		if( lead && i == 0 ) res += dfs(pos-1,rest,flag&&(i==max_num),lead&&(i==0));
		else
		{
			if( i == 0 || rest % i ) continue;
			res += dfs(pos-1,rest/i,flag&&(i==max_num),lead&&(i==0));
		}
	}
	if( !flag && !lead ) dp[pos][rest] = res;
	return res;
}

ll solve(ll x,ll rest)
{
	num.clear();
	while( x )
	{
		num.push_back(x%10);
		x /= 10;
	}
	return dfs(num.size()-1,rest,1,1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll k;
	cin >> n >> k;
	dfsx(0,1);
	for (int i = 0; i < s.size(); i++)
	{
		res.push_back(solve(n,s[i]));
	}
	priority_queue<ll,vector<ll>,greater<ll> > q;
	sort(res.begin(),res.end(),cmp);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res.size(); j++)
		{
			if( q.size() < k ) q.push(res[i]*res[j]);
			else 
			{
				if( q.top() > res[i]*res[j] ) break;
				else
				{
					q.pop();
					q.push(res[i]*res[j]);
				}
			}
		}
	}
	ll ans = 0;
	while( !q.empty() )
	{
		ans = ( ans + q.top() ) % mod;
		q.pop();
	}
	cout << ans << '\n';
	return 0;
}
