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
const int N = 300000 + 10;
double dp[N],g[N];
/*ll qpwo(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		b /= 2;
		a = a * a % mod;
	}
	return res;
}*/
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	dp[n] = 0;
	g[n] = 0;
	per(i, 0, n) dp[i] = dp[i + 1] + 1.0 * n / ( n - i);
	per(i, 0, n) g[i] = 1.0 * i / (n - i) *dp[i] + 1.0 * n / (n - i) + g[i + 1] + dp[i + 1];
	//cout << g[0] << endl;
	printf("%.2lf\n",g[0]);
	return 0;
}