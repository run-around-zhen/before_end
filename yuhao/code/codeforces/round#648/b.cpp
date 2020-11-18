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
map<vector<int>, int> ma;
vi v;
int n;
vector<int> cal(vi v, int k){
	rep(i, 0, k){
		swap(v[i], v[n - k + i]);
	}
	return v;
}
void dfs(vector<int> v){
	rep(i, 1, n / 2 + 1){
		vi v1 = cal(v, i);
		if(ma[v1] == 0) {
			ma[v1] = 1;
			/*for(auto j : v1){
				cout << j << " ";
			}
			cout << endl;*/
			dfs(v1);
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n;
	rep(i, 1, n + 1) {
		int x;
		cin >> x;
		v.pb(x);
	}
	dfs(v);
	for(auto i :ma){
		for(auto j : i.fi){
			cout << j << " ";
		}
		 cout << endl;
	}
	return 0;
}