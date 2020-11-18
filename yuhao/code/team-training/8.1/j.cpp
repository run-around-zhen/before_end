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
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	ll n, k;
	cin >> n >> k;
	/*ll ans = n;
	rep(i, 2, k + 1){
		ans += (n - 1) / i + n / i + 1;
	}
	cout << ans << endl;*/
	ll res = n % mod;
	for(ll l = 2,r;l <= min(n ,k); l = r + 1){
    	ll d = n / l;
   		r = n / d;
   		//cout << l << " " << r << endl;
   		res += (min(k, r) - l + 1) % mod  * (n / l) % mod;
   		res %= mod;
	}
	//cout << res << endl;
	n --;
	for(ll l = 2,r;l <= min(n, k); l = r + 1){
    	ll d = n / l;
   		r = n / d;
   		res += (min(k, r) - l + 1)% mod* (n / l) % mod;
   		res %= mod;
	}
	cout << (res  + k - 1) % mod<< endl;
	return 0;
}