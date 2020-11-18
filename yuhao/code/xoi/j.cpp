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
	ll n,mod;
	cin >> n >> mod;
	ll sum = 0;
	ll ans =0;
	for(ll l=1,r;l<=n;l=r+1){
        if(n/l!=0){
        	r=n/(n/l);
			if(r>n){
				r=n;
			}
		}
        else r=n;
        ll k;
        if( (r - l + 1) % 2== 0 ) k = ((r -l + 1)/2)%mod*((r+l)%mod)%mod;
        else k=((r+l)/2)%mod*((r-l+1)%mod)%mod; 
        ll len = (r-l+1)%mod;
        ans = ( ans + n %mod *( (n / l)%mod) %mod * len ) % mod;
        sum = ( sum + ( n / l ) % mod * ( ( n / l) % mod ) % mod * k ) % mod ;
    }
    //cout << ans <<" " << sum <<endl;
    cout << (ans - sum + mod)%mod;
	return 0;
}