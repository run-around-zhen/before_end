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
ll qpow(ll a, ll b,ll mod){
	ll res =1 ;
	while(b){
		if(b&1){
			res = res *a %mod;
		}
		a= a* a%mod;
		b/=2;
	}
	return res;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	ll n, mod;
	cin >> n >> mod;
	ll ans =0 ;
	rep(i, 1, n + 1){
		ans = (ans + (n/i ) *(n-(n/i)*i))%mod;
	}
	cout << ans << endl;
}