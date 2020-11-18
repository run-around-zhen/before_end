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
ll maze[310][310], sum1[310][310], sum[310][310];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		memset(sum1, 0,sizeof(sum1));
		memset(sum, 0, sizeof(sum));
		memset(maze, 0, sizeof(maze));
		int n, k;
		cin >> n >> k;
		int cnt = 0;
		rep(i, 1, n + 1){
			rep(j, 1, n + 1){
				if(i + j - 1 > n) continue;
				if(cnt == k) break;
				maze[j][i + j - 1] = 1;
				cnt ++;
			}
			rep(j, 1, n + 1){
				if(i + j - 1 > n) continue;
				if(cnt == k) break;
				if(j == i + j - 1) continue;
				maze[i + j - 1][j] = 1;
				//cout << i + j - 1 << " " << j << endl;
				cnt ++;
			}
		}
		//cout << cnt << endl;
		/*rep(i, 1, n + 1){
			rep(j, 1, n + 1){
				if(i + j - 1 > n) continue;
				if(cnt == k) break;
				if(j == i + j - 1) continue;
				maze[i + j - 1][j] = 1;
				//cout << i + j - 1 << " " << j << endl;
				cnt ++;
			}
		}*/
		int res1 = 1e9, res2 = -1e9, res3 = 1e9, res4 = -1e9;
		rep(i, 1, n + 1){
			rep(j, 1, n + 1){
				if(maze[i][j]){
					sum[i][j] = 1;
				}
				if(maze[j][i]) sum1[j][i] = 1;
				sum[i][j] += sum[i][j - 1];
				sum1[j][i] += sum1[j - 1][i];
			}
		}
		rep(i, 1, n + 1){
			res1 = min(res1, sum[i][n]);
			res2 = max(res2, sum[i][n]);
			res3 = min(res3, sum1[n][i]);
			res4 = max(res4, sum1[n][i]);
		}
		cout << (res1 - res2) * (res1 - res2) + (res3 - res4) * (res3 - res4) << endl;
		rep(i, 1, n + 1){
			rep(j, 1, n + 1){
				cout << maze[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}