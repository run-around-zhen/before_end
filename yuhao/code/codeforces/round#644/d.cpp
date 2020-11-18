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
string s[100];
int n ;
bool vis[60][60];
bool check(int x, int y){
	if(x >= 0 && y >= 0 && x < n && y < n && !vis[x][y] && s[x][y] == '1'){
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
		memset(vis,false,sizeof(vis));
		cin >> n;
		rep(i, 0, n){
			cin >> s[i];
		}
		queue<pair<int,int> > q;
		rep(i, 0, n - 1){
			if(s[i][n - 1] == '1') {
				q.push(mp(i, n - 1));
				vis[i][n - 1] = true;
			}
		}
		rep(i, 0, n){
			if(s[n - 1][i] == '1') {
				q.push(mp(n - 1, i));
				vis[n - 1][i] = true;
			}
		}
		while(q.size() != 0){
			int xx = q.front().fi;
			int yy = q.front().se;
		//	cout << xx << " " << yy << endl;
			q.pop();
			if(check(xx - 1, yy)){
				q.push(mp(xx - 1, yy));
			}
			if(check(xx, yy - 1)){
				q.push(mp(xx, yy - 1));
			}
		}
		int flag = 0;
		rep(i, 0, n){
			rep(j, 0, n){
				if(s[i][j] == '1' && !vis[i][j]){
					flag = 1;
				}
			}
		}
		/*rep(i, 0, n){
			rep(j, 0, n){
				if(s[i][j] == '1'){
					int flag1 = 0,flag2 = 0;
					rep(k, j + 1, n) if(s[i][k] == '0') flag1 = 1;
					rep(k, i + 1, n) if(s[k][j] == '0') flag2 = 1;
					if(flag1 == 1 && flag2 == 1){
						flag = 1;
						break;
					}
				}
			}
		}*/
		if(flag){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
	}
	return 0;
}