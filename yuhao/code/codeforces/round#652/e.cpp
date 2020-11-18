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
int w[200000 + 10], tot[200000 + 10];
vi ans, v[200000 + 10];
bool vis[200000 + 10];
int a[200000 + 10], b[200000 + 10];
void check(int i){
	if(vis[i]) return ;
	if(tot[a[i]] <= w[a[i]] || tot[b[i]] <= w[b[i]]){
		ans.pb(i);
		vis[i] = true;
		tot[a[i]]--;
		tot[b[i]]--;
		for(auto j : v[a[i]]) check(j);
		for(auto j : v[b[i]]) check(j);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n + 1) cin >> w[i];
	rep(i, 1, m + 1){
		cin >> a[i] >> b[i];
		v[a[i]].pb(i);
		v[b[i]].pb(i);
		tot[a[i]] ++ ;
		tot[b[i]] ++;
	}
	rep(i, 1, m + 1) check(i);
	if(ans.size() == m) {
		cout << "ALIVE" << endl;
		reverse(all(ans));
		for(auto i:ans) cout << i << " ";
	}
	else{
		cout << "DEAD" << endl;
	}
 	return 0;
}