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
typedef vector<ll> vi;
int a[2]={-1,1};
ll sum[1000000 + 10];
int n;
vi v;
ll get(int l, int r){
	v.clear();
	v.pb(sum[l]);
	v.pb(sum[r] - sum[l]);
	v.pb(sum[n] - sum[r]);
	sort(all(v));
	//cout <<v[0] << " " << v[1] << " " << v[2] << endl;
	return v[2] - v[0];
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	srand(time(0));
	cin >> n;
	rep(i, 1, n + 1) {
		cin >> sum[i] ;
		sum[i] += sum[i - 1];
	}
	int pos1 = n / 3;
	int pos2 = n / 3 * 2;
	rep(i, 1, n + 1){
		if(sum[i] - sum[n]/3 <= 0 && sum[i + 1] - sum[n]/3 >= 0){
			pos1 = i;
		}
		if(sum[i] - sum[n]/3 * 2 <= 0 && sum[i + 1] - sum[n]/3 * 2>= 0){
			pos2 = i;
		}
	}
	ll ans = sum[n];
	rep(i, 1, 1000000 + 10){
		int s1 = rand()%100;
		int s2 = rand()%100;
		int l = pos1 + a[rand()%2] + s1;
		int r = pos2 + a[rand()%2] + s2;
		r = min(n - 1, r);
		r = max(2, r);
		l = min(l, r - 1);
		l = max(1, l);
	//	cout << l << " " << r <<endl;
		ans = min(ans, get(l, r));
	}
	cout << ans << endl;
}