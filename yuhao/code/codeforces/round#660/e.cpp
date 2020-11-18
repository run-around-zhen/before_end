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
ll a[200000 + 10], b[200000 + 10], dp[200000 + 10];
bool vis[200000 + 10], vis1[200000 + 10];
vi edge[200000 + 10], v[200000 + 10];
int d[200000 + 10];
vi ans;
void dfs(int rt, int fi){
	vis[rt] = true;
	dp[rt] = a[rt];
	for(auto i : edge[rt]){
		if(i == fi) continue;
		if(!vis[i]) dfs(i, rt);
		if(dp[i] > 0) {
			dp[rt] += dp[i];
			v[i].pb(rt);
			d[rt] ++;
		}
		else{
			v[rt].pb(i);
			d[i] ++;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n + 1) cin >> b[i];
	rep(i, 1, n + 1){
		if(b[i] == -1) continue;
		edge[b[i]].pb(i);
	//	d[i] ++;
	}
	ll res = 0;
	rep(i, 1, n + 1){
		if(!vis[i]) {
			dfs(i, 0);
		}
		res += dp[i];
	}
	queue<int>q;
	rep(i, 1, n + 1) {
		if(d[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int rt = q.front();
		vis1[rt] = true;
		ans.pb(rt);
		q.pop();
		for(auto i :v[rt]){
			d[i] --;
			if(d[i] == 0) {
				q.push(i);
			}
		}
	}
	rep(i, 1, n + 1){
		if(!vis1[i]) ans.pb(i);
	}
	
	cout << res << endl;
	for(auto i : ans){
		cout << i <<  " ";
	}
	return 0;
}