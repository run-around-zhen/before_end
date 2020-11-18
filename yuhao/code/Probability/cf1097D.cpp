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
typedef vector<ll> vi;
ll dp[100+ 10][100 + 10];
vi p, v[100000 + 10];
ll inv[10000 + 10];
ll mod = 1e9 + 7;
map<ll, int> cnt;
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n, k;
	cin >> n >> k;
	for(ll i = 2; i * i <= n ; i ++){
		if(n % i == 0){
			p.pb(i);
			while(n % i == 0) {
				n /= i;
				cnt[i] ++ ;
			}
		}
	}
	if(n != 1) {
		p.pb(n);
		cnt[n] ++ ;
	}
	sort(all(p));
	rep(i, 0, p.size()){
		dp[i][cnt[p[i]]] = 1;
		//cout << i << "  " << p[i] << " " << cnt[p[i]] << endl;
	}
	rep(i, 1, 100) inv[i] = qpow(i, mod - 2);
	//dp[p.size() - 1] = 1;
	rep(i, 1, k + 1){
		rep(j, 0, p.size()){
			rep(t, 0, cnt[p[j]] + 1){
				dp[j][t] = dp[j][t] * inv[t + 1] % mod;
				rep(q, t + 1, cnt[p[j]] + 1){
					dp[j][t] = (dp[j][t] + dp[j][q] * inv[q + 1]) % mod;
				}
			}
		}
	}
	ll ans = 1;
	rep(i, 0, p.size()){
		ll tmp = 1;
		ll res = 0;
		rep(j, 0, cnt[p[i]] + 1) {
			res = (res + tmp * dp[i][j]) % mod;
			tmp = tmp * p[i] % mod;
		}
		ans = ans * res % mod; 
	}
	cout << ans << endl;
	return 0;
}