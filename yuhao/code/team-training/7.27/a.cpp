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
const int N = 100000 + 10;
ll ans[N], sum[N], a[N];;
const int mod = 998244353;
bool vis[N];
int cnt;
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}
void dfs(int i){
	vis[i] = true;
	cnt ++;
	if(!vis[a[i]]) dfs(a[i]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, m;
	cin >> n >> m;
	ans[1] = 0;
	ans[2] = 4;
	sum[2] = 2;
	rep(i, 3, n + 1){
		ans[i] = (sum[i - 1] + i) * i % mod * qpow(i - 1, mod - 2)% mod;
		sum[i] = (sum[i - 1] + ans[i] * qpow(i, mod - 2)) % mod;
	}
	while(m --){
		memset(vis, false, sizeof(vis));
		rep(i, 1, n + 1) cin >> a[i];
		ll res = 0;
		rep(i, 1, n + 1){
			if(!vis[i]){
				cnt = 0;
				dfs(i);
				res = (res + ans[cnt]) % mod;
			}
		}
		cout << res << endl;
	}
	return 0;
}