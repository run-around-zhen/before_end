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
vi edge[200000 + 10];
int dp[200000 + 10][2], maxn[200000 + 10][2], minn[200000 + 10][2];
bool vis[200000 + 10];
void dfs(int rt, int fi){
	if(vis[rt]) minn[rt][0] = maxn[rt][0] = 0;
	for(auto i: edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		if(minn[i][0] + 1 < minn[rt][0]){
			//if(minn[i][1] + 1 < minn[rt][1]) minn[rt][1] = minn[i][1] + 1;
			//else 
			minn[rt][1] = minn[rt][0];
			minn[rt][0] = minn[i][0] + 1;
		}
		else if(minn[i][0] + 1< minn[rt][1]){
			minn[rt][1] = minn[i][0] + 1;
		}
		if(maxn[i][0] + 1> maxn[rt][0]){
			//if(maxn[i][1] + 1 > maxn[rt][1]) maxn[rt][1] = maxn[i][1] + 1;
			//else 
			maxn[rt][1] = maxn[rt][0];
			maxn[rt][0] = maxn[i][0] + 1;
		}
		else if(maxn[i][0] + 1 > maxn[rt][1]){
			maxn[rt][1] = maxn[i][0] + 1;
		}
	}
}
void dfs1(int rt, int fi){
	if(dp[fi][0] < minn[rt][0]){
		minn[rt][1] = minn[rt][0];
		minn[rt][0] = dp[fi][0];
	}
	else if(dp[fi][0] < minn[rt][1]){
		minn[rt][1] = dp[fi][0];
	}
	if(dp[fi][1] > maxn[rt][0]){
		maxn[rt][1] = maxn[rt][0];
		maxn[rt][0] = dp[fi][1];
	}
	else if(dp[fi][1] > maxn[rt][1]){
		maxn[rt][1] = dp[fi][1];
	}
	for(auto i : edge[rt]){
		if(i == fi) continue;
		if(maxn[i][0] + 1 == maxn[rt][0]) dp[rt][1] = maxn[rt][1] + 1;
		else dp[rt][1] = maxn[rt][0] + 1;
		if(minn[i][0] + 1 == minn[rt][0]) dp[rt][0] = minn[rt][1] + 1;
		else dp[rt][0] = minn[rt][0] + 1;
		dfs1(i, rt);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 0, n + 1){
		dp[i][1] = maxn[i][0] = maxn[i][1] = -1e9;
		dp[i][0] = minn[i][0] = minn[i][1] = 1e9;
	}
	rep(i, 1, n){
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	rep(i, 1, m + 1) {
		int x;
		cin >> x;
		vis[x] = 1;
	}
	dfs(1, 0);
	/*rep(i, 1, n + 1){
		cout << minn[i][0] << " " << minn[i][1] << " " <<maxn[i][0] << " "<<maxn[i][1] << endl;
	}*/
	dfs1(1, 0);
	/*rep(i, 1, n + 1){
		cout << i << " " << maxn[i][0] << " " << minn[i][0] << endl;
	}*/
	int flag = 0;
	rep(i, 1, n + 1){
		if(minn[i][0] == maxn[i][0]) {
			flag = 1;
			cout << "YES" << endl;
			cout << i << endl;
			break;
		}
	}
	if(!flag){
		cout << "NO" << endl;
	}
	return 0;
}