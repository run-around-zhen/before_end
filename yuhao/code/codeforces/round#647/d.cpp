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
struct node{
	int val, pos;
}a[500000 + 10];
int b[500000 + 10];
bool cmp(node a, node b){
	return a.val < b.val;
}
vi v, edge[500000 + 10];
bool vis[500000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, m + 1){
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	rep(i, 1, n + 1){
		cin >> a[i].val;
		a[i].pos = i;
		b[i] = a[i].val;
	}
	sort(a + 1, a + 1 + n, cmp);
	rep(i, 1, n + 1){
		v.clear();
		for(auto j : edge[a[i].pos]){
			if(vis[j]) v.pb(b[j]);
		}
		sort(all(v));
		int minn = 1;
		for(auto j : v){
			if(j == minn) minn++;
		}
		//cout << minn << endl;
		if(minn != a[i].val){
			cout << "-1" << endl;
			return 0;
		}
		vis[a[i].pos] = true;
	}
	rep(i, 1, n + 1){
		cout << a[i].pos << " ";
	}
	return 0;
}