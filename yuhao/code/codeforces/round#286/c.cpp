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
int dp[1110][30000 + 10];
int dir[3] = {1, 0, -1};
int vis[300000 + 10];
int a[30000 + 10];
int n, d;
bool check(int i, int j){
	if(i < 100 || i > 1001 || j < 0 || j > 30000) return false;
	if(dp[i][j] != -1) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> d;
	memset(dp, -1, sizeof(dp));
	rep(i, 1, n + 1) {
		cin >> a[i];
		vis[a[i]] ++;
	}
	int minn = d, maxn = d;
	dp[550][d] = vis[d];
	int ans = vis[d];
	int tmp_min = 0;
	int tmp_max = 0;
	rep(i, d + 1, 30001){
		//cout << i << " " << minn << " " << maxn << endl;
		rep(j, 100, 1000 + 1){
			rep(k, 0, 3){
				int tmp = j  + dir[k];
				int tt = j - 550 + d;
				if(tt == 0) continue;
				if(check(tmp, i - tt)){
					dp[j][i] = max(dp[j][i], dp[tmp][i - tt] + vis[i]);
				}
				ans = max(ans, dp[j][i]);

			}
		}

	}
	cout << ans << endl;
	return 0;
}