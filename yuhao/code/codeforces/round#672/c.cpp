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
ll a[1000000 + 10], b[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n, q;
		cin >> n >> q;
		rep(i, 0, n + 2) a[i] = b[i] = 0;
		rep(i, 1, n + 1) cin >> a[i];
		b[1] = a[1];
		rep(i, 2, n + 1) {
			b[i] = a[i] - a[i - 1];
		}
		ll ans = 0;
		rep(i, 1, n + 1){
			if(b[i] > 0) ans += b[i];
		}
		cout << ans << endl;
	//	int q;
	//	cin >> q;
		while(q --){
			int l, r;
			cin >> l >> r;
			if(l == r){
				cout << ans << endl;
				continue;
			}
			if(l > r) swap(l, r);
			swap(a[l], a[r]);
			if(l == r - 1){
				if(b[l] > 0) ans -= b[l];
				//if(l != n && b[l + 1] > 0) ans -= b[l + 1];
				if(b[r] > 0) ans -= b[r];
				if(r != n && b[r + 1] > 0) ans -= b[r + 1];
				b[l] = a[l] - a[l - 1];
				if(l != n) b[l + 1] = a[l + 1] - a[l];
				b[r] = a[r] - a[r - 1];
				if(r != n) b[r + 1] = a[r + 1] - a[r];
				if(b[l] > 0) ans += b[l];
				//if(b[l + 1] > 0) ans += b[l + 1];
				if(b[r] > 0) ans += b[r];
				if(b[r + 1] > 0) ans += b[r + 1];
				cout << ans << endl;
				continue;
			}
			if(b[l] > 0) ans -= b[l];
			if(l != n && b[l + 1] > 0) ans -= b[l + 1];
			if(b[r] > 0) ans -= b[r];
			if(r != n && b[r + 1] > 0) ans -= b[r + 1];
			b[l] = a[l] - a[l - 1];
			if(l != n) b[l + 1] = a[l + 1] - a[l];
			b[r] = a[r] - a[r - 1];
			if(r != n) b[r + 1] = a[r + 1] - a[r];
			if(b[l] > 0) ans += b[l];
			if(b[l + 1] > 0) ans += b[l + 1];
			if(b[r] > 0) ans += b[r];
			if(b[r + 1] > 0) ans += b[r + 1];
			cout << ans << endl;
		}  
	}
	return 0;
}