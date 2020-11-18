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
typedef vector<pii> vi;
ll mod = 1e9 + 7;
ll dis[5050][2010];
bool vis[2010];
int link[2010][2010];
vi edge[2000+ 10];
int maxn[2010];
bool vis1[2010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	/*Iint n, m, k;
	cin >> n >> m >> k;
	rep(i, 1, n + 1){
		int u, v, w;
		cin >> u >> v >> w;
		link[u][v] = w;
		link[v][u] = w;
		edge[u].pb(mp(v, w));
		edge[v].pb(mp(u, w));
		maxn[u] = max(maxn[u], w);
		maxn[v] = max(maxn[v], w);
	}
	vis[1] = true;
	ll ans = 0;
	ll res = 0;
	rep(i, 1, min(k + 1,5010)){
		res = 0;
		rep(j, 1, n + 1){
			if(vis[j]){
				dis[i][j] = max(dis[i][j], dis[i - 1][j] + maxn[j]);
				res = max(res, dis[i][j]);
			}
			for(auto q : edge[j]){
				int t= q.fi;
				if(vis[t]){
					dis[i][j] = max(dis[i][j], dis[i - 1][t] + link[j][t]);
					vis1[j] = true;
					res = max(res, dis[i][j]);
					//cout << res << endl;
				}
			}
		}
		rep(j, 1, n + 1){
			if(vis1[i] || vis[i]) vis[i] = true;
		}
		//cout << res << endl;
		ans = (ans + res) % mod;
	}
	if(k <=5000) cout << ans << endl;
	else cout << (ans + (k - 5009) * res) % mod;*/
	freopen("1111.in","w", stdout);
	cout << 500000 << endl;
	rep(i, 1, 500000 + 1){
		if(i == 1) cout << "8485553";
		else cout << " 8485553";
	}
	cout << endl;
	return 0;
}