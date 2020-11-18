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
ll mod = 998244353;
ll A[4000000 + 10];
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a  %mod;
		}
		b /= 2;
		a = a * a % mod;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	A[0] = 1;
	rep(i, 1, 3000000 + 10) {
		A[i] = A[i - 1] * i % mod;
	}
	int n;
	while(cin >> n){
		//cout << n << endl;
	//	cout << A[n * 2 + 1] << endl;
		//cout << A[n * 2 + 1] * qpow(A[n], mod - 2) % mod * qpow(A[n], mod - 2) % mod<< endl;
		cout << qpow(A[n * 2 + 1] * qpow(A[n], mod - 2) % mod * qpow(A[n], mod - 2)% mod, mod - 2) << endl;
	}
	return 0;
}