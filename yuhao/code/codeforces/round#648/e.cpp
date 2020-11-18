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
ll a[10000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	ll ans = 0;
	rep(i, 1, n + 1){
		ans = max(ans, a[i]);
		rep(j, i + 1, n + 1){
			ans = max(ans,(a[i] | a[j]));
			rep(k ,j + 1, n + 1){
				ans = max(ans, (a[i] | a[j] | a[k] ));
			}
		}
	}
	cout << ans << endl;
	return 0;
}