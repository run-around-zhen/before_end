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
const int mod = 1000000009;
ll dp[1010][1010][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int k, b;
	cin >> k >> b;
	dp[0][0][0] = 1;
	dp[0][0][1] = 0;
	rep(i, 1, b + 1){
		rep(j, 0, k){
			dp[i][(j * 2) % k][0] = (dp[i][(j * 2) % k][0] + dp[i - 1][j][0]) % mod;
			dp[i][(j * 2 + 1) % k][0] = (dp[i][(j * 2 + 1) % k][0] + dp[i - 1][j][0]) % mod;
			dp[i][(j * 2) % k][1] = (dp[i][(j * 2) % k][1] + dp[i - 1][j][1]) % mod;
			dp[i][(j * 2 + 1) % k][1] = (dp[i][(j * 2 + 1) % k][1] + dp[i - 1][j][1] + dp[i - 1][j][0]) % mod;
		}
	}
	cout << dp[b][0][1];
	return 0;
}