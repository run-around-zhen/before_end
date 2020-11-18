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
const int N = 5050;
int c[N + 10][N + 10];
int dp[N + 10], g[N + 10], f[N + 10], A[N + 10][N + 10];
int mod;
ll add(ll a ,ll b){
	if(a + b >= mod) return a + b - mod;
	return a + b;
}
ll mul(ll a, ll b){
	return a * b % mod;
}
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T >> mod;
	rep(i, 0, N + 1){
		c[i][0] = c[i][i] = 1;
		rep(j, 1, i){
			c[i][j] = ((ll)c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	rep(i, 1, N + 1){
		A[i][0] = 1;
		rep(j, 1, N + 1){
			A[i][j] = (ll)A[i][j - 1] * i % mod;
		}
	}
	f[2] = 2;
	rep(i, 3, N + 1){
		rep(j, 1, i - 1){
			f[i] = add(f[i], mul(mul(c[i - 1][j], j), mul(A[i - 1][i - 2 - j], j * j)));
		}
		f[i] = mul(i, add(f[i], (i - 1) * (i - 1)));
		
	}
	g[0] = 1;
	g[1] = 1;
	g[2] = 2;
	rep(i, 3, N + 1){
		g[i] = A[i][i - 2];
		rep(j, 1, i){
			g[i] = add(mul(mul(c[i - 1][j - 1], j >= 2? A[j][j - 2]:1), g[i - j]), g[i]);
		}
	}
	rep(i, 2, N + 1){
		dp[i] = f[i];
		rep(j, 1, i){
			dp[i] = add(mul(c[i - 1][j - 1], add(mul(f[j], g[i - j]), mul(j >= 2?A[j][j - 2]:1, dp[(i - j)]))), dp[i]);
		}
	}
	while(T --){
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}
/*
5 1000000007
2
3
4
5
107
*/