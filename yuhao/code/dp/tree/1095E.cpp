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
priority_queue<pii>q;
int deep[100000 + 10], f[100000 + 10], fa[100000 + 10], a[100000 + 10];
vi edge[100000 + 10];
ll sum[100000 + 10];
bool vis[100000 + 10];
void dfs(int rt, int fi){
	deep[rt] = deep[fi] + 1;
	sum[rt] = sum[fi] + a[rt];
	q.push(mp(deep[rt], rt));
	for(auto i: edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
	}
}
int find(int rt){
	if(f[rt] == rt) return rt;
	return f[rt] = find(f[rt]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	ll l, s;
	int flag = 0;
	cin >> n >> l >> s;
	rep(i, 1, n + 1)  {
		cin >> a[i];
		if(a[i] > s){
			flag = 1;
		}
	}
	rep(i, 2, n + 1){
		int x;
		cin >> x;
		edge[x].pb(i);
		edge[i].pb(x);
		fa[i] = x;
	}
	if(flag){
		cout << "-1" << endl;
		return 0;
	}
	rep(i, 1, n + 1) f[i] = i;
	dfs(1, 0);
	int ans = 0;
	while(!q.empty()){
		int now = q.top().se ;
		int y = now;
		q.pop();
		if(vis[now]) continue;
		ans ++;
		while(y && deep[now] - deep[y] + 1 <= l && sum[now] - sum[y] + a[y] <= s){
			vis[y] = true;
			f[y] = find(fa[y]);
			y = f[y];
		}
	}
	cout << ans << endl;
	return 0;
}