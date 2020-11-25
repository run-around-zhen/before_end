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
int a[1000000 + 10];
int ans[1000000 + 10];
int dp[3][1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n + 1){
		ans[1] = max(ans[1], a[i]);
	}
	rep(i, 1, n){
		dp[1][min(i, n - i)] = max(dp[1][min(i, n - i)], max(a[i], a[i + 1]));
	}
	rep(i, 2, n){
		dp[2][min(i - 1, n - i)] = max(dp[2][min(i - 1, n - i)], max(min(a[i - 1], a[i]), min(a[i], a[i + 1])));
	}
	per(i, 1, n / 2 + 1){
		ans[i * 2] = max(ans[(i + 1) * 2], dp[1][i]);
		ans[i * 2 + 1] = max(ans[(i + 1) * 2 + 1], dp[2][i]);
	}
	per(i, 1, n + 1){
		cout << ans[i] << " ";
	}
	return 0;
}