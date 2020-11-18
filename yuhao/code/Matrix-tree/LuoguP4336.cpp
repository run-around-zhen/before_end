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
const int mod = 1e9 + 7;
int n;
int res = 0;
int a[20][20], b[20][20], siz[400], u[20][400], v[20][400];
ll mul(int a, int b){
	return (ll)a * b % mod;
}
ll sub(int a, int b){
	if(a - b < 0) return a - b + mod;
	return a - b;
}
ll add(int a, int b){
	if(a + b >= mod) return a + b - mod;
	return a + b;
}
void add_edge(int u, int v){
	b[u][v] = sub(b[u][v], 1);
	b[v][u] = sub(b[v][u], 1);
	b[u][u] = add(b[u][u], 1);
	b[v][v] = add(b[v][v], 1);
}
void del_edge(int u, int v){
	b[u][v] = add(b[u][v], 1);
	b[v][u] = add(b[v][u], 1);
	b[u][u] = sub(b[u][u], 1);
	b[v][v] = sub(b[v][v], 1);
}
int det(int n) { // det(a[1..n-1][1..n-1])
	int ans = 1;
	rep(i, 1, n){
		rep(j, 1, n){
			a[i][j] = b[i][j];
		}
	}
	rep(i, 1, n) {
		rep(j, i + 1, n) while(a[j][i]) {
			int t = a[i][i] / a[j][i];
			rep(k, i, n) a[i][k] = sub(a[i][k], mul(a[j][k], t)), swap(a[i][k], a[j][k]);
			ans = mod - ans;
		}
		if(a[i][i] == 0) return 0;
		ans = mul(ans, a[i][i]);
	}
	return ans;
}
void dfs(int x, int y){
	if(x == n){
		if((n - y) % 2 == 1) res = add(res, det(n));
		else res = sub(res, det(n));
		//cout << res << endl;
		return ;
	}
	dfs(x + 1, y);
	rep(i, 1, siz[x] + 1){
		add_edge(u[x][i], v[x][i]);
	}
	dfs(x + 1, y + 1);
	rep(i, 1, siz[x] + 1){
		del_edge(u[x][i], v[x][i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	rep(i, 1, n){
		cin >> siz[i];
		rep(j, 1, siz[i] + 1){
			cin >> u[i][j] >> v[i][j];
		}
	}
	dfs(1, 0);
	cout << res << endl;
	return 0;
}