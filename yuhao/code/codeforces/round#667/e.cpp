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
int n, k;
int dp[2000000 + 10];
int x[2000000 + 10], y[2000000 + 10];
int cal(int pos, int n, int k){
	if(x[pos] + k >= x[n]) return n;
	int l = pos, r = n;
	while(l < r){
		int m = (l + r) / 2 + 1;
		if(x[m] > x[pos] + k){
			r = m - 1;
		}
		else l = m;
	}
	return l;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		cin >> n >> k;
		rep(i, 1, n + 1) cin >> x[i];
		rep(i, 1, n + 1) cin >> y[i];
		rep(i, 0, n + 1) dp[i] = 0;
		sort(x + 1, x + 1 + n);
		int res = 0;
		rep(i, 1, n + 1){
			
			dp[i] = max(dp[i], dp[i - 1]);
			int use = cal(i, n, k);
			res = max(res, dp[i] + use - i + 1);
			if(use + 1 <= n) dp[use + 1] = max(dp[use + 1], use - i + 1);
		}
		cout << res << endl;
	}
	return 0;
}