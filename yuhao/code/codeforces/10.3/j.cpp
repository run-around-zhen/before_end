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
const int inf = 0x3f3f3f3f;
const int N = 10010;
vi edge[N];
int f[N], g[N], h[N], dp1[4], dp2[4], d[N];
int n;
int min(int a, int b, int c){
	return min(a, min(b, c));
}
void dfs(int rt, int fi){
	if(fi && d[rt] == 1){
		f[rt] = h[rt] = 1;
		g[rt] = 0;
		return ;
	}
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
	}
	int tmp = 0, tmp1 = 0, tmp2 = 0;
	for(auto i : edge[rt]){
		tmp += min(f[i], g[i], h[i]);
		tmp1 += f[i];
		tmp2 += min(f[i], h[i]);
	}
	f[rt] = min(tmp + 1, tmp1);
	g[rt] = tmp2;
	h[rt] = tmp + 1;
	dp1[0] = 0;
	dp1[1] = dp1[2] = dp1[3] = inf;
	for(auto i : edge[rt]){
		if(i == fi) continue;
		f[rt] = min(f[rt], tmp2 - min(f[i], h[i]) + f[i]);
		g[rt] = min(g[rt], tmp2 - min(f[i], h[i]) + g[i]);
		memcpy(dp2, dp1, sizeof(dp2));
		dp1[0] = dp2[0] + min(h[i], f[i]);
		dp1[1] = min(dp2[0] + f[i], dp2[1] + min(h[i], f[i])); 
		dp1[3] = min(dp2[3] + min(f[i], g[i], h[i]), dp2[0] + g[i]);
		dp1[2] = min(dp2[2] + min(f[i], g[i], h[i]), dp2[1] + min(f[i], g[i], h[i]), dp2[3] + f[i]);
	}
	h[rt] = min(h[rt], dp1[1], dp1[2]);
	//cout << rt << " " << h[rt] << " " << g[rt] << " " << f[rt] << " " << dp1[1] << " " << dp1[2] << endl; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n){
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
		d[u] ++;
		d[v] ++;
	}
	int rt = 1;
	rep(i, 1, n + 1) {
		if(d[i] == 1) {
			rt = i;
			break;
		}
	}
	dfs(rt, 0);
	cout << min(f[rt], h[rt]) << endl;
	return 0;
}