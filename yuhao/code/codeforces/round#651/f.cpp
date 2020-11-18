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
vi edge[1010], v[1010];
void dfs(int rt, int fi){
	siz[rt] = 1;
	for(auto i:edge[rt]){
		if(vis[i] || i == fi) continue;
		dfs(i, rt);
		siz[rt] += siz[i];
		v[rt].pb(v[i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		rep(i, 1, n){
			int u, v;
			cin >> u >> v;
			edge[u].pb(v);
			edge[v].pb(u);
		}
		rep(i, 1, n + 1) s[1].insert(i);
		int pos = -1;
		rep(i, 1, n + 1){
			if(vis[i]) continue;
			memset(siz, 0, sizeof(siz));
			dfs(i, -1);
			rep(j, 1, n + 1){
				if(siz[j] == n / 2){
					for(auto k :v[j]){
						s[1].erase(k);
						s[0].insert(k);
					}
					pos = j;
					break;
				}
			}
		}
		ask()
		cal(s[1], pos);
		cal(s[0], pos);
	}
	return 0;
}