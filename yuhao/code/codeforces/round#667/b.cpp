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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		ll a, b, x ,y, n;
		cin >> a >> b >> x >> y >> n;
		if(a - x + b - y <= n){
			cout << x * y << endl;
		}
		else{
			if(a > b){
				swap(a, b);
				swap(x, y);
			}
			if(a == b){
				if(x > y) swap(x, y);
			}
			ll ans = 1e18;
			if(a - x > n){
				ans = min(ans, (a - n) * b);
			}
			else{
				ans = min(ans, x * (b - (n - (a - x))));
			}
			if(b - y > n){
				ans = min(ans, (b - n) * a);
			}
			else{
				ans = min(ans, y * (a - (n - (b - y))));
			}
			cout << ans << endl;
		}
	}
	return 0;
}