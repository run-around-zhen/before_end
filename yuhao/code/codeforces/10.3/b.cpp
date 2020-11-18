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
ll dp[10000000 + 10];
ll solve(ll a, ll b){
	if(a < b) swap(a, b);
	if(b == 0) return 0;
	per(i, 1, a + 1){
		dp[i] = (a / i) * (b / i); 
		for(int j = i + i ;j <= a; j += i){
			dp[i] -= dp[j];
		}
	}
	return dp[1];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	//cout << solve(d, b) << endl;
	cout << solve(d, b) - solve(d, a - 1) - solve(b, c - 1) + solve(a - 1, c - 1)<< endl;
	return 0;
}