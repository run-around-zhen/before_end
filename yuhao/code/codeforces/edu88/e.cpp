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
ll mod = 998244353;
ll A[1000000 + 10];
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
ll c(int a, int b){
	return A[a] * qpow(A[b], mod - 2) % mod * qpow(A[a - b], mod - 2) % mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, k;
	cin >> n >> k;
	A[1] = 1;
	A[0] = 1;
	rep(i, 2, n + 1) A[i] = A[i - 1] * i % mod;
	ll ans = 0;
	rep(i, 1, n + 1){
		int tmp = n / i;
		if(tmp < k) break;
		ans = (ans + c(tmp - 1, k - 1)) % mod ;
	}
	cout << ans % mod;
	return 0;
}