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
map<int, int> ma;
vi v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		ma.clear();
		v.clear();
		int ans = 0;
		rep(i ,1, n + 1) {
			int x;
			cin >> x;
			ma[x] ++ ;
		}
		for(auto i : ma){
			v.pb(i.se);
		}
		int maxn = 0;
		per(i, 0, v.size()){
			ans = max(ans, v[i] - maxn);
			maxn = max(maxn, v[i]);
		}
		cout << ans << endl;
	}
	return 0;
}