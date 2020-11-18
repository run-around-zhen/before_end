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
	int n;
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	sort(a + 1, a + 1 + n);
	ll ans = 1e18;
	int flag = 0;
	rep(i, 1, 100001){
		ll cost = 1;
		ll sum = 0;
		rep(j, 1, n + 1){
			if(cost > 1e10) {
				flag = 1;
				break;
			}
			sum += abs(cost - a[j]);
			cost *= i;

		}
		if(flag) break;
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}