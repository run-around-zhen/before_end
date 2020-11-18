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
typedef pair<ll, int> pii;
typedef vector<int> vi;
int w, n;
set<pii>s;
ll sum[50000 + 10], a[50000 + 10];
bool dp[50000 + 10];
bool check(int k){
	memset(dp, 0, sizeof(dp));
	s.clear();
	s.insert(mp(k + w, 0));
	int flag = 0;
	rep(i, 1, n + 1){
		while(!s.empty()){
			int id = (*s.begin()).se;
			if(sum[i] - sum[id] + i - id - 1 > w) s.erase(s.begin());
			else break;
		}
		if(!s.empty() && (*s.begin()).fi <= (ll)sum[i] + k * i){
			s.insert(mp(k + w + sum[i] + k * i, i));
			dp[i] = true;
			flag = i;
		//	cout << k << " "<< i << "!!" << endl;
		}
	}
	return sum[n] - sum[flag] + n - flag - 1 <= w;
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	while(cin >> w >> n){
		if(w == 0 && n == 0) break;
		rep(i, 1, n + 1){
			cin >> a[i];
			sum[i] = a[i] + sum[i - 1];
		}
		if(sum[n] + n - 1 <= w){
			cout << "1" << endl;
			continue;
		}
		int l = 1, r = w;
		int ans = w;
		while(l <= r){
			memset(dp, 0, sizeof(dp));
			int mid = (l + r) / 2;
			// cout << check(mid) << endl;
			if(check(mid)){
				ans = min(ans, mid);
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		cout << ans << endl;
		//check(1);
	}
	return 0;
}