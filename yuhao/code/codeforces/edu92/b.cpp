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
int a[1000000 + 10], sum[1000000 + 10];
int dp[2][1000000][10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n, xx, z;
		cin >> n >> xx >> z;
		rep(i, 1, n + 1) {
			cin >> a[i];
		}
		dp[0 & 1][1][0] = a[1];
		int res = a[1];
		rep(i, 1, xx + 1){
			int aa  = i + 1, bb = max(1, 1 + i - 2 * z);
			rep(j, bb, aa + 1){
				rep(k, 0, z + 1){
					dp[i&1][j][k] = dp[(i+1)&1][j-1][k] + a[j];
					if(k) dp[i&1][j][k]=max(dp[i & 1][j][k],dp[(i+1) & 1][j+1][k-1]+a[j]);
					res = max(res,dp[i&1][j][k]);
					//cout << res << endl;
				}
			}
		}
		rep(i, 0, n + 1){
			rep(j, 0, z + 1) dp[0][i][j] = dp[1][i][j] = 0;
		}
		cout << res << endl;
	}
	return 0;
}