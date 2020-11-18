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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, a1, a2, a3, b1, b2 ,b3;
	cin >> n ;
	cin >> a1 >> a2 >> a3;
	cin >> b1 >> b2 >> b3;
	int ans = 0;
	ans += min(a3, b1);
	ans += min(a1, b2);
	ans += min(a2, b3);
	int res = 0;
	res += max(0,min(b2, -(b1 + b3 - a1)));
	res += max(0,min(b3, -(b1 + b2 - a2)));
	res += max(0,min(b1, -(b2 + b3 - a3)));
	cout << res << " ";
	cout << ans << endl;
	return 0;
}