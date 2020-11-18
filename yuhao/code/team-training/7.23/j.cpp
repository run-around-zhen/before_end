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
int T;
int n, k;
int cas = 1;
ll ans;
int flag = 0;
struct node{
	int a, b, c, d;
}maxn[100];
vector<node>acc[100];
int start;
void dfs(int i, int a, int b, int c, int d){
	ans = max(ans, (ll)(100 + a) * (100 + b) * (100 + c) * (100 + d));
	if(maxn[i].a >= a +120 && maxn[i].b >= b + 120&& maxn[i].c >= c + 120&& maxn[i].d >= d + 120){
		return ;
	}
	maxn[i].a = max(maxn[i].a, a);
	maxn[i].b = max(maxn[i].b, b);
	maxn[i].c = max(maxn[i].c, c);
	maxn[i].d = max(maxn[i].d, d);
	/*if(1.0 * (clock() - start) / CLOCKS_PER_SEC > 1.0 * cas / T * 8 - 0.05) {
		flag = 1;
	}*/
	if(i == k + 1) return ;
	if(flag){
		return ;
	}
	rep(j, 0, (int)acc[i].size()){
		dfs(i + 1, a + acc[i][j].a, b + acc[i][j].b, c + acc[i][j].c, d + acc[i][j].d);
		if(flag){
			return ;
		}
	}
	if(flag){
		return ;
	}
	if(acc[i].size() == 0){
		dfs(i + 1, a, b, c, d);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	srand(time(0));
	start = clock();
	cin >> T;
	for(; cas <= T; cas ++){
		cin >> n >> k;
		rep(i, 1, k + 1){
			maxn[i] = {-1, -1, -1, -1};
		}
		rep(i, 1, k + 1) acc[i].clear();
		ans = 0;
		flag = 0;
		rep(i, 1, n + 1) {
			int  op, a, b, c, d;
			cin >> op >> a >> b >> c >> d;
			acc[op].pb({a, b, c, d});
		}
		rep(i, 1, k + 1) random_shuffle(all(acc[i]));
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}