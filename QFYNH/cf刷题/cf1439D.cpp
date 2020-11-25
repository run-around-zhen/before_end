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
const int N = 505;
int n, m, mod;
int C[N][N];
int way[N];
int sum[N];
int g[N][N], f[N][N];
int add(int a, int b){
	if(a + b >= mod) return a + b - mod;
	return a + b;
}
int mul(int a, int b){
	return (ll)a * b % mod;
}
int get(int i){
	return i * (i + 1) / 2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m >> mod;
	rep(i, 0, m + 1){
		C[i][0] = 1;
		rep(j, 1, i + 1){
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
		}
	}
	way[0] = 1;
	rep(i, 1, m + 1){
		rep(j, 0, i){
			way[i] = add(way[i], mul(mul(i + 1, C[i - 1][j]), mul(way[j], way[i - j - 1])));
			sum[i] = add(sum[i], mul(mul(mul(add(get(j), get(i - j - 1)), way[j]), way[i - j - 1]), C[i - 1][j]));
			sum[i] = add(sum[i], mul(mul(i + 1, add(mul(sum[j], way[i - j - 1]), mul(way[j], sum[i - j - 1]))), C[i - 1][j]));
		}
	}
	n ++;
	f[0][0] = 1;
	rep(i, 0, n){
		rep(j, 0, m + 1){
			for(int k = 0; j + k <= m && i + k + 1 <= n; k ++){
				f[i + k + 1][j + k] = add(f[i + k + 1][j + k], mul(mul(f[i][j], way[k]), C[j + k][j]));
				g[i + k + 1][j + k] = add(g[i + k + 1][j + k], mul(add(mul(f[i][j], sum[k]), mul(g[i][j], way[k])), C[j + k][j]));
			}
		}
	}
	cout << g[n][m] << endl;
	return 0;
}