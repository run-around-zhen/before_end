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
void dfs(int rt,int fi){
	h[rt]=h[fi]+1;
	f[rt][0]=fi;
	for(int i=1;(1<<i)<=h[rt];i++) f[rt][i]=f[f[rt][i-1]][i-1];
	for(int i=0;i<edge[rt].size();i++){
	    int y=edge[rt][i].fi;
	    if(y==fi) continue;
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	rep(i,1,n+1) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	return 0;
}


