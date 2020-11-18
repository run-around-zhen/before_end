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
int d[200000 + 10];
vi edge[200000 + 10];
int deep[200000 + 10];
priority_queue<pii> q;
bool vis[200000 + 10];
void dfs(int rt, int fi){
	d[rt] = edge[rt].size();
	deep[rt] = deep[fi] + 1;
	q.push(mp(deep[rt], rt));
	for(auto i: edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
	}
}
void solve(int rt){
	cout << rt << endl;
	vis[rt] = true;
	for(auto i : edge[rt]){
		if(vis[i]) continue;
 		d[i] --;
	}
	for(auto i: edge[rt]){
		if(vis[i]) continue;
		if(d[i] % 2 == 0 && deep[i] > deep[rt]) solve(i);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int rt = 0;
	rep(i, 1, n + 1){
		int x;
		cin >> x;
		if(x != 0){
			edge[i].pb(x);
			edge[x].pb(i);
		}
		else{
			rt = i;
		}
	}
	if(n % 2 == 0){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
		dfs(rt, 0);
		while(!q.empty()){
			int now = q.top().se;
			q.pop();
			if(d[now] % 2 == 0) solve(now);
		}
	}
	return 0;
}