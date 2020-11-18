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
vector<pair<int,ll>>edge[100000+10];
ll len[100000+10],f[100000+10][40],lg[100000+10],h[100000+10],siz[100000 + 10], res[100000 + 10];
int n;
ll sum[100000 + 10];
void dfs(int rt,int fi){
	h[rt]=h[fi]+1;
	f[rt][0]=fi;
	siz[rt] = 1;
	//cout << rt << " " << fi << endl;
	for(int i=1;(1<<i)<=h[rt];i++) f[rt][i]=f[f[rt][i-1]][i-1];
	for(int i=0;i<edge[rt].size();i++){
	    int y=edge[rt][i].fi;
	    if(y==fi) continue;
	   	len[y]=len[rt]+edge[rt][i].se;
	    dfs(y,rt);
	    siz[rt] += siz[y];
	    res[rt] += res[y] + siz[y];
	}
}
int up(int x,int d){
    for(int i=25;i>=0;i--){
        if(d<(1<<i))continue;

        x=f[x][i];
      //  cout << d<<" " << x << "!!!!!!" << endl;
        d-=(1<<i);
        
    }
    return x;
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
void dfs1(int rt, int fi){
	sum[rt] += res[rt];
	for(auto i: edge[rt]){
		if(i.fi == fi) continue;
		int tmp = siz[i.fi];
		sum[i.fi] = sum[rt] - (res[i.fi] + siz[i.fi]) + n - siz[i.fi];
		dfs1(i.fi, rt);
	}
}
ll get_dis(int a,int b){
	return len[a]+len[b]-2*len[lca(a,b)];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int  m;
	cin >> n >> m;
	rep(i,1,n+1) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	rep(i, 1, n){
		int u, v;
		cin >> u >> v;
		edge[u].pb(mp(v, 1));
		edge[v].pb(mp(u, 1));
	}
	dfs(1, 0);
	dfs1(1, 0);
	//rep(i, 1, 5) cout << res[i] << ">>>" << endl;
	while(m --){
		int u, v;
		cin >> u >> v;
		int LCA = lca(u, v);
	//cout << u << " " << v << "??? " << LCA << endl;
		if(LCA != u && LCA != v){
			cout<<setiosflags(ios::fixed)<<setprecision(10)<< 1.0 * (siz[u] * siz[v] * (get_dis(u, v) + 1) + res[u] * siz[v] + res[v] * siz[u]) / (siz[u] * siz[v]) << endl;
		}
		else{
			if(LCA != u) swap(u, v);
			int rt = up(v, h[v] - h[u] - 1);
			ll tmp = sum[u] - res[rt] - siz[rt];
			//cout << sum[u] << " " << u << "!!!" << endl;
			//cout << u << " "<< v <<" " << h[v]- h[u] - 1<<" " <<rt << " "<< tmp <<"!!" << endl;
			cout<<setiosflags(ios::fixed)<<setprecision(10) <<1.0 * ((n - siz[rt]) * siz[v] * (get_dis(u, v) + 1) + tmp * siz[v] + res[v] * (n - siz[rt])) / ((n - siz[rt]) * siz[v])<< endl;
		}
	}
	return 0;
}


