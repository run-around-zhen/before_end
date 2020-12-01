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
bool vis[1000000 + 10];
int deg[1000000 + 10];
int siz[1000000 + 10];
vi edge[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int _;
	cin >> _;
	while(_ --){
		int n;
		cin >> n;
		rep(i, 1, n + 1){
			deg[i] = 0;
			siz[i] = 0;
			vis[i] = false;
			edge[i].clear();
		}
		rep(i, 1, n + 1){
			int u, v;
			cin >> u >> v;
			edge[u].pb(v);
			edge[v].pb(u);
			deg[u] ++;
			deg[v] ++;
		}
		queue<int>q;
		rep(i, 1, n + 1){
			siz[i] = 1;
			if(deg[i] == 1) {
				q.push(i);
			}
		}
		while(!q.empty()){
			int x = q.front();
			vis[x] = true;
			q.pop();
			for(auto i : edge[x]){
				deg[i] --;
				siz[i] += siz[x];
				if(deg[i] == 1){
					q.push(i);
				}
			}
		}
		ll ans = 0;
		rep(i, 1, n + 1){
			if(!vis[i]){
				ans += (ll)siz[i] * (n - siz[i]) * 2;
				ans += (ll)siz[i] * (siz[i] - 1);
			}
		}
		cout << ans / 2 << endl;
	}
	return 0;
}