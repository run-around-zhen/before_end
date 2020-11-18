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
ll qpow(ll a, ll b){
	if(a == 0) return 0;
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	rep(cas, 1, T + 1){
		ll n, m, k;
		cin >> n >> m >> k;
		ll ans = qpow(k, n * m);
		//cout << ans << endl;
		//ans %= mod;
		cout <<"Case #" << cas << ": " ;
		rep(i, 1, k + 1){
			ans = (ans + qpow(i - 1, n + m - 2) * n % mod * m % mod * qpow(k, n * m - (n + m - 1))) % mod;
		}
		cout << ans << endl;
	}
	return 0;
}