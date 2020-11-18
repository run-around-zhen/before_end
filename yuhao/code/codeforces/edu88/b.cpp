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
char maze[110][1100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		rep(i, 1, n + 1){
			rep(j, 1, m + 1){
				cin >> maze[i][j];
			}
		}
		ll ans = 0;
		rep(i, 1, n + 1){
			int sum = 0;
			rep(j, 1, m + 1){
				if(maze[i][j] == '.') sum ++;
				else{
					if(sum == 1){
						ans += x;
					}
					else{
						if(x + x <= y){
							ans += x * sum;
						}
						else{
							ans += (sum / 2) * y + (sum % 2) * x;
						}
					}
					sum = 0;
				}
			}
			if(sum == 1){
				ans += x;
			}
			else{
				if(x + x <= y){
					ans += x * sum;
				}
				else{
					ans += (sum / 2) * y + (sum % 2) * x;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}