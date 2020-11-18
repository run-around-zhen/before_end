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
set<int>v;
int a[100000 + 10];
int n;
int cal(){
	v.clear();
	rep(j, 1, n + 1){
		v.insert(a[j]);
	}
	//sort(all(v));
	int j = 0;
	for(auto k : v){
		if(k != j){
			return j;
		}
		j ++ ;
	}
	return n;
}
vi ans;
vi cnt[1000 + 10];
int vis[1010];
bool get(int k){
	rep(i, 1, k){
		if(a[i] > k) return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		ans.clear();
		memset(vis, 0, sizeof(vis));
		cin >> n;
		rep(i, 0, n + 1) cnt[i].clear();
		rep(i ,1, n + 1){
			cin >> a[i];
			//cnt[a[i]].pb(i);
			vis[a[i]] ++;
		}
		/*rep(i, 0, n + 1){
			rep(j, 0, (int)cnt[i].size() - 1){
				a[cnt[i][j]] = cal();
				ans.pb(cnt[i][j]);
			}
		}*/
		rep(i, 1, n + 1){
			if((vis[a[i]] > 1 && get(i))|| a[i] > i - 1) {
				vis[a[i]] --;
				a[i] = cal();
				
				ans.pb(i);
			}
		}
		//cout << ans.size() << endl;
		//rep(i ,1, n + 1) cout << a[i] << " ";
	//	cout << endl;
	//cout << "!!" << endl;
		rep(i, 1, n + 1){
			int mex = cal();
			if(a[i] == i - 1) continue;
			while(mex >= i){
				rep(j, i + 1, n + 1){
					if(a[j] < i) {
						a[j] = mex;
						ans.pb(j);
						break;
					}
				}
				mex = cal();
			}
			a[i] = mex;
			ans.pb(i);
		}
		/*rep(i, 1, n + 1) cout << a[i] << " ";
		cout << endl;*/
		cout << ans.size() << endl;
		for(auto i: ans){
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}