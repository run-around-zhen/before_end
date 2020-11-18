#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(ll i=(a); i<(b); i++)
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
ll dp[1010][110][2];
int flag[1010][110];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n, k, mod;
	cin >> n >> k >> mod;
	ll tmp = 1;
	rep(i, 0, 10){
		//flag[1][i % k] = true;
		if(i % k == 0 && i != 0) dp[1][i % k][1] += 1;
		else dp[1][i % k][0] += 1;
	}
	//cout << dp[1][0][0] << endl;
	/*rep(i, 2, n + 1){
		rep(j, 0, 10){
			if(i == n && j == 0 ) continue;
			rep(t, 0, k){
			//	if(!flag[i - 1][t]) continue;
				int last = (tmp  * j % k + t) % k;
				//cout << last << endl;
				dp[i][last] = (dp[i - 1][t] + dp[i][last]) % mod;
			//	flag[i][last] = true;
			}
		}
		tmp = tmp * 10 % k;
	}*/
	/*rep(i, 0, k){
		cout << dp[1][i][0] << " " << dp[1][i][1] << endl;
	}*/
	rep(i, 2, n + 1){
		tmp = tmp * 10 % k;
		rep(j, 0, 10){
			if(i == n && j == 0 ) continue;
			rep(t, 0, k){
				ll last = (tmp  * j % k + t) % k;
				//cout << last << endl;
				if(last == 0) {
					if(j != 0){
						dp[i][last][1] = (dp[i - 1][t][0] + dp[i - 1][t][1] + dp[i][last][1]) % mod;
						//dp[i][last][0] = (dp[i][last][0] + dp[i - 1][t][0]) % mod;
					}
					else{
						dp[i][last][0] = (dp[i - 1][t][0] + dp[i][last][0]) % mod;
						dp[i][last][1] = (dp[i][last][1] + dp[i - 1][t][1]) % mod;
						//cout << "??" << endl;
					}
				}
				else {
					dp[i][last][0] = (dp[i - 1][t][0] + dp[i][last][0]) % mod;
					dp[i][last][1] = (dp[i - 1][t][1] + dp[i][last][1]) % mod;
					//cout << j << " " <<last <<" " << t << " " << dp[i - 1][t][1] << endl;
				}
			//	flag[i][last] = true;
			}
		}
		
	}
	ll ans = 0;
	rep(i, 0, k){
		ans = (ans + dp[n][i][1]) % mod;
		//cout << dp[n][i][0] <<" " << dp[n][i][1] << endl;
	}
	cout << ans << endl;
	//cout << dp[n][0][1] << endl;
	return 0;
}