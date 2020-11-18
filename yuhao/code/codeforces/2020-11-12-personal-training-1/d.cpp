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
const int mod = 1e9 + 7;
int fac[1000000 + 10], ifac[1000000 + 10];
int add(int a ,int  b){
	if(a + b >= mod) return a + b - mod;
	return a + b;
}
int mul(int a, int b){
	return (ll)a * b % mod;
}
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
int get(int a, int b){
	return mul(mul(fac[a], ifac[a - b]), ifac[b]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, m, g;
	cin >> n >> m >> g;
	if(m == 0){
		if(g == 0){
			if(n % 2 == 1){
				cout << "1" << endl;
			}
			else{
				cout << "0" << endl;
			}
		}
		else{
			if(n % 2 == 1){
				cout << "0" << endl;
			}
			else{
				cout << "1" << endl;
			}
		}
		return 0;
	}
	if(n == 0){
		if(g == 0){
			if(m == 1){
				cout << "0" << endl;
			}
			else{
				cout << "1" << endl;
			}
		}
		else{
			if(m == 1){
				cout << "1" << endl;
			}
			else{
				cout << "0" << endl;
			}
		}
		return 0;
	}
	fac[0] = ifac[0] = 1;
	rep(i, 1, n + m + 1){
		fac[i] = mul(fac[i - 1], i);
		ifac[i] = qpow(fac[i], mod - 2);
	}
	int ans = 0;
	rep(i, 0, n + m + 1){
		if(n + m - 2 * i - 1 < 0) break;
		if(n - 2 * i < 0) break;
		ans = add(ans, get(n + m - 2 * i - 1, n - 2 * i));
	}
//	de(ans);
	if(m == 1){
		if(n % 2 == 1) ans = add(ans, 1);
		else ans = add(ans, -1);
	}
//	de(ans);
	if(g == 0) cout << ans << endl;
	else {
		cout << add(get(n + m, n), - ans + mod) << endl; 
	}
	return 0;
}