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
const int N = 1000000;
ll f1[N * 2 + 20], f2[N * 2 + 20];
ll mod1 = 998244353;
ll mod2 = 100000007;
ll a[N * 2 + 20];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	f1[1] = f2[1] = 1, f1[2] = f2[2] = 2;
	rep(i, 3, N * 2 + 10){
		f1[i] = (f1[i - 1] + f1[i - 2]) % mod1;
		f2[i] = (f2[i - 1] + f2[i - 2]) % mod2;
	}
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		ll sum1 = 0, sum2 = 0;
		ll res1 = 0, res2 = 0;
		rep(i, 1, n + 1) {
			int x;
			cin >> x;
			sum1 = (sum1 + f1[i] * x) % mod1;
			sum2 = (sum2 + f2[i] * x) % mod2;
		}
		int m;
		cin >> m;
		rep(i, 1, m + 1){
			int x;
			cin >> x;
			res1 = (res1 + f1[i] * x) % mod1;
			res2 = (res2 + f2[i] * x) % mod2;
		}
		ll cnt1 = sum1 * res1 % mod1;
		ll cnt2 = sum2 * res2 % mod2;
		ll ans1 = 0, ans2 = 0;
		int len;
		cin >> len;
		rep(i, 1, len + 1){
			int x;
			cin >> x;
			a[i] = x;
			ans1 = (ans1 + f1[i] * x) % mod1;
			ans2 = (ans2 + f2[i] * x) % mod2;
		}
		int pos = -1;
		rep(i, 1, len + 1){
			if(a[i - 1] == 1 || a[i + 1] == 1 || a[i] == 1) continue;
			if((ans1 + f1[i]) % mod1 == cnt1){
				pos = i;
				break;
			}
		}
		if(pos == -1) while(1);
		cout << pos << endl;
	}
	return 0;
}
/*
2
3 1 0 1
4 0 0 0 1
6 0 1 0 0 0 1
3 1 0 1
4 0 0 0 1
6 0 1 0 0 0 1
*/
