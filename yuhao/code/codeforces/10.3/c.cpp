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
const int mod = 998244353;
map<int, int> cnt;
ll dp[1010][1010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, k;
	cin >> n >> k;
	rep(i, 1, n + 1) {
		int x;
		cin >> x;
		cnt[x] ++;
	}
	rep(i, 0, n + 1) dp[i][0] = 1;
//	dp[0][0] = 1;
	int  now = 0;
	for(auto  i : cnt){
		now ++ ;
		rep(j, 1, k + 1){
			dp[now][j] = (dp[now][j] + (dp[now - 1][j - 1] * i.se % mod)) % mod;
			dp[now][j] = (dp[now][j] + dp[now - 1][j]) % mod;
			//cout <<now << " " << j << " "  << dp[now - 1][j - 1] << " " << i.se << endl;
		}
	}
	cout << dp[now][k] << endl;
	return 0;
}