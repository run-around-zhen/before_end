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
int n;
double dp[500000 + 10][70];
int f[500000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(8);
	int T;
	n = 1;
	rep(i, 0, 60) dp[n][i] = 1;
	cin >> T;
	while(T --){
		int type, x;
		cin >> type >> x;
		if(type == 1){
			n ++ ;
			rep(i, 0, 60) dp[n][i] = 1;
			f[n] = x;
			double pre = 1;
			int s=n;
			for(int deep = 0, now = x; now && deep <= 50; deep ++, now = f[now]){
				double tmp = dp[now][deep];
				dp[now][deep] /= 0.5 * (1 + pre);
				if(deep) dp[now][deep] *= 0.5 * (1 + dp[s][deep - 1]);
				else dp[now][deep] *= 0.5;
				s= now;
				pre = tmp;
			}
		}
		else{
			double ans = 0;
			rep(i, 1, 50) ans += (dp[x][i] - dp[x][i - 1]) * i;
			cout << ans << endl;
		}
	}
	return 0;
}