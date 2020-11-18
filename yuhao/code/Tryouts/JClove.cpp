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
ll mod = 1e9 + 7;
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		b /= 2;
		a = a * a % mod;
	}
	return res;
}
ll inv = qpow(2, mod - 2);
string s, t;
ll sum1 = 0, sum2 = 0;
ll get(int i, int j){
	ll a1 = (sum1 - (s[i] - '0') + mod) % mod * inv;
	ll b1 = (sum1 - (s[i] - '0') + mod) % mod * inv + s[i] - '0';
	ll a2 = (sum2 - (t[j] - '0') + mod) % mod * inv;
	ll b2 = (sum2 - (t[j] - '0') + mod) % mod * inv + t[j] - '0';
	a1 %= mod;
	b1 %= mod;
	a2 %= mod;
	b2 %= mod;
	//cout << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
	return (a1 * b2 + b1 * a2) % mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	
	cin >> s >> t;	
	rep(i, 0, s.size()){
		sum1 = sum1 * 2 + s[i] - '0';
	}
	rep(i, 0, t.size()){
		sum2 = sum2 * 2 + t[i] - '0';
	}
	ll ans = 0;
	int i = s.size() - 1;
	int j = t.size() - 1;
	while(i >= 0 && j >= 0){
		ans = (ans + get(i, j)) % mod;
		cout << sum1 << " " << sum2 << endl;
		sum1 = (sum1 - (s[i] - '0') + mod) % mod * inv;
		sum2 = (sum2 - (t[j] - '0') + mod) % mod * inv;
		//cout << ans << endl;
		i --;
		j --;
		sum1 %= mod;
		sum2 %= mod;
		cout << ans << endl;
	}
	//cout << ans << endl;
	return 0;
}