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
int sg[1010][1010];
int get(int n, int m){
	if(sg[n][m] != - 1) return sg[n][m];
	if(n == 0) return sg[n][m] = 0;
	if(n <= m * 2) return sg[n][m] = 1;
	int vis[1010];
	memset(vis, false, sizeof(vis));
	rep(i, 1, min(n, 2 * m + 1)){
		vis[get(n - i, i)] = true;
	}
	rep(i, 0, 1010){
		if(!vis[i]){
			return sg[n][m] = i;
		}
	}
}
ll f[1010];
map<ll, int> ma;
int main(){
	//ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	// memset(sg, -1, sizeof(sg));
	// rep(i, 1, 20){
	// 	int ans = 0;
	// 	dd(i);
	// 	rep(j, 1, i){
	// 		if(!get(i - j, j)) ans = 1;
	// 	}
	// 	if(ans){
	// 		cout << "YES" << endl;
	// 	}
	// 	else{
	// 		cout <<"NO" << endl;
	// 	}
	// }
	f[0] = f[1] = 1;
	rep(i, 2, 40){
		f[i] = f[i - 1] + f[i - 2];
		ma[f[i]] = true;
		dd(f[i]);
	}
	int n;
	while(cin >> n){
		if(n == 0) break;
		if(ma[n]){
			cout << "Second win" << endl;
		}
		else cout << "First win" << endl;
	}
	return 0;
}