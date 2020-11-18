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
int a[310][310], b[310][310];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n, m ;
		cin >> n >> m;
		rep(i, 1, n + 1){
			rep(j, 1, m + 1) cin >> a[i][j];
		}
		rep(i, 1, n + 1){
			rep(j, 1, m + 1){
				if((i == 1 || i == n)&& (j == 1 || j == m)) b[i][j] = 2;
				else if(i == 1 || j == 1 || i == n || j == m) b[i][j] = 3;
				else b[i][j] = 4;
			}
		}
		int flag = 0;
		rep(i, 1, n  + 1){
			rep(j, 1, m + 1){
				if(a[i][j] > b[i][j]){
					flag = 1;
					break;
				}
			}
		}
		if(!flag){
			cout << "YES" << endl;
			rep(i, 1, n + 1){
				rep(j, 1, m + 1) cout << b[i][j] << " ";
				cout << endl;
			}
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}