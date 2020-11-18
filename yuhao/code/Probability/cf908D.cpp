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
ll mod = 1e9 + 7;
ll dp[1010][1010];
ll a, b, k;
ll qpow(ll a ,ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		b /= 2;
		a = a * a % mod;
	}
	return res;
}
ll solve(int i, int j){
	if(dp[i][j] != -1) return dp[i][j];
	if(i + j >= k) return dp[i][j] = (i + j + a * qpow(b, mod - 2)) % mod;
	return dp[i][j] = (a * solve(i + 1, j) % mod + b * solve(i, i + j) % mod) * qpow(a + b , mod - 2) %mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> k >> a >> b;
	cout << solve(1, 0) << endl;
	return 0;
}