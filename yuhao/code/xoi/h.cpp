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
ll dp[5010][5010];
ll mod = 998244353;
int main(){
	int n, k;
	cin >> n >> k;
	dp[1][1] = k;
	ll ans = 0;
	rep(i, 2, n + 1){
		rep(j, 2, k){
			dp[i][j] =( dp[i - 1][j - 1] * k ) % mod;
		}
		rep(j, 1, k) dp[i][1] = ( dp[i - 1][j] + dp[i][1] ) % mod;
	}
	rep(i, 1, k) ans = ( ans + dp[n][i] ) % mod;
	cout << ans << endl;
	return 0;
}