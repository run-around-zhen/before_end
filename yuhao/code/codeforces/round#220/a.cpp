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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;
	cin >> s;
	rep(i, 0, s.size()){
		if(i) {
			if(s[i] - '0' + s[i - 1] - '0' == 9){
				dp[i][1] = dp[i - 1][0];
			}
			dp[i][0] = dp[i - 1][1] + dp[i - 1][0]; 
		}
		else{
			dp[i][0] = 1;
		}
	}
	cout << dp[n][0] + dp[n][1]
	return 0;
}