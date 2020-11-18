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
typedef vector<pii> vi;
vi ans;
char a[1000][1000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		rep(j, 1, n + 1){
			cin >> a[i][j];
		}
	}
	rep(i, 1, n + 1){
		int flag = 0;
		rep(j, 1, n + 1){
			if(a[i][j] != 'E') flag = 1;
		}
		if(!flag){
			rep(k, 1, n + 1){
				rep(t, 1, n + 1){
					if(a[t][k] != 'E') {
						ans.pb(mp(t, k));
						break;
					}
				}
			}
			if(ans.size() != n){
				cout << "-1" << endl;
				return 0;
			}
			else{
				for(auto i : ans){
					cout << i.fi <<" " << i.se << endl;
				}
				return 0;
			}
		}
	}
	rep(i, 1, n + 1){
		rep(j, 1, n + 1){
			if(a[i][j] != 'E'){
				ans.pb(mp(i, j));
				break;
			}
		}
	}
	for(auto i :ans){
		cout << i.fi <<" " << i.se << endl;
	}
	return 0;
}