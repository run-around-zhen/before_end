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
vi ans;
ll a, b, c;
ll check(ll i){
	ll ans = 1;
	rep(j, 0, a) ans = ans * i;
	return ans * b + c;
}
ll cal(ll i){
	if(i > 0 && i < 1e9){
		ll  res = 0;
		while(i){
			res += i % 10;
			i /= 10;
		}
		return res;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> a >> b >> c;
	rep(i, 1, 100){
		if(cal(check(i)) == i) ans.pb(check(i));
	}
	//cout << check(10) << endl;
	sort(all(ans));
	cout << ans.size() << endl;
	for(auto i : ans){
		cout << i << " ";
	}
	return 0;
}