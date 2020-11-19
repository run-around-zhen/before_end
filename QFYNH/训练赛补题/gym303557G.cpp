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
const int mod = 998244353;
const int base = 321685497;
const int N = 2000000 + 10;
int siz[N];
int deg[N];
bool incyc[N];
int ha[N];
set<pii> s;
vi edge[N], idcyc;
int add(int a, int b){
	if(a + b >= mod) return a + b - mod;
	return a + b;
}
int mul(int a, int b){
	return (ll)a * b % mod;
}
int sub(int a, int b){
	return add(a, -b + mod);
}
struct treehash{
	int dfs(int rt, int fi){
		siz[rt] = 1;
		vi vec;
		for(auto i : edge[rt]){
			if(i == fi || incyc[i]) continue;
			vec.pb(dfs(i, rt));
			siz[rt] += siz[i];
		}
		sort(all(vec));
		int hash = 98563217;
		for(auto i:vec){
			hash = add(i, mul(hash, base));
		}
		hash = mul(hash, siz[rt]);
		return hash;
	}
}get_ha;
void get_cyc(int  n){
	queue<int> q;
	rep(i, 1, n + 1){
		incyc[i] = true;
		if(deg[i] == 1){
			q.push(i);
		}
	}
	while(!q.empty()){
		int x = q.front();
		incyc[x] = false;
		q.pop();
		for(auto i : edge[x]){
			deg[i] --;
			if(deg[i] == 1){
				q.push(i);
			}
		}
	}
}	
void dfs_cyc(int rt, int fi, int fa){
	idcyc.pb(rt);
	for(auto i : edge[rt]){
		if(!incyc[i] || i == fi || i == fa) continue;
		dfs_cyc(i, rt, fa);
		break;
	}
}
int getha_cyc(vi v){
	int n = v.size();
	vi hacyc;
	int ans = 0;
	int bb = 1;
	rep(i, 0, n){
		ans = add(ha[v[i]], mul(ans, base));
		if(i != n - 1) bb = mul(bb, base);
	}
	rep(i, 0, n){
		ans = sub(ans, mul(ha[v[i]], bb));
		ans = mul(ans, base);
		ans = add(ans, ha[v[i]]);
		hacyc.pb(ans);
	}
	sort(all(hacyc));
	int hash = 0;
	for(auto i: hacyc){
		hash = add(i, mul(hash, mod));
	}
	return hash;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int k;
		cin >> k;
		rep(cas, 1, k + 1){
			int n;
			cin >> n;
			rep(i, 1, n + 1){
				int u, v;
				cin >> u >> v;
				edge[u].pb(v);
				edge[v].pb(u);
				deg[u] ++;
				deg[v] ++;
			}
			get_cyc(n);
			vi ha_cyc;
			rep(i, 1, n + 1){
				if(incyc[i]){
					ha[i] = get_ha.dfs(i, 0);
				}
			}
			rep(i, 1, n + 1){
				if(incyc[i]){
					dfs_cyc(i, 0, i);
					break;
				}
			}
			int ha1 = getha_cyc(idcyc);
			reverse(all(idcyc));
			int ha2 = getha_cyc(idcyc);
			s.insert(mp(min(ha1, ha2), max(ha1, ha2)));
			rep(i, 1, n + 1){
				deg[i] = 0;
				edge[i].clear();
				siz[i] = 0;
				idcyc.clear();
				ha[i] = 0;
			}
		}
		cout << s.size() << endl;
		s.clear();
	}
	return 0;
}
/*
1
2
4 1 2 2 3 3 1 2 4
4 1 2 2 3 3 1 1 4

*/