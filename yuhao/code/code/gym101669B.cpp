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
const int mod = 1e9 + 7;
const int N = 1000000 + 10;
ll sum[N], g[N], f[N], a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, m;
	cin >> n >> m;
	rep(i, 1, m + 1){
		int x;
		cin >> x;
		a[x] ++;
	}
	rep(i, 1, n + 2) sum[i] = sum[i - 1] + a[i];
	f[0] = 1;
	g[1] = 1;
	rep(i, 1, n + 2){
		if(a[i] == 0){
			if(i - sum[i] >= 0) f[i] = g[i - sum[i]];
			if(i + 1 - sum[i] >= 0) g[i + 1 - sum[i]] = (g[i + 1 - sum[i]] + f[i]) % mod;
		}
	}
	cout << f[n + 1] << endl;

	return 0;
}