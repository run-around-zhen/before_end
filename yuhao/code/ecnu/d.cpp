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
ll sum = 0;
int a[1000000 + 10],dp[1000000 + 10][2];
vi edge[1000000 + 10];
int res = 0;
ll suml = 1e9, sumr = 1;
void dfs(int rt, int fi){
	int maxn = 0;
	int maxn1 = 0;
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		if(dp[i][0] > maxn) maxn = dp[i][0];
		else if(dp[i][0] > maxn1) maxn1 = dp[i][0];
	}
	if(a[rt] == 1){
		dp[rt][0] = maxn + 1;
		dp[rt][1] = maxn1 + 1;
	}
	/*else{
		dp[rt][0] = maxn;
		dp[rt][1] = maxn1;
	}*/
}
void dfs1(int rt, int fi, int tmp){
	if(a[rt] == 1){
		res = max(res, dp[rt][0] + dp[rt][1] - 1);
		res = max(res, dp[rt][0] + tmp - 1);
	}
	//else{
		
		
	//}
//	cout << rt << " " << fi << " " << tmp << " " << res <<" "<< dp[rt][0] << " " << dp[rt][1] <<" " <<tmp <<endl;
	if(a[rt] == 1){
		if(dp[rt][0] < tmp){
			dp[rt][1] = dp[rt][0];
			dp[rt][0] = tmp;
		}
		else if(dp[rt][1] < tmp){
			dp[rt][1] = tmp;
		}
	}
	int maxn = 0, maxn1 = 0;
	for(auto i : edge[rt]){
		if(i == fi) continue;
		/*if(a[rt] != 1) {
			dfs1(i, rt, 0);
			continue;
		}*/
		if(dp[rt][0] == dp[i][0] + 1){
			dfs1(i, rt, dp[rt][1] + 1);
		}
		else{
			dfs1(i, rt, dp[rt][0] + 1);
		}
		if(dp[i][0] > maxn) maxn = dp[i][0];
		else if(dp[i][0] > maxn1) maxn1 = dp[i][0];
	}
	//cout << maxn << "  " << maxn1 << " " << tmp << endl;
	if(a[rt] != 1){
		if(1.0 * suml / sumr > 1.0 * a[rt] / (max(maxn + maxn1 + 1, maxn + tmp))){
			suml = a[rt];
			sumr = max(maxn + maxn1 + 1, maxn + tmp);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n){
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	int ans = 1e9 + 10 ;
	rep(i, 1, n + 1) {
		cin >>  a[i];
		ans = min(ans , a[i]);
	}
	if(ans == 1){
		dfs(1, 0);
		dfs1(1, 0, 0);
		if(1.0 * suml / sumr > 1.0 / res){
			cout << "1/" << res << endl;
		}
		else{
			int gcd = __gcd(suml, sumr);
			cout << suml / gcd << "/" << sumr / gcd << endl;
		}
	}
	else{
		cout << ans << "/" << "1" << endl;
	}
	return 0;
}
/*
10
1 2 
2 3
2 4
2 5
4 8
4 9
4 10
1 6
1 7
2
1
1
1
1
1
1
1
1
1
*/