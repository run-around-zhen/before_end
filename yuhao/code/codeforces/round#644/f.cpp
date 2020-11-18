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
int acc[55][55];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		memset(acc, 0, sizeof(acc));
		int flag = 1;
		rep(tmp, 0, m){
			memset(acc, 0, sizeof(acc));
			int tt = 0;
			rep(i, 0, n){
				rep(j, 0, a){
					acc[i][(j + tt) % m] = 1;
				}
				tt = (tt + tmp) % m;
			}
			int ff = 0;
			/*rep(i, 0, n){
				rep(j, 0, m){
					cout <<acc[i][j] << " ";
				}
				cout << endl;
			}*/
			rep(i, 0, m){
				int sum = 0;
				rep(j, 0, n){
					sum += acc[j][i];
				}
				if(sum != b){
					ff = 1;
				}
			}
			if(!ff) {
				flag = 0;
				break;
			}
		}
		if(!flag){
			cout << "YES" << endl;
			rep(i, 0, n){
				rep(j, 0, m){
					cout << acc[i][j] ;
				}
				cout << endl;
			}
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}