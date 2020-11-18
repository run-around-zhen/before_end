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
struct node{
	int w, v, op;
}a[2000 + 10];
ll dp[2000000 + 20];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	srand(time(0));
	int T;
	cin >> T;
	while(T --){
		int n, m;
		cin >> n >> m;
		/*int sum = 0, sum1 = 0;
		rep(i, 1, n + 1) {
			cin >> a[i].w >> a[i].v;
			sum += a[i].v;
		}
		rep(i, 1, m + 1) {
			cin >> b[i].w >> b[i].v;
			sum1 += b[i].v;
		}
		rep(i, 0, sum + 1) dp[i] = -1e9;
		rep(i, 0, sum1 + 1) dp1[i] = -1e9;
		dp[0] = dp1[0] = 0;
		random_shuffle(a + 1, a + 1 + n);
		random_shuffle(b + 1, b + 1 + m);
		int L = 0;
		int limit = n / 50;
		rep(i, 1, n + 1){
			int nowL = max(0, min(L - a[i].w, sum - limit));
			per(j, nowL, sum - a[i].w + 1){
				dp[j + a[i].w] = max(dp[j + a[i].w], dp[j] + a[i].v);
			}
			L = max(L, sum - a[i].w + 1);
		}
		int limit1 = m / 50;
		L = 0;
		rep(i, 1, m + 1){
			int nowL = max(0, min(L - b[i].w, sum1 - limit1));
			per(j, nowL, sum1 - b[i].w + 1){
				dp1[j + b[i].w] = max(dp1[j + b[i].w], dp1[j] + b[i].v);
			}
			L = max(L, sum1 - b[i].w + 1);
		}
		int ans = 0;
		rep(i, 0, 1000000 + 1){
			ans = max(ans, dp[i] + dp1[i]);
		}
		rep(i, 0, 10){
			cout << dp[i] << " ";
		}
		cout << ans << endl;*/
		//ll res = 0;
		int sum1 = 0, sum2 = 0;
		rep(i, 1, n + m + 1){
			cin >> a[i].w >> a[i].v;
			//a[i].w = 1000;
			//a[i].v = (i * 1000 + 10) % 1000000000;
			//res += a[i].v;
			if(i <= n) {
				a[i].op = 1;
				sum1 += a[i].w;
			}
			else {
				a[i].op = -1;
				sum2 += a[i].w;
			}
		}
		//cout << res << endl;
		random_shuffle(a + 1, a + 1 + n + m);
		int avr = max(sum1, sum2);
		int L = avr, R = avr;
		int limit = 150000000 / (n + m);
		rep(i, 0, sum1 +sum2 + 10) dp[i] = -1e18;
		//cout << avr << " " << L << " " << R << " " << limit << endl;
		dp[avr] = 0;
		rep(i, 1, n + m + 1){
		//	cout << a[i].op << endl;
			if(a[i].op == 1){
				//int nowr = max(limit + avr, R);
				per(j, L, min(sum1 + sum2 - a[i].w, R) + 1){
					dp[j + a[i].w] = max(dp[j + a[i].w], dp[j] + a[i].v);
				}
				R = R + a[i].w;
			}
			else{
				//int nowl = min(limit, L);
				rep(j, max(a[i].w, L), R + 1){
					dp[j - a[i].w] = max(dp[j - a[i].w], dp[j] + a[i].v);
				}
				L = L - a[i].w;
			}
			L = max(avr - limit, L);
			R = min(avr + limit, R);
		//	cout << L << " " << R << endl;
		}
		//cout << dp[avr]<< " " << res << endl;
		//cout << res << endl;
		cout << dp[avr] << endl;
	}
	return 0;
}