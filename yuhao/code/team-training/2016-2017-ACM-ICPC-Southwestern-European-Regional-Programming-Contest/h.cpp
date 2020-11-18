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
typedef vector<ll> vi;
map<vi, ll> ma;
int n, h;
vi v;
set<ll> s;
ll dfs1(vi v){
	if(ma[v]) return ma[v];
	ll ans = 0;
	rep(i, 0, n){
		vi vv = v;
		vv[i] = v[i] - 1;
		sort(all(vv));
		if(vv[0] < 0 ) continue;
		ans += dfs1(vv);
	}
	return ma[v] = ans;
}
void dfs(int i, int k, int sum){
	if(sum >= h ) return ;
	if(i == n){
		/*for(auto j : v){
			cout << j << " ";
		}
		cout << endl;*/
		if(sum == h - 1) {
		//	cout << "!!" << endl;
			s.insert(dfs1(v)); 
		}
		return ;
	}
	rep(j, k, h){
		v.pb(j);
		dfs(i + 1, j, sum + j);
		v.pop_back();
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> h;
	vi vvv;
	rep(i, 0, n){
		vvv.pb(0);
	}
	ma[vvv] = 1;
	dfs(0, 0, 0);
	for(auto i : s){
		cout << i <<  endl;
	}
	return 0;
}