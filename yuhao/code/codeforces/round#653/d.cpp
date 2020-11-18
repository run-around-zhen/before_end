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
map<int, int>cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n, k;
		cin >> n >> k;
		cnt.clear();
		rep(i, 0, n){
			int x;
			cin >> x;
			if(x % k == 0) continue;
			if(x <= k) cnt[k - x ] ++;
			else cnt[k - x % k] ++;
		}
		ll ans = 0;
		for(auto i :cnt){
			if(i.fi == 0) continue;
			ans = max(ans, (ll)(i.se - 1) * k + i.fi);
			//cout << i.fi << " " << i.se << endl;
		}
		if(ans)cout << ans + 1<< endl;
		else cout << ans << endl;
	}
	return 0;
}
/*
1
1 4
1
*/