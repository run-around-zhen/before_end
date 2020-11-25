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
	if(n > m) swap(n, m);
	if(sg[n][m] != -1) return sg[n][m];
	if(n == 0) return sg[n][m] = 0;
	int vis[1010];
	memset(vis, false, sizeof(vis));
	rep(i, 1, m + 1){
		int x = m - i * n;
		if(x < 0) break;
		int y = n;
		if(x > y) swap(x, y);
		vis[get(x, y)] = true;
	}
	rep(i, 0, 1010){
		if(!vis[i]){
			return sg[n][m] = i;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	// memset(sg, -1, sizeof(sg));
	// rep(i, 1, 20){
	// 	rep(j, i + 1, 20){
	// 		if(get(i, j) == 0) {
	// 			dd(i);dd(j);de((__gcd(j , i)));
	// 		}
	// 	}
	// }
	int n, m;
	while(cin >> n >> m){
		if(n + m == 0) break;
		if(n > m) swap(n, m);
		if(m >= 2 * n) {
			cout << "Stan wins" << endl;
			continue;
		}
		int flag = 0;
		int cnt = 0;
		while(m && n){
			if(n > m) swap(n, m);
			if(m >= 2 * n){
				flag = 1;
				if(cnt % 2 == 0){
					cout << "Stan wins" << endl;
				}
				else{
					cout << "Ollie wins" << endl;
				}
			}
			m -= n;
			cnt ++;
		}
		if(flag) continue;
		if(cnt % 2 == 1){
			cout << "Stan wins" << endl;
		}
		else{
			cout << "Ollie wins" << endl;
		}
	}
	return 0;
}