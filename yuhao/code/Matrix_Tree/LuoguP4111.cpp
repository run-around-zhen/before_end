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
int a[300 + 10][300 + 10];
char s[300 + 10][300 + 10];
int id[300 + 10][300 + 10];
const int mod = 1e9;
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
	a[u][v] = sub(a[u][v], 1);
	a[v][u] = sub(a[v][u], 1);
	a[u][u] = add(a[u][u], 1);
	a[v][v] = add(a[v][v], 1);
}
int det(int n) { // det(a[1..n-1][1..n-1])
	int ans = 1;
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n + 1) cin >> (s[i] + 1);
	int idx = 0;
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			if(s[i][j] == '.') id[i][j] = ++idx;
		}
	}
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			if(s[i][j] == '.'){
				if(id[i - 1][j]) add_edge(id[i][j], id[i - 1][j]);
				if(id[i][j - 1]) add_edge(id[i][j], id[i][j - 1]);
			}
		}
	}
	cout << det(idx) << endl;
	return 0;
}