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
const int limit = 28;
int now_limit = 0;
int ans = 29;
int n, m;
const int N = 5e5 + 10;
int deg[N], a[N], b[N];
bool vis[N];
vector<pii> edge[N];
void init(){
	rep(i, 1, n + 1) deg[i] = 0;
}
bool check(int k, int maxn){
	if(deg[k] > maxn) return true;
	return false;
}
pii get_deg(int k){
	int maxn = 0, maxn_id = 0;
	for(auto i : edge[k]){
		deg[i.fi] ++;
		deg[i.se] ++;
		if(check(i.fi, maxn)){
			maxn = deg[i.fi];
			maxn_id = i.fi;
		}
		if(check(i.se, maxn)){
			maxn = deg[i.se];
			maxn_id = i.se;
		}
	}
	return mp(maxn, maxn_id);
}
void get_edge(int k){
	edge[k].clear();
	for(auto i : edge[k - 1]){
		if(!vis[i.fi] && !vis[i.se]){
			edge[k].pb(i);
		}
	}
}
void dfs(int k, int now_limit){
	if(now_limit >= ans) return;
	if(!sz(edge[k])) {
		ans = min(ans, now_limit);
		return ;
	}
	init();
	pii now_maxn = get_deg(k);
	int max_deg = now_maxn.fi;
	int max_id = now_maxn.se;
	if(max_deg <= 1){
		ans = min(ans, now_limit + sz(edge[k]));
		return ;
	}
	vis[max_id] = true;
	get_edge(k + 1);
	dfs(k + 1, now_limit + 1);
	vis[max_id] = false;
	vi use;
	for(auto i: edge[k]){
		if(i.fi == max_id){
			now_limit ++;
			if(now_limit >= ans) break;
			vis[i.se] = true; 
			use.pb(i.se);
		}
		if(i.se == max_id){
			now_limit ++;
			if(now_limit >= ans) break;
			vis[i.fi] = true;
			use.pb(i.fi);
		}
	}
	get_edge(k + 1);
	dfs(k + 1, now_limit);
	for(auto i : use){
		vis[i] = false;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, m + 1){
		cin >> a[i] >> b[i];
		a[i] ++;
		b[i] ++;
		deg[a[i]] ++;
		deg[b[i]] ++;
	}
	rep(i, 1, n + 1){
		if(deg[i] > limit){
			now_limit ++;
			vis[i] = true;
		}
	}
	rep(i, 1, m + 1){
		if(!vis[a[i]] && !vis[b[i]]) edge[0].pb(mp(a[i], b[i]));
	}
	if(now_limit > limit || sz(edge[0]) > (limit + 1) * (limit - now_limit)){
		cout << "-1" << endl;
		return 0;
	}
	dfs(0, now_limit);
	if(ans > limit) cout << "-1" << endl;
	else{
		cout << n - ans << endl;
	}
	return 0;
}