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
int n;
vi edge[100000 + 10];
double ansy = 0, ansx = 0;
double dp[100000 + 10];
int siz[100000 + 10];
double a[100000 + 10], b[100000 + 10];
double res = 0;
void dfs(int rt, int fi){
	siz[rt] = 1;
	for(auto i: edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		siz[rt] += siz[i];
		dp[rt] += dp[i];
	}
	dp[rt] += 1.0 * siz[rt] * b[rt] / ansy;
}
void dfs1(int rt, int fi, double p){
	dp[rt] += p;
	res += (n - dp[rt]) * a[rt] / ansx;
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs1(i, rt, dp[rt] - dp[i] - siz[i] * b[rt] / ansy + (n - siz[i]) * b[i] / ansy);
	}
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);

	//cin >> n;
	scanf("%d", &n);
	rep(i, 1, n){
		int x, y;
		//cin >> x >> y;
		scanf("%d %d", &x, &y);
		edge[x].pb(y);
		edge[y].pb(x);
	}
	rep(i, 1, n + 1){
		//cin >> a[i] >> b[i];
		scanf("%lf %lf", &a[i], &b[i]);
		ansx += a[i];
		ansy += b[i];
	}
	dfs(1, 0);
	dfs1(1, 0, 0);
	cout << setiosflags(ios::fixed) << setprecision(12) << res << endl;
	return 0;
}