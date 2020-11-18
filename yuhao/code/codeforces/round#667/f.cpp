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
int n, op;
string s, t;
int dp[2][210][210][210];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> op;
	cin >> s >> t;
	if(t[0] == t[1]){
		int sum = 0;
		rep(i, 0, s.size()){
			if(s[i] == t[0]) sum ++;
		}
		int maxn = min(n, sum + op);
		cout << maxn * (maxn - 1) / 2 << endl;
		return 0;
	} 
	memset(dp, -1, sizeof(dp));
	dp[0][0][0][0] = 0;
	int ans = 0;
	rep(i, 1, n + 1){
		rep(j, 0, n + 1){
			rep(k, 0, n + 1){
				if(j + k > n) break;
				rep(q, 0, op + 1){
					ans = max(ans, dp[i & 1][j][k][q]);
					if(dp[(i - 1) & 1][j][k][q] == - 1) continue;
					
					if(s[i - 1] == t[0]){
						dp[i & 1][j + 1][k][q] = max(dp[(i - 1) & 1][j][k][q], dp[i & 1][j + 1][k][q]);
						dp[i & 1][j][k + 1][q + 1] = max(dp[(i - 1) & 1][j][k][q] + j, dp[i & 1][j][k + 1][q + 1]);
					}
					else if(s[i - 1] == t[1]){
						dp[i & 1][j + 1][k][q + 1] = max(dp[(i - 1) & 1][j][k][q], dp[i & 1][j + 1][k][q + 1]);
						dp[i & 1][j][k + 1][q] = max(dp[(i - 1) & 1][j][k][q] + j, dp[i & 1][j][k + 1][q]);
					}
					else{
						dp[i & 1][j + 1][k][q + 1] = max(dp[(i - 1) & 1][j][k][q], dp[i & 1][j + 1][k][q + 1]);
						dp[i & 1][j][k + 1][q + 1] = max(dp[(i - 1) & 1][j][k][q] + j, dp[i & 1][j][k + 1][q + 1]);
					}
					dp[i & 1][j][k][q] = max(dp[i & 1][j][k][q], dp[(i - 1)& 1][j][k][q]);
					//cout << (i & 1) << "  "<< i << " " <<j << " " << k << " " << q << " " << dp[(i - 1) & 1][j][k][q] << endl;

				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*
5 1
aabax
ac
*/