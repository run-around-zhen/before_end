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
int n, k;
vi edge[1000000 + 10];
int deep[1000000 + 10], dp[1000000 + 10], low[1000000 + 10];
int ans[1000000 + 10];
void dfs(int rt, int fi){
	deep[rt] = deep[fi] + 1;
	//cout << rt << " " << fi << " " << deep[rt] << " " << deep[fi] << endl;
	if(edge[rt].size() == 1 && rt != 1){	
		low[rt] = deep[rt];
		dp[rt] = 1;
		return ;
	}
	int minn = 1e9;
	for(auto i: edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		if(deep[rt] + k >= low[i]){
			minn = min(minn, low[i]);
			dp[rt] += dp[i];
		}
	}
	low[rt] = minn;
}
void dfs1(int rt, int fi){
	ans[rt] = dp[rt];
//	cout << rt << " " << fi << " " << dp[rt] << " " << low[rt] << " " << deep[rt] << endl;
	for(auto i: edge[rt]){
		if(i == fi) continue;
		int tmp = dp[i];
		if(deep[rt] + k >= low[i]){
			dfs1(i, rt);
			ans[rt] = max(ans[rt], dp[rt] - tmp + ans[i]);
		}
		else{
			dfs1(i, rt);
			ans[rt] = max(ans[rt], dp[rt] + ans[i]);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	rep(i, 2, n + 1){
		int x;
		cin >> x;
		edge[i].pb(x);
		edge[x].pb(i);
	}
	dfs(1, 0);
	dfs1(1, 0);
	cout << ans[1] << endl;
	return 0;
}