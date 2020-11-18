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
ll a[200000 + 10], b[200000 + 10], d[200000 + 10], c[200000 + 10], f[200000 + 10], siz[200000 + 10];
vi edge[200000 + 10];
bool vis[200000 + 10];
bool vis1[200000 + 10];
vi ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	ll res = 0;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n + 1) {
		c[i] = a[i];
		f[i] = i;
		siz[i] = 1;
	}
	rep(i, 1, n + 1) cin >> b[i];
	rep(i, 1, n + 1){
		if(b[i] == -1) continue;
		if(a[i] > 0){
			vis1[i] = true;
		}
	}
	queue<int>q, q1;
	rep(i, 1, n + 1) if(vis1[i]){
		q1.push(i);
	}
	while(!q1.empty()){
		int i = q1.front();
		q1.pop();
		if(b[i] == -1) continue;
		if(a[f[b[i]]] + a[i] > 0){
			edge[i].pb(b[i]);
			d[b[i]] ++;
			if(b[i] != f[b[i]]){
				edge[b[i]]
			}
			vis1[b[i]] = true;
			q1.push(b[i]);
			a[b[i]] += a[i];
		}
	}
	rep(i, 1, n + 1){
		if(a[i] < 0){
			edge[b[i]].pb(i);
			d[i] ++;
		}
	}
	rep(i, 1, n + 1) {
		if(d[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int rt = q.front();
		vis[rt] = true;
		ans.pb(rt);
		q.pop();
		for(auto i :edge[rt]){
			d[i] --;
			if(d[i] == 0) {
				q.push(i);
			}
		}
	}
	rep(i, 1, n + 1){
		if(!vis[i]){
			ans.pb(i);
			res += a[i];
		}
	}
	//ll res = 0;
	/*for(auto i : ans){
		res += c[i];
		c[b[i]] += c[i]; 
	}*/
	cout << res << endl;
	for(auto i :ans){
		cout << i << " " ;
	}
	cout << endl;
	return 0;
}