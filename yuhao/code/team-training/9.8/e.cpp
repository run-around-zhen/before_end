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
const int mod = 998244353;
const int MAXN = 1e5 + 10;
int num[MAXN + 10], cnt[MAXN + 10], inv[MAXN + 10];
vi v[MAXN + 10];
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
void init(){
	rep(i, 1, MAXN + 1){
		num[i] += i;
		inv[i] = qpow(i, mod - 2);
		for(int j = i; j <= MAXN; j += i){
			v[j].pb(i);
			if(j > i) num[j] -= num[i];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	init();
	while(T --){
		int n, m;
		cin >> n >> m;
		rep(i, 1, MAXN + 1) cnt[i] = 0;
		rep(i, 1, n + 1){
			int x;
			cin >> x;
			for(auto j:v[x]){
				cnt[j] ++;
			}
		}
		ll ans = 0;
		rep(i, 1, m + 1){
			ll tmp = 0;
			for(auto j: v[i]){
				tmp = (tmp + (qpow(i + 1, cnt[j]) - 1) * inv[i] % mod * num[j] % mod) % mod;
			}
			ans ^= tmp;
		}
		cout << ans << endl;
	}
	return 0;
}