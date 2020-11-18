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
	ll A, B, C, D;
	cin >> A >> B >> C >> D;
	ll ans = 0;
	rep(i, 1, 1000){
		rep(j, 1, 1000){
			if(i + j >= 1000) break;
			if(__gcd(i, j) != 1) continue;
			if(i > B || j > D) continue;
			ll l = A / i;
			if(A % i != 0) l++;
			ll r = B / i;
			ll l1 = C / j;
			if(C % j != 0) l1 ++;
			ll r1 = D / j;
			ans += max(0ll, min(r1, r) - max(l, l1) + 1);
		}
	}
	cout << ans << endl;
	return 0;
}