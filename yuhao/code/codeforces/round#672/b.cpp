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
ll a[1000000 + 10], b[100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n;
		memset(b, 0, sizeof(b));
		cin >> n;
		rep(i, 1, n + 1) cin >> a[i];
		rep(i, 1, n + 1){
			int cnt = 0;
			while(a[i]){
				a[i] /= 2;
				cnt ++;
			}
			b[cnt] ++;
		}
		ll ans = 0;
		rep(i, 0, 33){
			ans += b[i] * (b[i] - 1) / 2;
		}
		cout << ans << endl;
	}
	return 0;
}