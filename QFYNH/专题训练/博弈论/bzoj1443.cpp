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
const int N = 105;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
char maze[N][N];
int n, m, id[N][N], now, px[N][N], py[N][N];
bool pd, v[N][N], ed[N][N];
bool dfs(int x, int y){
	id[x][y] = now;
	if(px[x][y] && id[px[x][y]][py[x][y]] != now) return dfs(px[x][y], py[x][y]);
	for(int i = 0; i < 4; i ++){
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if(!px[xx][yy] && maze[xx][yy] == '.' && id[xx][yy] != now){
			px[xx][yy] = x;
			py[xx][yy] = y;
			px[x][y] = xx;
			py[x][y] = yy;
			return 1;
		}
	}
	rep(i, 0, 4){
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if(maze[xx][yy] == '.' && id[xx][yy] != now && dfs(xx, yy)){
			px[xx][yy] = x;
			py[xx][yy] = y;
			px[x][y] = xx;
			py[x][y] = yy;
			return 1;
		}
	}
	return 0;
}
void dfs2(int x, int y){
	if(ed[x][y]) return ;
	v[x][y] = 1;
	ed[x][y] = 1;
	rep(i, 0, 4){
		int xx = dir[i][0] + x;
		int yy  =dir[i][1]+ y;
		if(maze[xx][yy] == '.' && px[xx][yy]) dfs2(px[xx][yy], py[xx][yy]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			cin >> maze[i][j];
		}
	}
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			if(maze[i][j] == '.' && !px[i][j]){
				now ++;
				dfs(i, j);
			}
		}
	}
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			if(!px[i][j] && maze[i][j] == '.'){
				v[i][j] = 1;
			}
		}
	}
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			if(!px[i][j] && maze[i][j] == '.') dfs2(i, j);
		}
	}
	int ans = 0;
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			if(v[i][j]) ans ++;
		}
	}
	if(ans) cout << "WIN" << endl;
	else cout << "LOSE" << endl;
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			if(v[i][j]){
				cout << i << " " << j << endl;
			}
		}
	}
	return 0;
}