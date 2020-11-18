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
int ans = 1e9;
int n, m, s;
int a[100];
int cost[100];
int maze[100][100];
int res[1000];
bool check(){
	rep(i, 1, m + 1){
		if(a[i] < s) return false;
	}
	return true;
}
void dfs(int i, int sum){
	if(check()) {
		ans = min(ans, sum);
		return ;
	}
	if(i == n + 1) return ;
	rep(j, i + 1, n + 1){
		rep(k, 1, m + 1) a[k] += maze[j][k];
		sum += cost[j];
		dfs(j, sum);
		sum -= cost[j];
		rep(k, 1, m + 1) a[k] -= maze[j][k];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> s;
	rep(i, 1, n + 1){
		cin >> cost[i];
		rep(j, 1, m + 1) {
			cin >> maze[i][j];
			res[j] += maze[i][j];
		}
	}
	rep(i, 1, m + 1){
		if(res[i] < s ) {
			cout << "-1" <<endl;
			return 0;
		}
	}
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}