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
ll a[1000000 + 10], dp[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		rep(i, 1, n + 1) cin >> a[i];
		sort(a + 1, a + 1 + n);
		dp[4] = a[4] - a[1];
		dp[6] = a[6] - a[1];
		for(int i = 8; i <= n; i += 2){
			dp[i] = min(dp[i - 4] + a[i] - a[i - 3], dp[i - 6] + a[i] - a[i - 5]);
		}
		cout << dp[n] * 2 << endl;
		cout << (a[n] - a[1]) * 2 << endl;
	}
	return 0;
}