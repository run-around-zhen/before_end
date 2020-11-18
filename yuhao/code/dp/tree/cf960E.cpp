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
ll a[200000 + 10], dp[200000 + 10][2], siz[200000 + 10], res[200000 + 10][2];
ll mod = 1e9 + 7;
vi edge[200000 + 10];
ll ans = 0;
int n;
void dfs(int rt, int fi){
	//ans += a[rt];
	siz[rt] = 1;
	dp[rt][0] += 1;
	for(auto i: edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		siz[rt] = (siz[rt] + siz[i]) % mod;
		dp[rt][0] = (dp[rt][0] + dp[i][1]) % mod;
		dp[rt][1] = (dp[rt][1] + dp[i][0]) % mod;
	}
}
void dfs1(int rt, int fi){
	//cout <<"!!" << rt <<" " << ans << endl;
	ans = (ans + a[rt] * dp[rt][0] % mod * (n - siz[rt]) % mod + mod) % mod;
	ans = (ans - a[rt] * dp[rt][1] % mod * (n - siz[rt]) % mod + mod) % mod;
	//ans = (ans + a[rt]) % mod;
	ans = (ans + a[rt] * siz[rt] % mod + mod) % mod;
//	cout << rt << " " << ans << " " << n - siz[rt] << endl;
	ans = (ans + a[rt] * res[rt][0] % mod * (siz[rt]) % mod + mod) % mod;
	ans = (ans - a[rt] * res[rt][1] % mod * (siz[rt]) % mod + mod) % mod;
	//cout << rt << " " << res[rt][0] << " " << res[rt][1] << "!!!" << endl;
	res[rt][0] = (res[rt][0] + dp[rt][0]) % mod;
	res[rt][1] = (res[rt][1] + dp[rt][1]) % mod;

	//cout <<"!!!" << rt << " " << ans << endl;
	//cout << rt <<" " << ans << " " << dp[rt][0] << " " << dp[rt][1] << " " << siz[rt] << endl;
	//cout << rt << " " << ans << endl;
	for(auto i: edge[rt]){
		if(i == fi) continue;
		ans = (ans + a[rt] * dp[i][1] % mod * (siz[rt] - siz[i]) % mod + mod) % mod;
		ans = (ans - a[rt] * dp[i][0] % mod * (siz[rt] - siz[i]) % mod + mod) % mod;
		res[i][0] = (res[rt][1] - dp[i][0] + mod) % mod;
		res[i][1] = (res[rt][0] - dp[i][1] + mod) % mod;
		//cout << rt << " " << i << " " << ans << endl;
	}
	//cout << rt << " " << ans << endl;
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs1(i, rt);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n){
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	dfs(1, 0);
	dfs1(1, 0);
	cout << ans << endl;
	return 0;
}