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
const int N = 1000000;
int  mod = 998244353;
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		b /= 2;
		a = a * a % mod;
	}
	return res;
}
int A[N + 10], inv[N + 10];
int n, m, k;
int get(int a, int b){
	if(a < b) return 0;
	return 1ll * A[a] * inv[b] % mod * inv[a - b] % mod;
}
int add(int a, int b){
	if(a + b >= mod) return a + b - mod;
	return a + b;
}
int solve(){
	int ans = 0;
	if(k == 1){
		return n;
	}
	rep(i, k, n + 1){
		ans = (ans + 1ll * get(i - 1, k - 1) * get(n + k - i - 1, k - 1) % mod * get(m + k - i - 1, k - 1)) % mod;
	}
	return ans;
}
int main(){
	srand(time(0));
	A[0] = 1;
	inv[0] = 1;
	rep(i, 1, N + 1) {
		A[i] = (ll)A[i - 1] * i % mod;
	}
	inv[N] = qpow(A[N], mod - 2);
	per(i, 0, N) inv[i] = (ll)inv[i + 1] * (i + 1) % mod;
	int T;
	scanf("%d", &T);
	while(T --){
		scanf("%d %d %d", &n, &m, &k);
		if(n > m) swap(n, m);
		printf("%d\n", solve());
	}
	return 0;
}