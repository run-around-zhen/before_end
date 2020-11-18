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
	cout << setiosflags(ios::fixed);
	cout << setprecision(10);
	double m, r;
	cin >> m >> r;
	double ans = 0.0;
	rep(i, 1, m + 1){
		rep(j, 1, m + 1){
			if(i == j) ans += 2 * r;
			else ans += abs(i - j) * 2 * r+ sqrt(2) * r;
		}
	}
	cout << ans / (double)(m * m) << endl;
	return 0;
}