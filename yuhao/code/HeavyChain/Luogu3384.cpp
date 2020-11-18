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
int N, M , R, mod;
int val[100000 + 10];
vi edge[100000 + 10];
struct segtree{
	static const int N = 4e5 + 10;
	int num[N], laze[N];
	void pushdown(int l, int r, int rt){
		int mid = (l + r) / 2;
		if(laze[rt]){
			laze[rt * 2] += laze[rt];
			laze[rt * 2 + 1] += laze[rt];
			num[rt * 2] += (mid - l + 1) * laze[rt];
			num[rt * 2 + 1] += (r - mid) * laze[rt];
			laze[rt] = 0;
		}
		return ;
	}
	void pushup(int l, int r, int rt){
		num[rt] = num[rt * 2] + num[rt * 2 + 1];
	}
	void build(int l, int r, int rt, int a[]){
		if(l == r){
			num[rt] = val[a[l]];
			return ;
		}
		int mid = (l + r) / 2;
		build(l, mid, rt * 2, a);
		build(mid + 1, r, rt * 2 + 1,  a);
		pushup(l, r, rt);
	}
	void updata(int l, int r, int ql, int qr, int val, int rt){
		if(l >= ql && r <= qr){
			laze[rt] += val;
			num[rt] += (r - l + 1) * val;
			return ;
		}
		pushdown(l, r, rt);
		int mid= (l + r) / 2;
		if(ql <= mid) updata(l, mid, ql, qr, val, rt * 2);
		if(qr > mid) updata(mid + 1, r, ql, qr, val, rt * 2 + 1);
		pushup(l, r, rt);
		return ;
	}
	int qry(int l, int r, int ql, int qr, int rt){
		if(l >= ql && r <= qr){
			return num[rt];
		}
		pushdown(l, r, rt);
		int mid = (l + r) / 2;
		int ans = 0;
		if(ql <= mid) ans += qry(l, mid, ql, qr, rt * 2);
		if(qr > mid) ans += qry(mid + 1, r, ql, qr, rt * 2 + 1);
		pushup(l, r, rt);
		return ans;
	}
}T;
struct HeavyChain{
	static const int N = 1e5 + 10;
	int sz[N], wson[N], top[N], dep[N], id[N], dfs_cnt, par[N], who[N];
	void dfs(int rt, int fa, vi g[]){
		sz[rt] = 1;
		par[rt] = fa;
		dep[rt] = dep[fa] + 1;
		int &s = wson[rt] = top[rt] = 0;
		for(auto t : g[rt]) {
			if(t == fa)  continue;
			dfs(t, rt, g);
			sz[rt] += sz[t];
			if(sz[t] >= sz[s]) s = t;
		}
	}
	void dfs2(int rt, int fa, vi g[]){
		id[rt] = ++dfs_cnt;
		who[dfs_cnt] = rt;
		int s = wson[rt];
		if(!top[rt]) top[rt] = rt;
		if(s) top[s] = top[rt], dfs2(s, rt, g);
		for(auto t : g[rt]) if(t != fa && t != s) dfs2(t, rt, g);
	}
	void Query(int a, int b, int z, int n){
		int fa = top[a], fb = top[b];	
		while(fa != fb){
			if(dep[fa] < dep[fb]) swap(a, b), swap(fa, fb);
			// Cal id[fa] .. id[a]
			T.updata(1, n, id[fa], id[a] , z, 1);
			a = par[fa]; fa = top[a];
		}
		if(dep[a] < dep[b]) swap(a, b);
		T.updata(1, n, id[b], id[a], z, 1);
		// Cal id[b] .. id[a]
		// b is lca
	}
	int Query1(int a, int b, int n){
		int fa = top[a], fb = top[b];	
		ll ans = 0;
		while(fa != fb){
			if(dep[fa] < dep[fb]) swap(a, b), swap(fa, fb);
			// Cal id[fa] .. id[a]
			ans = (ans + T.qry(1, n, id[fa], id[a], 1)) % mod ; 
			a = par[fa]; fa = top[a];
		}
		if(dep[a] < dep[b]) swap(a, b);
		ans = (ans + T.qry(1, n, id[b], id[a], 1)) % mod;
		return ans;
		// Cal id[b] .. id[a]
		// b is lca
	}
	void Build(vi g[]){
		dfs(R, 0, g);
		dfs_cnt = 0;
		dfs2(R, 0, g);
	}
}hc;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N  >> M >> R >> mod;
	rep(i, 1, N + 1) cin >> val[i];
	rep(i, 1, N){
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	hc.Build(edge);
	cout << endl;
	T.build(1, N, 1, hc.who);
	while(M --){
		int op, x, y, z;
		cin >> op ;
		if(op == 1){
			cin >> x >> y >> z;
			hc.Query(x, y ,z, N);
		}
		else if(op == 2){
			cin >> x >> y;
			cout << hc.Query1(x, y, N) << endl;
		}
		else if(op == 3){
			cin >> x >> z;
			T.updata(1, N, hc.id[x], hc.id[x] + hc.sz[x] - 1, z, 1);
		}
		else if(op == 4){
			cin >> x;
			cout << T.qry(1, N, hc.id[x], hc.id[x] + hc.sz[x] - 1, 1) << endl;
		}
	}
	return 0;
}