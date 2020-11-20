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
const int mod = 1e9 + 7;
int dp[220][220];
int add(int a, int b){
	if(a + b >= mod){
		return a + b - mod;
	}
	return a + b;
}
int mul(int a, int b){
	return (ll)a * b % mod;
}
struct point{
	ll x, y;
	ll operator * (const point& b) const{
        return x*b.y-y*b.x;
    }
    point operator - (const point& b) const {
        point p;
        p.x = x-b.x;
        p.y = y-b.y;
        return p;
    }
}a[1000000 + 10];
int dfs(int l, int r){
	if(dp[l][r] != -1) return dp[l][r];
	if(l == r - 1) return 1;
	dp[l][r] = 0;
	rep(i, l + 1, r){
		if((a[i] - a[l]) * (a[r] - a[l]) <= 0) continue;
 		dp[l][r]= add(mul(dfs(l, i), dfs(i, r)), dp[l][r]); 
	}
	return dp[l][r];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	ll s = 0;
	rep(i, 1, n + 1){
		cin >> a[i].x >> a[i].y;
		s += a[i] * a[i - 1];
	}
	s += a[1] * a[n];
	if(s > 0) reverse(a + 1, a + 1 + n);
	memset(dp, -1, sizeof(dp));
	dfs(1, n);
	cout << dp[1][n] << endl;
	return 0;
}