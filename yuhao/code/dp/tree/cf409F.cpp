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
int a[100000 + 10], n, lis[100000 + 10];
vi edge[100000 + 10];
int ans = 0;
void dfs(int rt, int fi){
	int pos = lower_bound(lis + 1, lis + 1 + n, a[rt]) - lis;
//	cout << a[rt] << " " << lis[pos] << endl;
	int tmp = lis[pos];
	lis[pos] = a[rt];
	ans = max(ans, pos);
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
	}
	lis[pos] = tmp;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n){
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	rep(i, 1, n + 1){
		rep(j, 1, n + 1) lis[j] = 1e9;
		dfs(i, 0);
	}
	cout << ans << endl;
	return 0;
}