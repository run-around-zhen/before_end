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
char maze[100][100];
bool x[100], y[100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;
		memset(x, false,sizeof(x));
		memset(y, false,sizeof(y));
		rep(i, 1, n + 1){
			rep(j, 1, m + 1){
				cin >> maze[i][j];
				if(maze[i][j] == '1'){
					x[i] = true;
					y[j] = true;
				}
			}
		}
		int ans= 0, ans1 = 0;
		rep(i, 1, n + 1){
			if(!x[i]) ans ++;
		}
		rep(i, 1, m + 1){
			if(!y[i]) ans1 ++;
		}
		if(min(ans, ans1) % 2 == 1){
			cout << "Ashish" << endl;
		}
		else{
			cout <<"Vivek" << endl;
		}
	}
	return 0;
}