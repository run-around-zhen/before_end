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
typedef vector<pii> vi;
vi ans;
bool vis[1000000 + 10];
vector<int>v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		ans.clear();
		for(int i = 2; i <= n; i ++){
			v.clear();
			int cnt = 0;
			for(int j = i; j <= n; j += i){
				if(!vis[j]) {
					cnt ++;
					v.pb(j);
				}
				if(cnt == 2) {
					vis[v[1]] = true;
					vis[v[0]] = true;
					ans.pb(mp(v[1], v[0]));
					cnt = 0;
					v.clear();
				}
			}
		}
		cout << ans.size() << endl;
		for(auto i : ans){
			cout << i.fi << " " << i.se << endl;
		}
		rep(i, 1, n + 1) vis[i] = false;
	}
	return 0;
}