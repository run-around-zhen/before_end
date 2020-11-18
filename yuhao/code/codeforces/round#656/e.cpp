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
bool vis[200000 + 10];
int d[200000 + 10], in[200000 + 10], out[200000 + 10];
struct node{
	int op, u, v;
}a[200000 + 10];
vi edge[200000 + 10];
bool dfs(int rt){
	//cout << rt << endl;
	vis[rt] = true;
	for(auto i : edge[rt]){
		if(vis[i]) return true;
		return dfs(i);
	}
	return false;
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
		cin >> n >> m;
		int rt = 1;
		rep(i, 1, m + 1){
			cin >> a[i].op >> a[i].u >> a[i].v;
			if(a[i].op == 1){
				out[a[i].u] = 1;
				in[a[i].v] = 1;
				rt = a[i].u;
				edge[a[i].u].pb(a[i].v);
			}
		}
		if(dfs(rt)){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
			rep(i, 1, m + 1){
				if(a[i].op == 0 && in[a[i].u] && out[a[i].v]) {
					swap(a[i].u, a[i].v);
					
				}out[a[i].u] = 1;
					in[a[i].v] = 1;
				cout << a[i].u << " " << a[i].v << endl;
			}
		}
		rep(i, 1, m + 1) {
			in[i] = out[i] = 0;
			edge[i].clear();
			vis[i] = false;
		}
	}
	return 0;
}