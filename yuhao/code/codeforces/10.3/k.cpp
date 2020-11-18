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
const int N = 2e7 + 10;
ll f[N], last[20], a[20];
int w[20], b[20];
vi v, num;
ll qpow(ll a, ll b, ll mod){
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
ll fast_qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a;
		}
		b >>= 1;
		a = a * a;
	}
	return res;
}
ll add(ll a, ll b, ll mod){
	if(a + b >= mod) return a + b - mod;
	return a + b;
}
ll mul(ll a, ll b, ll mod){
	return (ll) a * b % mod;
}
__int128 ext_gcd(__int128 a, __int128 b, __int128 &x, __int128 &y){
	__int128 t, d;
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	d = ext_gcd(b, a % b, x, y);
	t = x;
	x = y;
	y = t - a / b * y;
	return d;
}
__int128 china(int b[], int w[], int k){
	int i;
	__int128 d, x, y, a = 0, m, n = 1;
	for(i = 0; i < k; i ++) n *= w[i];
	for(i = 0; i < k; i ++){
		m = n / w[i];
		d = ext_gcd(w[i], m, x, y);
		a = (a + y * m * b[i]) % n;
	}
	if(a > 0) return a;
	else return (a + n);
}
ll get(ll i, int d, ll p){
	if(i == 0) return 1;
	return mul(get(i / d, d, p) ,mul(qpow(f[p], i / p, d), f[i % d], d), d);  
}
ll dfs(ll n, ll m, ll p, ll k){
	return mul(mul(get(n, p, k), qpow(get(m, p, k), k - 2, k), k), qpow(get(n - m, p, k), k - 2, k), k);
}
ll cal(ll a, ll p){
	ll res = 0;
	while(a){
		res += a / p;
		a /= p;
	}
	return res;
}
ll cal_num(ll n, ll m, ll p){
	return cal(n, p) - cal(m, p) - cal(n - m, p);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	ll n, m, d;
	cin >> n >> m >> d;
	ll D = d;
	for(int i = 2; i * i <= d; i ++){
		if(d % i == 0){
			int cnt = 0;
			while(d % i == 0){
				d /= i;
				cnt ++;
			}
			v.pb(i);
			num.pb(cnt);
		}
	}
	if(d != 1) {
		v.pb(d);
		num.pb(1);
	}
	ll k = 4e18;
	rep(i, 0, (int)v.size()){
		last[i] = cal_num(n, m, v[i]);
		a[i] = fast_qpow(v[i], num[i]);
		k = min(k, last[i] / num[i]);
	}
	rep(i, 0, (int)v.size()){
		f[0] = 1;
		b[i] = v[i];
		rep(j, 1, v[i] + 1){
			f[j] = f[j - 1];
			if(v[i] % j) f[j] = (ll)f[j - 1] * j % v[i]; 
		}
		w[i] = dfs(n, m, v[i], a[i]);
		w[i] = mul(mul(w[i], qpow(v[i], last[i] - num[i] * k, a[i]), a[i]), qpow(D / a[i], k, a[i]), a[i]); 
	}
	/*rep(i, 0, v.size()){
		cout << w[i] << "  " << b[i] << endl;
	} */
	ll ans = china(w, b, (int)v.size());
	cout << ans << endl;
	return 0;
}