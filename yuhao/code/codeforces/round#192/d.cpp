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
int n, m;
bool vis[1010][1010];
char maze[1010][1010];
int dir[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
int dis[1010][1010];
bool check(int x, int y){
	if(x > 0 && y > 0 && x <= n && y <= m && !vis[x][y] && maze[x][y] != 'T'){
		vis[x][y] = true;
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	pair<int, int> pos, pos1;
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			cin >> maze[i][j];
			if(maze[i][j] =='E') {
				pos.fi = i;
				pos.se = j;
			}
			if(maze[i][j] =='S') {
				pos1.fi = i;
				pos1.se = j;
			}
		}
	}
	queue<pii>q;
	q.push(pos);
	vis[pos.fi][pos.se] = true;
	while(!q.empty()){
		int x = q.front().fi;
		int y = q.front().se;
		q.pop();
		rep(i, 0, 4){
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if(check(xx, yy)){
				q.push(mp(xx, yy));
				dis[xx][yy] = dis[x][y] + 1;
			}
		}
	}
	ll ans  = 0;
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			if(vis[i][j]&&maze[i][j] >= '0' && maze[i][j] <= '9' && dis[i][j] <= dis[pos1.fi][pos1.se]){
				ans += maze[i][j] -'0';
			}
			//cout << dis[i][j] << " " ;
		}
	}
	cout << ans << endl;
	return 0;
}