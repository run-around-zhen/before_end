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
vi v;
map<int, int >ma;
ll mod = 1e9 + 7;
ll mod1 = 998244353;
int a[1000000 + 10];
ll qpow(ll a, ll b ,ll mod2){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod2;
		}
		b /= 2;
		a = a * a % mod2;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, p;
		v.clear();
		ma.clear();
		cin >> n >> p;
		int maxn = 0;
		rep(i, 1, n + 1) {
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n);
		ll ans = 0, res = 0;
		for(int  i = n ; i >= 1; i -- ){
			if(res == 0) {
				ans = (ans + qpow(p, a[i], mod)) % mod;
				res = (res + qpow(p, a[i], mod1)) % mod1;
			}
			else {
				ans = (ans - qpow(p, a[i],mod) + mod) % mod;
				res = (res - qpow(p, a[i], mod1) + mod1) % mod1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}