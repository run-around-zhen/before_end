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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m >> q;
	queue<pair<int,int>>q, q1;
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			cin >> maze[i][j];
		}
	}
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			int flag = 0;
			rep(k, 0, 4){
				int x = i + dir[k][0];
				int y = j + dir[k][1];
				if(check(x, y)){
					if(maze[x][y] == maze[i][j]) flag = 1;
				}
			}
			if(flag) {
				q.push(mp(i, j));
				vis[i][j] = true;
			}
		}
	}
	int time = 1;
	while(1){
		while(!q.empty())
			int x = q.front().fi;
			int y = q.front().se;
			q.pop();
			rep(k, 0, 4){
				int xx = x + dir[k][0];
				int yy = y + dir[k][1];
				if(check(xx, yy) && !vis[xx][yy]){
					q1.push(xx, yy);
					ans[xx][yy] = time;
					vis[xx][yy] = true;
				}
			}
		}
		while(!q1.empty()){
			q.push(q1.front());
		}
		/*while(!q1.empty())
			int x = q.front().fi;
			int y = q.front().se;
			q1.pop();
			int flag = 0;
			rep(k, 0, 4){
				int xx = x + dir[k][0];
				int yy = y + dir[k][1];
				if(check(xx, yy)){
					q.push(xx, yy);
				}
			}
		}*/
	}
	return 0;
}