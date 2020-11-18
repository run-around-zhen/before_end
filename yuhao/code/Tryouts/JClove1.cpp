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
ll mod = 1e9 + 7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	ll sum1 =0 ;
	ll sum2 = 0;
	string s, t;
	cin >> s >> t;
	rep(i, 0, s.size()){
		sum1 = sum1 * 2 + s[i] - '0';
	}
	rep(i, 0, t.size()){
		sum2 = sum2 * 2 + t[i] - '0';
	}
	ll ans = 0;
	//cout << sum1 << " " << sum2 << endl;
	while(sum1 > 0 && sum2 > 0){
		ll a = sum1 / 2;
		ll b = sum2 / 2;
		ans += a * (sum2 - b) + b * (sum1 - a);
		sum1 /= 2;
		sum2 /= 2;
	}
	//cout << ans << endl;
	cout << ans % mod << endl;
	return 0;
}
