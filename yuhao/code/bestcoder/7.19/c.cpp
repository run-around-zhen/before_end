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
int a[1010][1010], dp[1010][1010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	rep(i, 1, 1001){
		rep(j, 1, 1001){
			if(__gcd(i, j) == 1) a[i][j] = 1;
			//a[i][j] += a[i][j - 1];
		}
	}
	rep(i, 1, 1001){
		rep(j, 1, 1001) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
			dp[i][j] = max(dp[i][j], dp[i][j -1] + a[i][j]);
		}
	}
	int T;
	cin >> T;
	while(T --){
		int x, y;
		cin >> x >> y;
		cout << dp[x][y] << endl;
	}
	return 0;
}