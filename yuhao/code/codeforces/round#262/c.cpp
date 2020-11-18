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
int n, m, k;
map<ll, int > ma;
ll a[200000 + 10];
bool check(ll h){
	ma.clear();
	ll sum = 0;
	ll cnt = 0;
	rep(i, 1, n + 1){
		sum += ma[i];
		if(sum + a[i] >= h) continue;
		else{
			cnt += h - (sum + a[i]);
			ma[i + k] -= h - (sum + a[i]);
			sum += h - (sum + a[i]);
		} 
	}
	//cout << cnt << endl;
	return cnt <= m;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, n + 1) cin >> a[i];
	ll l = 1,r = 2e9;
	ll ans = 0;
	//cout << check(3) << endl;
	//return 0;
	while(l <= r){
		ll mid = (l + r) / 2;
		//cout << l << " " << r << " " << mid << endl;
		if(check(mid)){
			ans = max(ans, mid);
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}