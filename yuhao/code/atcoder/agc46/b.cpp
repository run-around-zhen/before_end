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
ll mod = 998244353;
ll dp[3030][3030];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int n = c - a + 1;
	int m = d - b + 1;
	//cout << n <<  " " << m << endl;
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			if(i == 1 && j == 1) dp[i][j] = 1;
			else{
				dp[i][j] = (dp[i - 1][j] * (j + b - 1) + dp[i][j - 1] * (i + a - 1) - dp[i - 1][j - 1] * (j - 1 + b - 1) % mod * (i - 1 + a - 1) % mod  + mod) % mod;
			}
			//cout << i << " " << j << " " << dp[i][j]<< endl;
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}