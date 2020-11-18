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
int deep[100000 + 10], f[100000 + 10];
vi res[100000 + 10], edge[100000 + 10];
void dfs(int rt, int fi){
	deep[rt] = deep[fi] + 1;
	f[rt] = f[fi];
	res[deep[rt]].pb(rt);
	for(auto i: edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
	}
}
struct node{
	ll l, r;
}dp[100000 + 10];
ll mod = 1e9 + 7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	ll n, s, c, d;
	cin >> n >> s >> c >> d;
	rep(i, 1, n){
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	dfs(s, 0);	
	res[0].pb(0);
	edge[0].pb(s);
	rep(i, 1, n + 1){
		cin >> dp[i].l >> dp[i].r;
	//	cout << "!!" << a[i].l << " " << a[i].r << endl;
	}
	ll ans = 0;
	rep(i, 1, n + 1){
		per(k, 1, i + 1){
			for(auto j : res[k]){

				ll tmp = dp[j].l;
				ll tmp1 = dp[j].r;
				dp[j].l = tmp + c * tmp1 ;
				dp[j].r = d * tmp + tmp1;
				dp[j].l %= mod;
				dp[j].r %= mod;
				//cout << dp[j].l << " " << dp[j].r << endl;
			}
			for(auto j : res[k - 1]){
				for(auto q : edge[j]){
					dp[j].l += dp[q].l;
					dp[j].r += dp[q].r;
					dp[j].l %= mod;
					dp[j].r %= mod;
					dp[q].l = 0;
					dp[q].r = 0;
				}
			}
		}
	}
	cout << (dp[0].l + dp[0].r) % mod << endl;
	return 0;
}