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
ll dp[200][200];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	dp[1][0] = m;
	rep(i, 2, n + 1){
		dp[i][0] = dp[i - 1][0] * (m- 1)%mod;
		rep(j, 1, k + 1){
			dp[i][j] = ( dp[i - 1][j - 1] + (m - 1) * dp[i - 1][j] )%mod;
			cout << dp[i][j];
		}
	}
	ll ans = 0;
	rep(i, 0, k + 1){
		ans = (ans + dp[n][i] ) %mod;
	}
	cout << ans << endl;
	return 0;
}