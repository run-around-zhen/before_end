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
int A[1000000 + 10], inv[1000000 + 10];
ll mod = 1e9 + 7;
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
ll c(int a, int b){
	if(a < b) return 0;
	return (ll)A[a] * inv[b] % mod * inv[a - b] % mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	A[0] = 1;
	inv[0] = 1;
	rep(i, 1, 1000000 + 1){
		A[i] = (ll)A[i - 1] * i % mod;
		inv[i] = (ll)inv[i - 1] * qpow(i, mod - 2) % mod;
	}
	ll ans = c(m, n) * c(m, n) % mod * A[n] % mod * A[n] % mod;
//	cout << ans << endl;
	rep(i, 1, n + 1){
		if(i % 2 == 1) ans = (ans - c(n, i) * c(m, i) % mod * A[i] % mod * A[n - i] % mod* A[n - i] % mod * c(m - i, n - i) % mod * c(m - i, n - i) % mod + mod) % mod;
		else ans = (ans + c(n, i) * c(m, i) % mod * A[i] % mod * A[n - i] % mod* A[n - i] % mod * c(m - i, n - i) % mod * c(m - i, n - i) % mod) % mod; 
		//cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}