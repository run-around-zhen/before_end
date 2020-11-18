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
vi edge[400000 + 10];
int siz[400000 + 10], dp[400000 + 10][2], dp1[400000 + 10], dp2[400000 + 10], res[400000 + 10];
int n;
bool ans[400000 + 10];
int g[400000 + 10];
void upmax(int &x, int &y, int val){
	if(val > x){
		y = x;
		x = val;
	}
	else if(val > y){
		y = val;
	}
}
void dfs(int rt, int fi){
	siz[rt] = 1;
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		siz[rt] += siz[i];
		if(siz[i] > n / 2) g[rt] = i;
		if(siz[i] > n / 2) upmax(dp[rt][0], dp[rt][1], dp[i][0]);
		else upmax(dp[rt][0], dp[rt][1], siz[i]);
	}
	if(n - siz[rt] > n / 2) g[rt] = -1;
}
void dfs1(int rt, int fi){
	if(n - siz[rt] <= n / 2){
		res[rt] = n - siz[rt];
	}
	else if(dp[fi][0] == siz[rt]){
		res[rt] = max(res[fi], dp[fi][1]);
	}
	else{
		res[rt] = max(res[fi], dp[fi][0]);
	}
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs1(i, rt);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	rep(i, 1, n){
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	dfs(1, 0);
	dfs1(1, 0);
	rep(i, 1, n + 1){
		if(g[i] == 0 || (g[i] != - 1 && siz[g[i]] - dp[g[i]][0] <= n / 2) ||(g[i] == - 1 && n - siz[i] - res[i] <= n / 2)){
			ans[i] = true;
		}
	}
	/*rep(i, 1, n + 1) cout << res[i] << " ";
	cout << endl;*/
	rep(i, 1, n + 1) cout << ans[i]<< " ";
	return 0;
}