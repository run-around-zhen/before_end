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
	void Query(int a, int b){
		int fa = top[a], fb = top[b];	
		while(fa != fb){
			if(dep[fa] < dep[fb]) swap(a, b), swap(fa, fb);
			// Cal id[fa] .. id[a]
			a = par[fa]; fa = top[a];
		}
		if(dep[a] < dep[b]) swap(a, b);
		// Cal id[b] .. id[a]
		// b is lca
	}
	void Build(vi g[]){
		dfs(1, 0, g);
		dfs_cnt = 0;
		dfs2(1, 0, g);
	}
}hc;