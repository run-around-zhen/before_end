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
bool vis[100000 + 10];
vi v, edge[100000 + 10], s[100000 + 10];
int deep[100000 + 10];
int k;
void dfs(int rt, int fi, int fa){
	//cout <<rt << " " << fi << endl;
	deep[rt] = deep[fi] + 1;
	v.pb(rt);
	s[fa].pb(rt);
	vis[rt] = true;
	for(auto i:edge[rt]){
		if(i == fi) continue;
		/*if(rt == 4 ){
			cout <<"!!!" << i << endl;
		}*/
		if(vis[i]) {
			//
			if(abs(deep[rt] - deep[i]) + 1 <= k){
				//cout << "!" << rt << " " << i << endl;
				//cout << deep[rt] << " "<< deep[i] << endl;
				cout << "2" << endl;
				cout << abs(deep[rt] - deep[i]) + 1 << endl;
				int flag = 1;
				for(auto j:v){
					if(j == i) flag = 0;
					if(!flag) cout << j << " ";
				}
				exit(0);
			}
		}
		else{
			dfs(i, rt, fa);
		}
	} 
	v.pop_back();
}
int main(){
	//ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m >> k;
	rep(i, 1, m + 1){
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	rep(i, 1, n + 1){
		v.clear();
		if(!vis[i]){
			dfs(i, 0, i);
		}
	}
	cout << "1" << endl;
	int t = 0;
	rep(i, 1, n + 1){
		rep(j, 0, (int)s[i].size()){
			if(j == s[i].size() - 1 && s[i].size() % 2  == 1) break;
			if(t == (k + 1)/ 2) break;
			if(deep[s[i][j]] % 2 == 1) {
				cout << s[i][j] << " ";
				t ++;
			}
		}
	}
	return 0;
}