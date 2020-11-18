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
int dp[100][100][6400 + 10];
int a[1000000 + 10];
vi v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		cin >> a[i];
		if(a[i] == 1) v.pb(i);
	}
	rep(i, 0, 90){
		rep(j, 0, 90){
			rep(k, 0, 6405) dp[i][j][k] = 1e9;
		}
	}
	dp[0][0][0] = 0;
	rep(i, 1, (int)v.size() + 1){
		rep(j, 1, n + 1){
			int c= abs(v[i - 1] - j);
			rep(t, 0, j){
				rep(k, c, n * (n - 1) / 2 + 1){
					//if(k >= abs(v[i - 1] - j))
					dp[i][j][k] = min(dp[i][j][k], dp[i - 1][t][k - abs(v[i - 1] - j)] + (j - t - 1) * (j - t - 2) / 2);
				}
			}
		}
	}
	int tot = v.size();
	int res = n * (n - 1) / 2 -  tot* (tot - 1) / 2 - tot * (n - tot);
	int MAXN = 0;
	rep(i, 0, n * (n - 1) / 2 + 1){
		int ans = 1e9;
		rep(j, 1, n + 1){
			ans = min(ans, dp[v.size()][j][i]+(n-j)*(n-j-1)/2);
		}
		cout << max(MAXN, res - ans) << " ";
		MAXN = max(MAXN, res - ans);
	}
	return 0;
}