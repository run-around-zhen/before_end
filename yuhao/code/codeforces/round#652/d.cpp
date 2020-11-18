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
ll mod=1e9 + 7;
ll dp[4][2000000 + 10];
ll qpow(ll a, ll b){
	ll res = 1;
	if(b < 0) return 0;
	while(b){
		if(b & 1){
			res =res * a % mod;
		}
		b /= 2;
		a = a * a % mod;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);dp[1][1] = 1;
		dp[2][2] = 1;
		rep(i, 3, 2000000 + 10){
			dp[1][i] =  2 * dp[2][i - 1] % mod;
			dp[2][i] = (dp[1][i - 1] + dp[2][i - 1])% mod;
			dp[3][i] = dp[2][i - 1] % mod;
		}
		rep(i, 3, 2000000 + 10){
			dp[3][i] = (dp[3][i] + dp[3][i - 3]) % mod;
		}
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		
		cout << (dp[3][n] * 4 ) % mod<< endl;
	}
	/*cout << dp[1][4] << " " << dp[2][4] <<endl;
	cout << dp[1][3] << " " << dp[2][3] << endl;
	cout << dp[1][5] << " " << dp[2][5] << endl;*/
	return 0;
}