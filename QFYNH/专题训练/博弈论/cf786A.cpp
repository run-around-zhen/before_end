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
int dp[2][7070];
int f[2][7070];
vi step[2];
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	rep(i, 0, 2){
		int m;
		cin >> m;
		rep(j, 0, m){
			int x;
			cin >> x;
		 	step[i].pb(x);
		}
	}
	memset(dp, -1, sizeof(dp));
	queue<pii> q;
	dp[0][0] = dp[1][0] = 0;
	q.push(mp(0, 0));
	q.push(mp(1, 0));
	while(!q.empty()){
		int x = q.front().fi;
		int y = q.front().se;
		q.pop();
		if(dp[x][y] == 1){
			for(auto i : step[x ^ 1]){
				f[x ^ 1][(y + i) % n] ++;
				if(f[x ^ 1][(y + i) % n] == sz(step[x ^ 1])){
					dp[x ^ 1][(y + i) % n] = 0;
					q.push(mp(x ^ 1, (y + i) % n));
				}
			}
		}
		else{
			for(auto i : step[x ^ 1]){
				if(dp[x ^ 1][(y + i) % n] == -1){
					dp[x ^ 1][(y + i) % n] = 1;
					q.push(mp(x ^ 1, (y + i) % n));
				}
			}
		}
	}
	rep(i, 0, 2){
		per(j, 1, n){
			if(dp[i][j] == -1){
				cout << "Loop" << " ";
			}
			else if(dp[i][j] == 0){
				cout << "Lose" << " ";
			}
			else{
				cout << "Win" << " ";
			}
		}
		// if(dp[i][1] == -1){
		// 		cout << "Loop" << " ";
		// 	}
		// 	else if(dp[i][1] == 0){
		// 		cout << "Lose" << " ";
		// 	}
		// 	else{
		// 		cout << "Win" << " ";
		// 	}
		cout << endl;
	}
	return 0;
}