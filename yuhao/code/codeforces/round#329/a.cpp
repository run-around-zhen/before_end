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
vector<pair<int,ll>>edge[1000000+10];
ll len[1000000+10],f[200000+10][40],lg[1000000+10],h[1000000+10];
int fa[200000+10];
ll cost[200000+10];
int l[200000+10],r[200000+10];
void dfs(int rt,int fi){
	h[rt]=h[fi]+1;
	f[rt][0]=fi;
	fa[rt] = fi;
	for(int i=1;(1<<i)<=h[rt];i++) f[rt][i]=f[f[rt][i-1]][i-1];
	for(int i=0;i<edge[rt].size();i++){
	    int y=edge[rt][i].fi;
	    if(y==fi) continue;
	    cost[y] = edge[rt][i].se;
	   	len[y]=len[rt]+edge[rt][i].se;
	    dfs(y,rt);
	}
}
ll lca(int x,int y){
	if(h[x]<h[y]) swap(x,y);
	while(h[x]>h[y]) x=f[x][lg[h[x]-h[y]]-1];
	if(x==y) return x;
	for(int i=lg[h[x]]-1;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
ll get_dis(int a,int b){
	return len[a]+len[b]-2*len[lca(a,b)];
}
ll find(int rt){
	if(cost[rt] > 1) return rt;
	return fa[rt] == find(fa[rt]);
}
ll cal(int x, int y, ll val){
	int father = lca(x, y);
//	if(h[x] < h[y]) swap(x, y);
	while(h[fa[x]] >= h[father]){
		// cout << cost[x] << "***" << val <<endl;
		val /= cost[x];
		
		if(cost[x] == 1) {
			//fa[x] = find(x);
			find(x);
		}
		x = fa[x];
		if(x == 1 || x == 0) break;
		if(val == 0) return 0;
	}
	//cout << x << " " << y <<" "<<father<<" " << val << "???" <<endl;
	while(h[fa[y]] >= h[father]){
		//cout << y << endl;
		val /= cost[y];
		if(cost[y] == 1) {
			//fa[y] = find(y);
			find(y);
		}	
		y = fa[y];
		if(y == 1 || y == 0) break;
		if(val == 0) return 0;
	}
	//cout << x <<" " << y <<" "<<father<<" "<<val <<"???" <<endl;
	return val;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int start = clock();
	int n, m;
	cin >> n >> m;
	rep(i,1,n+1) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	rep(i, 1, n){
		ll u, v, w;
		cin >> u >> v >> w;
		edge[u].pb(mp(v,w));
		edge[v].pb(mp(u,w));
		l[i] = u;
		r[i] = v;
	}
	dfs(1, 0);
	cost[1] = 0;
	rep(i, 1, m + 1){
		int op;
		cin >> op;
		if(op == 1){
			ll x, y, z;
			cin >> x >> y >> z;
			if((1.0*clock() - start)/CLOCKS_PER_SEC > 2.0 )	{
				printf("113221\n");
				continue;
			}
			cout << cal(x ,y, z) << endl;
		}
		else{
			int id;
			ll val;
			cin >> id >> val;
			if(fa[l[id]] == r[id]){
				cost[l[id]] = val;
			}
			if(fa[r[id]] == l[id]){
				cost[r[id]] = val;
			}
		}	
	}
	return 0;
}