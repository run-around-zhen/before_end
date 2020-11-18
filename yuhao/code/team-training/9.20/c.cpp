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
ll a[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		ll n, m, k;
		cin >> n >> m >> k;
		rep(i, 1, m + 1) cin >> a[i];
		sort(a + 1, a + 1 + m);
		ll ans = k - 1;
		rep(i, 2, m + 1){
			ans += 2 * abs(a[i] - k);
		}
		if(k > a[1]) ans += k - 1;
		else ans += abs(a[1] - k) + a[1] - 1;
		cout << ans << endl;
	}
	return 0;
}