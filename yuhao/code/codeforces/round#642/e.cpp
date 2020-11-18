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
int sum[1000000 + 10];
int dp[1000000 + 10][3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		int ans = n;
		string s;
		cin >> s;
		int len = s.size();
		rep(i, 0, len){
			if(s[i] == '1') sum[i] = 1;
			if(i > 0) sum[i] +=sum[i - 1];
		}
		rep(i, 0, k){
			for(int j = i; j < len; j += k){
				dp[j][0] = sum[min(len - 1, j + k - 1)];
				dp[j][2] = dp[j][0];
				int res = 0;
				if(s[j] != '1') res ++;
				res += sum[min(len - 1, j + k - 1)] - sum[j];
				if(j >= k) {
					dp[j][1] = res + min(dp[j - k][0], dp[j - k][1]);
					dp[j][2] = min(dp[j][2], dp[j - k][1] + sum[min(len - 1, j + k - 1)] - sum[j - 1]);
					dp[j][2] = min(dp[j][2], dp[j - k][2] + sum[min(len - 1, j + k - 1)] - sum[j - 1]);
				} 
				else {
					if(j > 0) dp[j][1] = res + sum[max(j - 1, 0)];
					else dp[j][1] = res;
					dp[j][2] = dp[j][0];
				}
			//	cout << dp[j][0] << " " <<dp[j][1] <<" " <<dp[j][2] << " "<< j <<endl;
				if(j + k >= len) {
					ans = min(ans,dp[j][0]);
					ans = min(ans, dp[j][1]);
					ans = min(dp[j][2], ans);
				//	cout << "!!!" <<endl;
				}
			}
			//cout << res << endl;
		} 
		cout << ans << endl;
		rep(i, 0, len) sum[i] = 0;
		rep(i, 0, len){
			dp[i][0] = 0;
			dp[i][1] = 0;
			dp[i][2] = 0;
		}
	}
	return 0;
}