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
int num = 0;
pii ans[10000];
map<ll, int> cnt;
ll solve(ll i){
	if(cnt[i]) return cnt[i];
	if(i == 1){
		num ++;
		ans[num].fi = 0;
		ans[num].se = 0;
		cnt[i] = num;
		return num;
	}
	ll mid = i / 2;
	int t1 = solve(i - mid);
	int t2 = solve(mid);
	num ++;
	ans[num].fi = t1;
	ans[num].se = t2;
	cnt[i] = num;
	return num;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		ll n;
		cin >> n;
		cnt.clear();
		num = 0;
		solve(n);
		cout << num << endl;
		rep(i, 1, num + 1){
			cout << ans[i].fi - 1<< " " << ans[i].se - 1<< endl;
		}
		cout << num  - 1<< endl;
	}
	return 0;
}