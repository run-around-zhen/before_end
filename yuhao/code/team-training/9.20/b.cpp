#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(ll i=(a); i<(b); i++)
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
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a;
		}
		b /= 2;
		a = a * a;
	}
	return res;
}
typedef __uint128_t returnT;
typedef unsigned long long argT;
struct Min_25{
	static const argT N = 1e6 + 7;
	argT Sqr, m, id1[N], id2[N], tot, cntp;
	argT p[N];
	returnT g[N], h[N], n, w[N];
	argT sp[N];
	bool isp[N];
	int f(int p) {
		return p;
	}
	// ll F(int p, int e) {
	// 	return e == 1 ? -1 : 0;
	// }
	returnT calc(returnT n){
		return (1+n)*n/2-1 ;
	}
	void prime(argT n){
		cntp = 0;
		isp[1] = 1;
		rep(i, 2, n + 1){
			if(!isp[i]) p[++ cntp] = i;
			for(argT j = 1; j <= cntp && i * p[j] <= n; j ++){
				isp[i * p[j]] = 1;
				if(i % p[j] == 0) break;
			}
		}
		rep(i, 1, cntp + 1){
			sp[i] = sp[i - 1] + p[i];
		}
		p[++cntp]=INT_MAX;
	}
	returnT solve(ll _n){
		n = _n;
		if(n == 0) return  0;
		m = 0;
		Sqr = sqrt((ll)n);
		//cout << Sqr << endl;
		tot = upper_bound(p + 1, p + cntp + 1, Sqr) - (p + 1);
		for(argT i = 1, j;i <= n; i = j + 1){
			j = n / (n / i);
		 	w[++m] = n / i;
		 	g[m] = calc(w[m]);
		 	w[m] <= Sqr ? id1[w[m]] = m : id2[j] = m;
		 }
		 rep(j, 1, tot + 1){
		 	for(argT i = 1; i <= m && p[j] * p[j] <= w[i]; i++){
		 		argT t = w[i] / p[j];
		 		argT k = t <= Sqr ? id1[t] :id2[n / t];
		 		g[i] -= p[j] * (g[k] - sp[j - 1]);
		 	}

		 }
		return g[1];
	}
}_U;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	_U.prime(1000000);
	cin >> T;
	//T = 50;
	while(T --){
		ll n, mod;
		cin >> n >> mod;
		//n = 10000000000;
		//mod = 998244353;
		cout << (int)((_U.solve(n + 1)  + (__int128)n *(3 + n)/2-4)%mod) << endl;
	}
	return 0;
}