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
int a[100000 + 10];
int res[100000 + 10];
bool vis[1000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		memset(vis, false,sizeof(vis));
		rep(i, 1, n + 1) cin >> a[i];
		int now = 1;
		rep(i, 1, n + 1) {
			int flag = 0;
			rep(j, 1, n + 1){
				if(a[j] == -1) {
					flag = 1;
					a[j] = 1;
				}
				if(a[j] == 1) {
					flag = 1;
					break;
				}
			}
			if(!flag) break;
			per(j, 1, n + 1){
				if(a[j] == 1) {
					res[j] = now ++;
				}
				if(a[j] > 0) a[j] --;
			}
		}
		rep(i, 1, n + 1){
			if(res[i] <= 0) res[i] = now ++;
		}
		rep(i, 1, n + 1) {
			if(i == n ) cout << res[i] ;
			else cout << res[i] << " ";
		}
		cout << endl;
	}
	return 0;
}