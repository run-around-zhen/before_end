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
ll a[110][110],dp[110][110];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n, m;
		cin >> n >> m;
		rep(i, 1, n + 1){
			rep(j, 1, m + 1) {
				cin >> a[i][j];
				//b[i][j] = a[i][j];
			}
		}
	/*	rep(i, 0, n + 1) {
			a[i][0] = inf;
			a[0][i] = inf;
		}
		ll ans = 0;*/
		ll res = 4e18;
		rep(i, 1, n + 1){
			rep(j, 1, m + 1){
				rep(k, 0, n + 1){
					rep(t, 0, m + 1) dp[k][t] = 2e18;
				}
				ll cost = a[i][j] - (i + j - 2);
				rep(k, 1, n + 1){
					rep(t, 1 , m + 1){
						if(a[k][t] - (k + t - 2) < cost) continue;
						if(k == 1 && t == 1 ) dp[k][t] = a[k][t] - (k + t - 2) - cost;
						else dp[k][t] = min(dp[k][t - 1], dp[k - 1][t]) + a[k][t] - (k + t - 2) - cost;
					}
				}
				/*cout << cost << endl;
				rep(k ,1 , n + 1){
					rep(t, 1 ,m + 1){
						cout << dp[k][t] << " ";
					}
					cout << endl;
				}*/
				res = min(res, dp[n][m]);
			}
		}
		cout << res << endl;
	}

	
	return 0;
}