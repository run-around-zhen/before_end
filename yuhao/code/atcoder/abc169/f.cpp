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
ll dp[3010][3010];
ll mod = 998244353;
ll a[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, k;
	cin >> n >> k;
	dp[0][0] = 1;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n + 1){
		rep(j, 0, 3001){
			if(j >= a[i]) dp[i][j] = (dp[i - 1][j] * 2 + dp[i - 1][j - a[i]]) % mod ;
			else dp[i][j] = (dp[i - 1][j] * 2) % mod;
		}
	}
	ll ans = 0;
	cout << dp[n][k];
	return 0;
}