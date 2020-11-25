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
int sg[1010];
int get(int n){
	if(sg[n] != - 1) return sg[n];
	if(n == 0) return sg[n] = 0;
	int vis[1010];
	memset(vis, false, sizeof(vis));
	rep(i, 0, n){
		vis[get(i)] = true;
	}
	rep(i, 1, n){
		vis[get(i) ^ get(n - i)] = true;
	}
	rep(i, 0, 1010){
		if(!vis[i]) return sg[n] = i;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	// memset(sg, -1, sizeof(sg));
	// rep(i, 1, 101) {
	// 	dd(i);
	// 	de(get(i));
	// }
	int _;
	while(cin >> _){
		rep(cas, 1, _ + 1){
			int n;
			cin >> n;
			int ans = 0;
			rep(i, 1, n + 1) {
				int x;
				cin >> x;
				if(x % 4 == 0) ans ^= (x - 1);
				else if(x % 4 == 3) ans ^= (x + 1);
				else ans ^= x;
			}
			if(ans){
				cout << "Alice" << endl;
			}
			else{
				cout << "Bob" << endl;
			}
		}
	}
	return 0;
}