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
int dp[200000 + 10][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		string s;
		cin >> s;
		int ans = 1e9;
		rep(i, 0, 10){
			rep(j, 0, 10){
				rep(k, 0, s.size()) dp[k][0] = dp[k][1] = 0;
				rep(k, 0, s.size()){
					if(k == 0){
						if(s[k] - '0' == i) dp[k][0] = 1;
						if(s[k] - '0' == j) dp[k][1] = 1;
					}
					else{
						if(s[k] - '0' == i) dp[k][0] = dp[k - 1][1] + 1;
						else dp[k][0] = dp[k - 1][0];
						if(s[k] - '0' == j) dp[k][1] = dp[k - 1][0] + 1;
						else dp[k][1] = dp[k - 1][1];
					}
				}
				int now = max(dp[s.size() - 1][0], dp[s.size() - 1][1]);
				if(i != j && now % 2 == 1) now --;
				ans = min(ans, (int)s.size() - now);
			}
		}
		cout << ans << endl;
	}
	return 0;
}