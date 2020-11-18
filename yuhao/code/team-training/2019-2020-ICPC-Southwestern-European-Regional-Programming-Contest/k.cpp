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
vi v, edge[200000 + 10], ans;
bool vis[200000 + 10];
int d[200000 + 10];
void dfs(int i){
	//cout << i << endl;
	if(vis[i] || d[i] > 1) return ;
	d[i] ++;
	for(auto j : edge[i]){
		vis[i] = 1;
		v.pb(i);
		dfs(j);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m, T;
	cin >> n >> m >> T;
	rep(i, 0, m){
		int a, b;
		cin >> a >> b;
		edge[b].pb(a);
	}
	vis[T] = 1;
	for(auto i : edge[T]){
		//memset(vis, false,sizeof(vis));
		//vis[T] = 1;
		dfs(i);
		/*rep(i, 0, n){
			cout << d[i] << " ";
		}
		cout << endl;*/
		for(auto j : v) vis[j] = 0;
	}
	for(auto i : edge[T]){
		if(d[i] == 1) ans.pb(i);
	}
	cout << ans.size() << endl;
	for(auto i : ans ){
		cout << i << endl;
	}
	return 0;
}