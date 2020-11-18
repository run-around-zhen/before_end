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
ll sum[1000000 + 10], a[1000000 + 10], dp[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, k;
	cin >> n >> k;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n + 1) sum[i] = sum[i - 1] + a[i];
	rep(i, 1, k + 1) dp[i] = dp[i - 1] + a[i];
	rep(i, k + 1, n + 1){
		dp[i] = sum[i] - sum[i - k];
	}
	ll ans = 0;
	ll maxn = dp[k - 1];
	int posa = 0, posb = 0;
	int pp = 1;
	rep(i, k, n + 1 - k){
		if(dp[i] > maxn) {
			maxn = dp[i];
			pp = i - k + 1; 
		}
		if(maxn + sum[i + k] - sum[i]  > ans){
			ans = maxn + sum[i + k] - sum[i];
			posa = pp;
			posb = i + 1;
		}
	}
	cout << posa << " " << posb;
	return 0;
}