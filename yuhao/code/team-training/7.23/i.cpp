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
typedef vector<pii> vi;
int n, m, q;
int max_x, min_x, max_y, min_y;
string s;
int cnt;
int maze[410][410], a[410][410], b[410][410];
bool vis[410 * 410];
vector<int> v_vis;
vi va, vb;
void dfs(int x, int y, int now, int siz){
	if(y < 0) while(1);
	//cout << x << " " << y << " " << now << endl;
	if(now == siz) return;
	max_x = max(max_x, x);
	max_y = max(max_y, y);
	min_x = min(min_x, x);
	min_y = min(min_y, y);
 	if(s[now] == 'R') {
		a[x][y] ++;
		va.pb(mp(x, y));
		dfs(x + 1, y, now + 1, siz);
	}
	else if(s[now] == 'U'){
		b[x][y] ++;
		vb.pb(mp(x, y));
		dfs(x, y + 1, now + 1, siz);
	}
	else if(s[now] == 'L'){
		a[x - 1][y] ++;
		va.pb(mp(x - 1, y));
		dfs(x - 1, y, now + 1, siz);
	}
	else if(s[now] == 'D'){
		b[x][y - 1] ++;
		vb.pb(mp(x - 1, y));
		dfs(x, y - 1, now + 1, siz);
	}
	return ;
}
void bfs(int x, int y){
	if(y < min_y) return;
	//if(x < 0 || y < 0 || x > 400 || y > 400) while(1);
	bfs(x, y - 1);
	cnt += a[x][y];
	if(cnt % 2 == 1){
		if(!vis[maze[x][y]]){
			vis[maze[x][y]] = true;
			v_vis.pb(maze[x][y]);
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		cin >> n >> m >> q;
		rep(i, 0, n){
			rep(j, 0, m){
				cin >> maze[i][j];
			}
		}
		while(q --){
			int x, y;
			cin >> x >> y;
			cin >> s;
			min_x = 1e9;
			min_y = 1e9;
			max_x = -1e9;
			max_y = -1e9;
			for(auto i: va){
				a[i.fi][i.se] = 0;
			}
			for(auto i: vb){
				b[i.fi][i.se] = 0;
			}
			for(auto i: v_vis){
				vis[i] = 0;
			}
			va.clear(); vb.clear(); v_vis.clear();
			dfs(x, y, 0, s.size());
			//cout << min_y << " " << max_y << " " << min_x << " " << max_x << endl;
  			if(min_y == max_y || min_x == max_x){
				cout << "0" << endl;
				continue;
			}
			rep(i, min_x, max_x){
				cnt = 0;
				bfs(i, max_y);
			}
			cout << v_vis.size() << endl;			
		}
	}
	return 0;
}
/*
1
3 3 1
1 2 3
1 1 2
7 8 9
0 0 RL
*/