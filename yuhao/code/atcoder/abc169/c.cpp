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
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	long double a, b;
	cin >> a >> b;
	//ll ans = a / 100 * ((ll)(b * 100) % 10) + a / 10 * ((ll)(b * 100) / 10 % 10) + a * ((ll) (b * 100) / 100);
	printf("%lld", (ll)floor(a * b));
	return 0;
}