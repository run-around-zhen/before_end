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
int sum[1000000 + 10];
char a[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n, p, k;
		cin >> n >> p >> k;
		rep(i, 1, n + 1) cin >> a[i];
		int x, y;
		cin >> x>> y;
		per(i, 1, n + 1){
			if(a[i] == '0') sum[i] = sum[i + k] + x;
			else sum[i] = sum[i + k];
		}
		int ans = 1e9;
		rep(i, 0, n - p + 1){
			ans = min(ans, sum[p + i] + i * y);
		}
		cout << ans << endl;
		rep(i, 1, n + 1){
			a[i] = sum[i] = 0;
		}
	}
	return 0;
}