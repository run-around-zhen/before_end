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
ll ans = 0;
ll dp[100000 + 10][30][2];
vi edge[100000 + 10];
int a[100000 + 10];
void dfs(int rt, int fi){
	rep(i, 0, 25){
		dp[rt][i][(a[rt] >> i) & 1] = 1;
	}
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		rep(j, 0, 25) {
			ans += dp[rt][j][0] * dp[i][j][1] * (1ll << j);
			ans += dp[rt][j][1] * dp[i][j][0] * (1ll << j);
			if((a[rt] >> j) & 1){
				dp[rt][j][1] += dp[i][j][0];
				dp[rt][j][0] += dp[i][j][1];
			}
			else{
				dp[rt][j][0] += dp[i][j][0];
				dp[rt][j][1] += dp[i][j][1];
			}
			
		}
	}
	ans += a[rt];
	//cout << rt << "  " << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n){
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}