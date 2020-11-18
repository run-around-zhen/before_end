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
typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, k;
void dfs(int rt, int fi){
	if(edge[rt].size() == 1 && rt != 1){
		dp[rt][0] = 0;
		return ;
	}
	for(auto i: edge[rt]){
		if(i.fa == fi) continue;
		dfs(i, rt);
		rep(j, 1, k + 1){
			dp[i][j] = max(dp[i][j], dp[])
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		cin >> n >> k;
		rep(i, 0, n){
			int u, v, a, b;
			cin >> u >> v >> a >> b;
			edge[u].pb({v, a, b});
			edge[v].pb({u, a, b});
		}
		dfs(1, 0);
	}
	return 0;
}