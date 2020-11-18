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
int INF = 0x3f3f3f;
vi edge[110];
int link[110][110];
int dp[55][55][55][55];
int siz[110];

void dfs(int rt, int fi){
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		siz[rt] += siz[i];
	}
}
int solve(int u, int v, int s1, int s2){
	//cout << "??" << u << " " << v << " " << s1 << " " << s2 << endl;
	if(s1 == 0 && s2 == 0) return dp[u][v][s1][s2] = 0;
	if(s1 == 0) return dp[u][v][s1][s2] = INF;
	if(dp[u][v][s1][s2] != -1) return dp[u][v][s1][s2];
	if(edge[v].size() == 1) return dp[u][v][s1][s2] = solve(v, u, s2, 0) + link[u][v];
	int g[55];
	memset(g, 0, sizeof(g));
	g[0] = INF;
	for(auto i : edge[v]){
		if(i == u) continue;
		for(int j = s1; j >= 0; j --){
			for(int k = 0; k <= j; k ++){
				g[j] = max(g[j], min(g[j - k], solve(v, i, k, s1 + s2 - k)) );
			}
		}
	}
	return dp[u][v][s1][s2] = g[s1] + link[u][v];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	rep(i, 1, n){
		int u, v, w;
		cin >> u >> v >> w;
		link[u][v] = w;
		link[v][u] = w;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	int rt;
	cin >> rt;
	int m;
	cin >> m;
	rep(i, 1, m + 1) {
		int x;
		cin >> x;
		siz[x] ++;
	}
	dfs(rt, 0);
	int ans = INF;
	//cout << rt << endl;
	for(auto i : edge[rt]){
		ans = min(ans , solve(rt, i, siz[i], m - siz[i]));
	//	cout << i << " " << solve(rt, i, siz[i], m - siz[i]) << endl;
	}
	//cout << solve(1, 2, 2, 0 ) << endl;
	//cout << solve(2, 3, 2, 0) << endl;
	//cout << solve(4, 3, 1, 0 ) << endl;
cout << ans << endl;
	return 0;
}