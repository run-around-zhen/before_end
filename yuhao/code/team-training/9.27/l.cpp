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
char a[110][110];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n, m, k;
		cin >> n >> m >> k;
		rep(j, 1, m * 2 + 1){
			rep(i, 1, 2 * n + m * 2 + 2){
				if(i <= m * 2 - j + 1){
					a[j][i] = '.';
					continue;
				}
				if(j % 2 == 1){
					if(i % 2 == 1){
						a[j][i] = '+';
					}
					else{
						a[j][i] = '-';
					}
				}
				else{
					if(i % 2 == 1){
						a[j][i] = '.';
					}
					else{
						a[j][i] = '/';
					}
				}
			}
		}
		rep(j, m * 2 + 1, m * 2 + 1 + 2 * k + 1){
			rep(i, 1, 2 * n + 2){
				if((j - m * 2) % 2 == 1){
					if(i % 2 == 1){
						a[j][i] = '+';
					}
					else{
						a[j][i] = '-';
					}
				}
				else{
					if(i % 2 == 1){
						a[j][i] ='|';
					}
					else{
						a[j][i] ='.';
					}
				}
			}
		}
		for(int t = 0; t < 2 * m; t ++){
			rep(j, 1, 2 * k + 2){
				if(t % 2 == 0){
					if(j % 2 == 1){
						a[j + t][2 * m + 2 * n + 1 - t] = '+';
					}
					else{
						a[j + t][2 * m + 2 * n + 1 - t] = '|';
					}
				}
				else{
					if(j % 2 == 1){
						a[j + t][2 * m + 2 * n + 1 - t] = '/';
					}
					else{
						a[j + t][2 * m + 2 * n + 1 - t] = '.';
					}
				}
			}
		}
		rep(i, 0, 2 * m){
			rep(j, 0, i + 1){
				a[2 * k + 2 + i][2 * m + 2* n + 1 - j] = '.';
			}
		}
		rep(i, 1, 2 * m + 2 * k + 2){
			rep(j, 1, 2 * m + 2 * n + 2){
				 cout << a[i][j] ;
			}
			cout << endl;
		}
	}

	return 0;
}
