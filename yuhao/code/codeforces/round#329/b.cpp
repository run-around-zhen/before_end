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
typedef pair<double, int> pii;
typedef vector<pii> vi;
vi a,aa;
bool cmp(pii a,pii b){
	if(a.fi < b.fi) return true;
	if(a.fi == b.fi) return a.se < b.se;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	double x1, x2;
	cin >> x1 >> x2;
	x1 += 0.0000001;
	x2 -= 0.0000001;
	rep(i, 1, n + 1){
		double  k, b;
		cin >> k >> b;
		a.pb(mp(x1 * k + b, i));
		aa.pb(mp(x2 * k + b, i));
	}
	sort(all(a),cmp);
	sort(all(aa),cmp);
	rep(i, 0, n){
		if(a[i].se != aa[i].se){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}