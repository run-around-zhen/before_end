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
ll mod = 1e9 + 7;
ll inv[2000000 + 10], A[2000000 + 10], bas[2000000 + 10], sum[2000000 + 10], a[2000000 + 10];
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
ll get(int a, int b){
	if(a < b) return 0;
	return A[a] * inv[b] % mod * inv[a - b] % mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int k;
	cin >> k;
	bas[0] = 1;
	rep(i, 1, k + 2) bas[i] = bas[i - 1] * 2;
	/*rep(i, 0, k + 1) {
		cout << i << " " << bas[i] << endl;
	}*/
	A[1] = 1;
	inv[1] = qpow(1, mod - 2);
	A[0] = 1;
	inv[0]= 1;
	rep(i, 2, bas[k + 1] + 1) {
		A[i] = A[i - 1] * i % mod;
		inv[i] = inv[i - 1] * qpow(i, mod - 2) % mod;
	}
	rep(i, 1, bas[k] + 1) cin >> a[i];
	//rep(i, 1, bas[k] + 1) cout << a[i] << " " ;
	//cout << endl;
	//cout << bas[k] << "  " << A[k] << " " << inv[k] << endl;
	ll ans = 0;
	per(i, 1, k + 1){
		per(j, 1, bas[k] + 1){
			ll res = A[bas[k - i]] * A[bas[k - i]] % mod * A[bas[k] - 2 * bas[k - i]] % mod * bas[i] % mod  * get(bas[k] - j - bas[k - i], bas[k - i] - 1)% mod;
			ans = (ans + res * a[j] % mod * sum[j + 1] % mod) % mod;
			//cout << res << endl;
			sum[j] = (sum[j + 1] + get(bas[k] - j,bas[k - i] - 1) * a[j] % mod) % mod;
			//cout << j << " " << bas[k] - j << " " <<  bas[k - i] << " "<<sum[j] << endl;
		}
	}
	cout << ans * inv[bas[k]] % mod << endl;
	return 0;
}