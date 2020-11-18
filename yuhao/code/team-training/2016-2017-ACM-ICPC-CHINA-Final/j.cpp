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
#define rint register int
#define inv inline void
#define ini inline int
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll get(int i, int j){
	return (ha[j] - ha[i - 1] + mod) % mod * inv[i - 1] % mod; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	bas[0] = 1;
	rep(i, 1, n + 1){
		hash[i] = (hash[i - 1] + bas[i - 1] * (s[i] - 'a' + 1)) % mod;
		bas[i] = bas[i - 1] * 29 % mod;
		inv_bas[i] = qpow(bas[i], mod - 2);
	}
	return 0;
}