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
ll dp[310][310], b[310][310];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, m, k1;
	cin >> n >> m >> k1;
	rep(i, 1, n + 1){
		rep(j, 1, n + 1) b[i][j] = dp[i][j] = 1e18;
	}
	rep(i, 1, m + 1){
		int l, r, cost;
		cin >> l >> r >> cost;
		rep(j, l, r + 1){
			b[j][r] = min(b[j][r], 1ll*cost);
		}
	}
	rep(i, 0, n + 1) dp[i][0] = 0;
	rep(i, 1, n + 1){
		rep(j, 0, i + 1){
			rep(k, j, i + 1) dp[i][j] = min(dp[i][j], dp[k][j]);
			rep(k, 1, n + 1){
				int tmp = i - k + 1;
				//dd(i);dd(j);dd(k);dd(tmp);
				if(j - tmp < 0) continue;
				dp[i][j] = min(dp[i][j], dp[k - 1][j - tmp] + b[k][i]);
				//dd(i);dd(j);dd(k);de(dp[i][j]);
			//	de(b[k][i]);
		//	dd(i);dd(j);dd(k - 1);dd(j - tmp); de(dp[k - 1][j - tmp]);
			}
			dp[i + 1][j] = dp[i][j];
		}
	}
	/*rep(i, 1, n + 1) {
		rep(j, 1, n + 1){
			de(dp[i][j]);
		}
	}*/
	if(dp[n][k1] != 1e18) cout << dp[n][k1] << endl;
	else cout << "-1" << endl;
	return 0;
}