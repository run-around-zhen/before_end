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
bool vis[1000000 + 10];
struct node{
	ll x, y;
}a[1000000 + 10];
bool cmp(node a, node b){
	return a.x > b. x;
}
ll sum[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n, m;
		cin >> n >> m;
		rep(i, 1, m + 1) cin >> a[i].x >> a[i].y;
		ll ans = 0;
		sort(a + 1, a + 1 + m, cmp);
		rep(i, 1,  m + 1){
			sum[i] = sum[i - 1] + a[i].x;
		}
		rep(i, 1, m + 1){
			int l = 1, r = m;
			int pos = 0;
			while(l <= r){
				int mid = (l + r) / 2;
				if(a[mid]. x > a[i].y){
					pos = max(pos, mid);
					l = mid + 1;
				}
				else{
					r = mid - 1;
				}
			}
			//cout << pos << endl;
			if(pos >= n) {
				ans = max(ans, sum[n]);
				continue;
			}
			if(a[i].x > a[i].y) ans = max(ans, sum[pos] + (ll)max(0, (n - pos)) * a[i].y);
			else ans = max(ans, sum[pos] + 1ll * max(0, (n - pos - 1)) * a[i].y +  a[i].x);
		}
		cout << ans << endl;

	}
	return 0;
}
/*
1
1
5
132132312 231323
321321 32131231232
123213
 321
321312
 312
321312
31231
*/