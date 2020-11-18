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
double minn = 1e9;
double dp[3010][3010],a[3010],sum[3010];
int n, m;
double check(double k){
	memset(dp, 0, sizeof(dp));
	rep(i, 1, n + 1){
		dp[i][0] = 0;
		rep(j, 1, i){
			dp[i][j] = min( dp[i - 1][j], dp[i - 1][j - 1] + i * a[i] - sum[i] + sum[n] - sum[i] - ( n - i ) * a[i] - k);
		}
	}
	minn = 1e9;
	int pos = - 1;
	rep(i, 1, n + 1){
		if(dp[n][i] < minn){
			minn = dp[n][i];
			pos = i;
		}
	}
	return pos;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n + 1) sum[i] = a[i] + sum[i - 1];
	double l = 0, r = 1e9;
	double ans = 1e9;
	while( r - l >= 1e-9 ){
		double mid= (l + r) / 2;
		cout << mid << " " << check(mid) << endl;
		if(check(mid) > m){
			r = mid;
			ans = min(ans, mid);
		}
		else{
			ans = max(ans, mid);
			l = mid;
		}
	}
	cout << ans << endl;
	cout << check(ans) * m + ans << endl;
	return 0;
}