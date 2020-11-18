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
int a[1000000 + 10];
vi ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	//cin >> T;
	T = 1;
	while(T --){
		int n;
		cin >> n;
		rep(i, 1, n + 1) cin >> a[i];
		sort(a + 1, a + 1 + n);
		rep(i, 1, n / 2+ 1){
			ans.pb(a[i + n / 2]);
			ans.pb(a[i]);
		}
		if(n % 2 == 1) ans.pb(a[n]);
		int cnt = 0;
		rep(i, 1, (int)ans.size() - 1){
			if(ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) cnt ++;
		}
		cout << cnt << endl;
		for(auto i:ans){
			cout << i << " ";
		}
	}
	return 0;
}