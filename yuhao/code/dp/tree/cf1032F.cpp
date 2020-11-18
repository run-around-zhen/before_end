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
ll dp[300000 + 10][4];
vi edge[300000 + 10];
ll g[4];
void dfs(int rt, int fi){
	dp[rt][0] = 1;
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		g[0] = dp[rt][0] * (dp[i][0] + dp[i][2]) % mod;
		g[1] = (dp[rt][1] * (dp[i][0] + 2 * dp[i][2]) % mod + dp[rt][0] * dp[i][2] % mod) % mod;
		g[2] = (dp[rt][0] * (dp[i][0] + dp[i][1]) % mod + dp[rt][1] * (dp[i][0] + dp[i][1]) % mod + dp[rt][2] * (dp[i][0] + 2 * dp[i][2])) % mod;
		swap(g, dp[rt]);
	}
	//cout << rt << " " << dp[rt][0] << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n){
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	dfs(1, 0);
	cout << (dp[1][0] + dp[1][2]) % mod;
	return 0;
}