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
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
char maze[100][100];
bool vis[100][100];
int n ,m;
bool check(int x, int y){
	if(x >= 1 && y >= 1 && x <= n && y <= m && !vis[x][y] &&maze[x][y] != '#'){
		vis[x][y] = true;
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		cin >> n >> m;
		//cout << n << " " << m << "!!" << endl;
		int flag = 0;
		memset(vis,false,sizeof(vis));
		rep(i ,1 ,n + 1){
			rep(j, 1, m + 1){
				cin >> maze[i][j];
			}
		}
		rep(i, 1, n + 1){
			rep(j, 1, m + 1){
				if(maze[i][j] == 'B'){
					rep(k, 0, 4){
						int x = i + dir[k][0];
						int y = j + dir[k][1];
						if(x >= 1 && y >= 1 && x <= n && y <= m && maze[x][y] == 'G'){
							flag = 1;
							break;
						}
						if(maze[x][y] == '.') maze[x][y] = '#';
					}
				}
			}
		}
		queue<pair<int,int>> q;
		if(maze[n][m] != '#' && maze[n][m] != 'B') {
			q.push(mp(n, m));
			vis[n][m] = true;
		}
		//cout << flag << endl;
		while(!q.empty()){
			int x = q.front().fi;
			int y = q.front().se;
			q.pop();
			rep(k, 0, 4){
				int xx = x + dir[k][0];
				int yy = y + dir[k][1];
				if(check(xx, yy)){
					q.push(mp(xx, yy));
				}
			}
		}
		rep(i, 1, n + 1){
			rep(j, 1, m + 1){
				if(maze[i][j] == 'G' && !vis[i][j]){
					flag = 1;
					break;
				}
			}
		}
		if(flag == 1){
			cout << "No" << endl;
		}
		else{
			cout << "Yes" << endl;
		}
	}
	return 0;
}