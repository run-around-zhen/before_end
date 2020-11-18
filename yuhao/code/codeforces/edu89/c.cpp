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
int a[100][100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n, m;
		cin >> n >> m;
		rep(i, 1, n + 1){
			rep(j, 1, m + 1){
				cin >> a[i][j];
				//v[(i - 1) * m + j].pb(mp(i, j));
			}
		}
		int ans = 0;
		rep(i, 0, (n + m - 1) / 2){
			int ans1 = 0, ans2 = 0;
			rep(k, 1, n + 1){
				rep(q, 1, m + 1){
					if( k + q == i + 2|| n + m - q - k == i ){
						if( a[k][q] == 0 ) ans1 ++;
						else ans2 ++;
					}
				}
			}
			ans += min(ans1, ans2);
		}
		cout <<ans << endl;
	}
	return 0;
}