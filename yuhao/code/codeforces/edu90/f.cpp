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
ll a[1000000 + 10], b[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		ll sum1 = 0, sum2 = 0;
		rep(i, 0, n) {
			cin >> a[i];
			sum1 += a[i];
		}
		rep(i, 0, n) {
			cin >> b[i];
			sum2 += b[i];
		}
		if(sum1 > sum2){
			cout << "NO" << endl;
			continue;
		}
		ll ans = 0, maxn = -1e18;
		int flag = 1;
		rep(i, 0, 2 * n){
			ans += b[i % n] - a[i % n];
			maxn = max(maxn, ans - b[i % n]);
			if(ans < maxn){
				flag = 0;
				break;
			}
		}
		if(flag){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}