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
double dp[10000 + 10][1000 + 10];
int ans[1000 + 10];
struct node{
	int val, pos;
}a[1000 + 10];
bool cmp(node a, node b){
	return a.val < b.val;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, q;
	cin >> n >> q;
	//int inv = qpow(n, mod - 2);
	dp[0][0] = 1;
	rep(i, 1, 10000 + 1){
		rep(j, 1, n + 1){
			dp[i][j] = (1.0 * dp[i - 1][j - 1] * (n - j + 1) / n + 1.0 * dp[i - 1][j] * (j) / n);
			//cout << i << " " << j << " "<< dp[i][j] << endl;
		}
	}
	int pos = 0;
	rep(i ,0, q) {
		cin >> a[i].val;
		a[i].pos = i;
	}
	sort(a, a + q, cmp);
	rep(i, 1, 10000 + 1){
		while(dp[i][n] >= 1.0 * a[pos].val / 2000 && pos < q) {
			ans[a[pos].pos] = i;
			pos ++;
			//cout << " ?? " << endl;
		}
	//	cout << dp[i][n] << endl;
	}
	rep(i, 0, q) cout << ans[i] << endl;
	return 0;
}