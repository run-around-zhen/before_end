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
int dp[300000 + 10], sum = 0, a[300000 + 10];
vi edge[300000 + 10];
void dfs(int rt, int fi){
	if(edge[rt].size() == 1){
		sum ++;
		dp[rt] = 1;
		return ;
	} 
	dp[rt] = 1e9;
	int res = 0;
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		if(a[rt] == 1) dp[rt] = min(dp[rt], dp[i]);
		res += dp[i];
	}
	if(a[rt] == 0){
		dp[rt] = res ;
	}
//	cout << rt << " " << dp[rt] << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 2, n + 1){
		int x;
		cin >> x;
		edge[i].pb(x);
		edge[x].pb(i);
	}
	dfs(1, 0);
	//cout << sum << endl;
	cout << sum - dp[1] + 1 << endl;
	return 0;
}