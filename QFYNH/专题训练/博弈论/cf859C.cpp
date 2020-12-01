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
int a[1000000 + 10];
int dp[1000000  + 10][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		cin >> a[i];
	}
	dp[n][1] = a[n]; dp[n][0]=0;
	per(i, 1, n) {
		dp[i][1]=max(a[i]+dp[i+1][0],dp[i+1][1]);
		dp[i][0]=min(dp[i+1][1],a[i]+dp[i+1][0]);
	}
	cout << dp[1][0] << " " << dp[1][1]<< endl;
	return 0;
}