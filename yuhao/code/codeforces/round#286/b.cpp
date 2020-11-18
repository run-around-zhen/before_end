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
vi edge[110][110];
bool vis[110];
void dfs(int rt, int fi, int to, int w){
	//cout << rt << " "  << to << " " << w << endl;
	vis[rt] = true;
	if(rt == to) return ;
	for(auto i : edge[w][rt]){
		if(!vis[i])  dfs(i, rt, to, w);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, m + 1) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[w][u].pb(v);
		edge[w][v].pb(u);
		//cout << "??? " << u << " " << v << " " << w << endl;
	}
	/*for(auto i : edge[1][5]){
		cout << i << "!!" << endl;
	}*/
	int q;
	cin >> q;
	while(q --){
		int a, b;
		cin >> a >> b;
		int ans = 0;
		rep(i, 1, m + 1){
			memset(vis, false, sizeof(vis));
			dfs(a, 0, b, i);
			if(vis[b]) ans ++ ;
		}
		cout << ans << endl;
	}
	return 0;
}