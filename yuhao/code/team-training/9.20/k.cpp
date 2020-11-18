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
int a[55][55], b[10][10];
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
			rep(j, 1, n + 1){
				cin >> a[i][j];
			}
		}
		int cnt = 0;
		rep(i, 1, 4){
			rep(j, 1, 4){
				cin >> b[i][j];
				if(b[i][j]) cnt ++;
			}
		}
		if(cnt >= 2 || b[1][1] == 0){
			rep(i, 1, n + 1){
				rep(j, 1, n + 1){
					if(j != n){
						cout << "0 ";
					}
					else{
						cout << "0";
					}
				}
				cout << endl;
			}
		}
		else{
			rep(i, 1, n + 1){
				rep(j, 1, n + 1){
					if(j != n){
						cout << a[i][j] << " ";
					}
					else{
						cout << a[i][j];
					}
				}
				cout << endl;
			}
		}
	}
	return 0;
}