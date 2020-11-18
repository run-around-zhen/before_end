#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
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
ll mod = 998244353;
vi edge[200000 + 10];
ll dp[200000 + 10][2];
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		b /= 2;
		a = a * a % mod;
	}
	return res;
}
void dfs(int rt, int fi){
	ll tmp = 1;
	dp[rt][0] = 1;
	dp[rt][1] = 1;
	int son = 0;
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		son ++ ;
		dp[rt][1] = dp[rt][0] = (dp[rt][0] * (dp[i][0] + dp[i][1])) % mod;
		tmp = (tmp * dp[i][0]) % mod;
	}
	if(!son) return ;
	dp[rt][1] = (dp[rt][1] - tmp + mod) % mod;
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dp[rt][0] = (dp[rt][0] - tmp * qpow(dp[i][0], mod - 2) % mod * dp[i][1] % mod + mod) % mod;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 2, n + 1){
		int x;
		cin >> x;
		edge[x].pb(i);
		edge[i].pb(x);
	}
	dfs(1, 0);
	cout << dp[1][0];
	return 0;
}