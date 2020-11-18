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
typedef pair<int, ll> pii;
typedef vector<pii> vi;
ll dis[2005][2005];
bool vis[2005][2005];
bool flag[2005];
vi edge[2005];
int st[2005];
int n;
double cal(int a, int b){
	return (1.0 * dis[n][a] - dis[n][b]) / (b - a);
}
void dfs(int rt, int k){
	flag[rt] = 1;
	if(vis[rt][k] || k <= 0) return;
	vis[rt][k] = 1;
	for(auto i :edge[rt]){
		if(dis[i.fi][k - 1] + i.se == dis[rt][k]) dfs(i.fi,k - 1);
	}
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int  m;
	cin >> n >> m;
	rep(i, 1, m + 1){
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].pb(mp(v, w));
		edge[v].pb(mp(u, w));
	}
	rep(i, 0, n + 1){
		rep(j, 0, n + 1) dis[i][j] = 1e18;
	}
	dis[1][0] = 0;
	rep(i, 1, n + 1){
		rep(j, 1, n + 1){
			for(auto k : edge[j]){
				dis[j][i] = min(dis[j][i], dis[k.fi][i - 1] + k.se); 
			}
		}
	}
	/*rep(i, 1, n + 1){
		cout << dis[n][i] << " ";
	}
	cout <<"!!!" << endl;*/
	int cnt = 0;
	per(k, 1, n + 1){
		if(dis[n][k] == 1e18) continue;
		while(cnt){
			if(cnt == 1){
				if(cal(st[0], k) < 0) cnt --;
				else break;
			}
			if(cnt > 1 && cal(st[cnt - 1], st[cnt - 2]) > cal(st[cnt - 2], k)) cnt --;
			else break;
		}
		st[cnt ++] = k; 
	}
	rep(i, 0, cnt){
		dfs(n, st[i]);
	}
	int ans = 0;
	rep(i, 1, n + 1){
		if(!flag[i]){
			ans ++;
		}
	}
	cout << ans << endl;
	rep(i, 1, n + 1){
		if(!flag[i]){
			cout << i << " ";
		}
	}
	return 0;
}