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
int ans[300000 + 10];
vi v[300000 + 10];
int res[300000 + 10];
int a[300000 + 10];
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
		rep(i, 1, n + 1){
			cin >> a[i];
			v[a[i]].pb(i);
		}
		rep(i, 1, n + 1){
			ans[i] = 0;
			if(v[i].size()!= 0) ans[i] = max(v[i][0], n - v[i][(int)v[i].size() - 1] + 1);
			rep(j, 0, (int)v[i].size() - 1){
				ans[i] = max(v[i][j + 1] - v[i][j], ans[i]);
			}
		}
		int j = 1;
		int fi = -1;
		/*rep(i, 1, n + 1){
			cout << ans[i] <<" ";
		}
		cout << endl;*/
		rep(i, 1, n + 1) res[i] = 1e9;
		rep(i, 1, n + 1){
			res[ans[i]] = min(res[ans[i]], i);
		}
		res[0] = 1e9;
		rep(i, 1,n + 1){
			res[i] = min(res[i], res[i - 1]);
		}
		/*per(i, 1, n + 1){
			if(ans[i] == 0) continue;
			while(j < ans[i]){
				res[j] = fi;
				j ++;
			}
			fi = i;
		}
		rep(i, j, n + 1) res[i] = fi;*/
		rep(i, 1, n + 1){
			if(res[i] == 1e9 ) cout << "-1 ";
			else cout << res[i] << " ";
		}
		cout << endl;
		rep(i, 1, n + 1) v[i].clear();
	}
	return 0;
}