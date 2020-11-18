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
ll mod = 998244353;
const double eps = 1e-9;
ll dp[1010];
ll a[1010],b[1010];
int n, m;
void cal(){
	rep(i, 0, n + 1){
		rep(j, 0, n + 1){
			if(i + j > n) break;
			b[i + j] += (a[j] * dp[i]) % mod;
            b[i + j] %= mod;
			//cout << b[i + j] << " " << i + j << endl;
		}
	}
	rep(i, 0, n + 1) {
		dp[i] = b[i];
		b[i] = 0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	int flag = 1;
	per(i, 1, sqrt(m) + 1){
		if(m % (i * i ) == 0) {
			m = i;
			flag = 1;
			break;
		}
	}
	if(!flag) m = 1;
	//cout << m << endl;
	swap(n, m);
	rep(i, 1, m + 1){
		memset(a, 0, sizeof(a));
		rep(j, 0, n + 1){
			if(i * j > n) break;
			if(i == 1) dp[i * j] = 1;
			else a[i * j] = 1;
		}
		if(i != 1) cal();
		/*rep(i, 0, n + 1) cout << dp[i] << " " ;
		cout << endl;
		rep(i, 0, n + 1) cout << a[i] << " ";
		cout << endl;*/
	}
	cout << dp[n];
	return 0;
}