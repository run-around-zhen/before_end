#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(ll i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll n, a, b, c, d;
unordered_map<ll, ll>dp;
ll dfs(ll rt){
	//cout << rt << endl;
	if(rt == 1) return d;
	if(dp[rt]) return dp[rt];
	//dp[rt] = 1e18;
	rep(j, 0, 15){
		ll i = rt - j + 8;
		//cout << rt << " " << i << endl;
		if(i <= 0 || dp[i]) continue;
		dp[i] = 1e18;
		if(1e18 / i > d ) dp[i] = min(dp[i], d * i);
		if(i % 2 == 0){
			dp[i] = min(dp[i], dfs(i / 2) + a);
		}
		if(i % 3 == 0){
			dp[i] = min(dp[i], dfs(i / 3) + b);
		}
		if(i % 5 == 0){
			dp[i] = min(dp[i], dfs(i / 5) + c);
		}
	}
	rep(j, 0, 15){
		rep(k, 0, 15){
			ll i = rt - j + 8;
			ll t = rt - k + 8;
			if(i < 0 || t <  0) continue;
			dp[i] = min(dp[i], dp[t] + d * abs(t - i));
		}
	}
	return dp[rt];
	/*if(i % 2 == 0){
		dp[i] = min(dp[i], dfs(i / 2) + a);
	}
	if(i % 3 == 0){
		dp[i] = min(dp[i], dfs(i / 3) + b);
	}
	if(i % 5 == 0){
		dp[i] = min(dp[i], dfs(i / 5) + c);
	}
	i ++;
	dp[i] = 1e18;
	if(i % 2 == 0){
		dp[i] = min(dp[i], dfs(i / 2) + a);
	}
	if(i % 3 == 0){
		dp[i] = min(dp[i], dfs(i / 3) + b);
	}
	if(i % 5 == 0){
		dp[i] = min(dp[i], dfs(i / 5) + c);
	}
	i -= 2;
	if(i > 0){
		dp[i] = 1e18;
	if(i % 2 == 0){
		dp[i] = min(dp[i], dfs(i / 2) + a);
	}
	if(i % 3 == 0){
		dp[i] = min(dp[i], dfs(i / 3) + b);
	}
	if(i % 5 == 0){
		dp[i] = min(dp[i], dfs(i / 5) + c);
	}
	//i -= 2;
	}
	i ++ ;*/
	//dp[i] = min(dp[i], dfs(i + 1) + d);
	//dp[i] = min(dp[i], dfs(i - 1) + d);
	//return dp[rt];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		cin >> n >> a >> b >> c >> d;
		dp.clear();
		cout << dfs(n) << endl;
		/*rep(i, 0, 20){
			cout << i << " " << dp[i] << endl;
		}*/
		/*for(auto i : dp){
			cout << i.fi <<" " << i.se << endl;
		}*/
	}
	return 0;
}