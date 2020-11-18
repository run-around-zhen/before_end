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
ll dp[5];
const int mod = 1e9 + 7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	string s;
	cin >> s;
	dp[0] = 1;
	rep(i, 0, n){
		if(s[i] == 'c') dp[3] = (dp[3] + dp[2]) % mod;
		else if(s[i] == 'b') dp[2] = (dp[2] + dp[1]) % mod;
		else if(s[i] == 'a') dp[1] = (dp[1] + dp[0]) % mod;
		else{
			per(i, 1, 4) dp[i] = (3 * dp[i] + dp[i - 1]) % mod;
			dp[0] = 3 * dp[0] % mod;
		}
	} 
	cout << dp[3] << endl;
	return 0;
}