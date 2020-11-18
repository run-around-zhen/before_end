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
ll dp[200000 + 10][5];
int a[200000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		ll res = 0;
		rep(i, 1, n + 1){
			cin >> a[i];
			if(i % 2 == 1) res += a[i];
		}
		ll maxn = 0, ans = 0, ans1 = 0;
		for(int i = 1; i <= n ;i += 2){
			ans += a[i + 1] - a[i];
			ans1 += a[i + 1] - a[i + 2];
			if(i < n) maxn = max(maxn, ans);
			if(i + 1 < n)maxn = max(maxn, ans1);
			if(ans < 0) ans = 0;
			if(ans1 < 0) ans1 = 0;
		}
		cout << res + maxn << endl;
	}
	
	return 0;
}