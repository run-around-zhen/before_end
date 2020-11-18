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
int flag = 0;
int a[200000 + 10], h[200000 + 10];
vi edge[200000 + 10];
void dfs(int rt, int fi){
	int sum = 0;
	if( edge[rt].size() == 1){
		if(abs(a[rt]) < abs(h[rt]) || abs(a[rt]) % 2 != abs(h[rt]) % 2) flag = 1;
		return ;
	}
	for(auto i:edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		a[rt] += a[i];
		//h[rt] += h[i];
	}
	if(abs(a[rt]) < abs(h[rt]) || (abs(a[rt]) % 2 != abs(h[rt]) % 2)) flag = 1;
	//cout << sum << " " << rt << " " << h[rt] << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n, m;
		flag = 0;
		cin >> n >> m;
		rep(i, 1, n + 1) cin >> a[i];
		rep(i, 1, n + 1) cin >> h[i];
		rep(i, 1, n){
			int u, v;
			cin >> u >> v;
			edge[u].pb(v);
			edge[v].pb(u);
		}
		if(n == 1){
			if((abs(a[1]) < abs(h[1])) || (abs(a[1]) % 2 != abs(h[1]) % 2)) flag = 1;
		}
		else dfs(1, 0);
		if(flag){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
		rep(i, 1, n + 1) edge[i].clear();
	}
	return 0;
}