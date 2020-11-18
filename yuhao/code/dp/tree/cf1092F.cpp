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
ll dis = 0, res = 0;
ll deep[200000 + 10];
vi edge[200000 + 10];
ll siz[200000 + 10], a[200000 + 10];
int n;
void dfs(int rt, int fi){
	if(rt == 1) deep[rt] = 0;
	else deep[rt] = deep[fi] + 1;
	dis += deep[rt] * a[rt];
	siz[rt] = a[rt];
	for(auto i:edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		siz[rt] += siz[i];
	}
}
void dfs1(int rt, int fi, ll dis){
	res = max(res, dis);
	//cout << rt <<" " << dis << endl;
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs1(i, rt, dis - siz[i] + siz[1] - siz[i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n) {
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	dfs(1, 0);
	dfs1(1, 0, dis);
	cout <<  res << endl;
	return 0;
}