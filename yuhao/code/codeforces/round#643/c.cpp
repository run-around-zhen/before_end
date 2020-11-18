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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll ans = (b - a + 1) * (c - b + 1) * ( d - c + 1);
	rep(i, c, d + 1){
		if(a + b > i ) continue;
		ll begin = i - ( a + b);
		ll res1 = b - a,res2 = c - b;
		if(res1 < res2){
			swap(res1, res2);
		}
		if(res1 >= begin && res2 >= begin){
			ans = ans - (2 + begin) * (begin + 1) / 2;
		}
		else if(res1 >= begin && res2 <= begin){
				ans -= (2 * begin - res2 + 2) * ( res2 + 1) /2;
		}
		else if(begin >= res1 + res2){
			ans = ans - ( res1 + 1) *( res2 + 1);
		}
		else{
			ans -= (res1 + 1)  * (res2 + 1);
			ll len = res1 + res2 -begin;
			ans += len * ( len + 1)/2;
		}
	}
	cout << ans << endl;
	return 0;
}