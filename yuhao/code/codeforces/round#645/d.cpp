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
ll sum[400000 + 10],cnt[400000 + 10],a[400000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	ll x;
	cin >> n >> x;
	rep(i, 1, n + 1){
		cin >> a[i];
		a[i + n] = a[i];
	}
	n = n * 2;
	rep(i, 1, n + 1){
		sum[i] = sum[i - 1] + a[i];
		cnt[i] = cnt[i - 1] + a[i] * (1 + a[i]) / 2;
	}
	int left = 1;
	ll ans = 0;
	rep(i, 1, n + 1){
		if(sum[n] - sum[i - 1] < x) break;
		while(sum[left] - sum[i - 1] < x && left < n) left ++;
		ll last = x - (sum[left] - sum[i]);
		if(last < 0) continue;
		ans = max(ans, cnt[left] - cnt[i] + (a[i] - last + 1 + a[i]) * last / 2);

 	}
 	//cout << n << endl;
 	cout << ans << endl;
	return 0;
}