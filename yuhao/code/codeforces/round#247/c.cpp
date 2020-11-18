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
ll dp[110][110];
ll mod = 1e9 + 7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, k, d;
	cin >> n >> k >> d;
	dp[0][0] = 1;
	rep(i, 1, n + 1){
		rep(j, 1, k + 1){
			if(i < j) continue;
			if(j >= d){
				dp[i][1] = (dp[i - j][0] + dp[i][1]) % mod;
				dp[i][1] = (dp[i - j][1] + dp[i][1]) % mod;
			}
			else{
				dp[i][0] = (dp[i - j][0] + dp[i][0]) % mod;
				dp[i][1] = (dp[i - j][1] + dp[i][1]) % mod;
			}
		}
	}
	cout << dp[n][1] << endl;
	return 0;
}