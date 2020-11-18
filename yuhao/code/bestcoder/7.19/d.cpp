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
int n;
int a[510][510];
bool cal(int x, int y){
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
int dir[24][2] = {1, 0, 2, 0, 3, 0, -1, 0, -2, 0, -3 ,0, 0, 3, -1, 2, 0, 2, 1, 2, -2, 1, -1,1, 0, 1, 1, 1, 2, 1, -2, -1, -1, -1, 0, -1, 1, -1,2, -1,-1, -2,0, -2 ,1, -2, 0, -3};
int check(int x, int y){
	priority_queue<int>q;
	rep(i, 0, 24){
		int xx = dir[i][0] + x;
		int yy = dir[i][1] + y;
		if(cal(xx, yy)) q.push(a[xx][yy]);
	}
	int cnt = 0, number = 0, tot = 0;
	//if(q.size() < 8) return 1e9;
	int sum = a[x][y];
	number ++;
	while(1){
		tot += sum;
		cnt ++;
		if(tot >= 8 * number * number) {
			if(!q.empty()){
				sum += q.top();
				q.pop();
			}
			number ++;
			
		}
		if(number == 9) break;
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int x, y;
		cin >> n >> x >> y;
		rep(i, 1, n + 1) rep(j, 1, n + 1) cin >> a[i][j];
		int ans = 1e9;
		rep(i, 1, n + 1){
			rep(j, 1, n + 1){
				ans = min(ans, check(i, j) + (abs(i - x) + abs(j - y) + 1)/ 2);
			}
		}
		cout << ans << endl;
	}
	return 0;
}