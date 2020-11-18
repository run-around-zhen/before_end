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
int dp[100000 + 10], a[100000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		rep(i, 1, n + 1) {
			cin >> a[i];
			dp[i] = -1e9;
		}
		rep(i, 1, n + 1){
			int t = a[i];
			rep(j, 1, 10){
				if(i - j < 1) break;
				t *= a[i - j];
				dp[i] = max(dp[i], dp[i - j - 1] + t);
			}
			if(i >= 2) dp[i] = max(dp[i], dp[i - 2] + a[i - 1] * a[i]);
			if(i >= 3) dp[i] = max(dp[i], dp[i - 3] + a[i - 2] * a[i - 1] * a[i]);
			dp[i] = max(dp[i], dp[i - 1] + a[i]);
		}
		cout << dp[n] << endl;
	}
	return 0;
}