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
int dp[200000 + 10][2];
vi edge[200000 + 10];
ll ans = 0;
ll minn[200000 + 10], a[200000 + 10], b[200000 + 10], c[200000 + 10];
void dfs(int rt, int fi){
	minn[rt] = min(a[rt], minn[fi]);
	//cout << minn[rt] << " " << rt << endl;
	if(b[rt] != c[rt]){
		dp[rt][b[rt]] += 1;
	}
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		dp[rt][0] += dp[i][0];
		dp[rt][1] += dp[i][1];
	}
	if(minn[rt] == a[rt]){
		ll tmp = min(dp[rt][0], dp[rt][1]);
		ans += tmp * a[rt] * 2;
		dp[rt][0] -= tmp;
		dp[rt][1] -= tmp;
	}
//	cout << rt << " " << dp[rt][1] << " " << dp[rt][0] << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	minn[0] = 1e10;
	rep(i, 1, n + 1){
		cin >> a[i] >> b[i] >> c[i];
	}
	rep(i, 1, n){
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	dfs(1, 0);
	if(dp[1][0] == 0 && dp[1][1] == 0) {
		cout << ans << endl;
	}
	else{
		cout << "-1" << endl;
	}
	return 0;
}	