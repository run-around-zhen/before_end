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
#define MAXN 100
#define ffabs(x) ((x)>0?(x):-(x))
#define eps 1e-6
long double a[100][100], x[100], b[100];
int gauss(long double a[][MAXN], int n, long double x[]) {
	int i, j, k, p;
	for (j = 0; j < n; ++j) {
		for (i = j + 1, p = j; i < n; ++i)
			if (ffabs(a[i][j]) > ffabs(a[p][j]))
					p = i;
		if (ffabs(a[p][j]) < eps) return 0;
		if (p != j)
			for (k = j; k <= n; ++k)
				swap(a[j][k], a[p][k]);
		for (i = j + 1; i < n; ++i)
			for (k = n; k >= j; --k)
				a[i][k] -= a[j][k] * a[i][j] / a[j][j];
	}
	for (j = n - 1; j >= 0; --j) {
		x[j] = a[j][n] / a[j][j];
		for (i = j - 1; i >= 0; --i)
			a[i][n] -= a[i][j] * x[j];
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	while(cin >> n){
		if(n == 0) break;
		rep(i, 0, n + 3) cin >> b[i];	
		rep(i, 0, n + 3){
			int t = 0;
			memset(a, 0, sizeof(a));
			memset(x, 0, sizeof(x));
			rep(j, 0, n + 2){
				if(j == i) continue;
				double tmp = 1;
				rep(k, 0, n + 1){
					a[t][k] = tmp;
					tmp *= j;
				}
				a[t][n + 1] = b[j];
				t ++;
			}
			gauss(a, n + 1, x);
			int cnt = 0;
			rep(i, 0, n + 3){
				long double tmp = 1;
				long double ans = 0;
				rep(j, 0, n + 1){
				 	ans +=  tmp * x[j]; 
				 	tmp *= i;
				}
				//cout << ans << " " << b[i] << endl;
				if(fabs(ans - b[i]) > 1) {
					//cout << ans << " " << b[i] << endl;
					cnt ++;
				}
			}
			if(cnt == 1){
				cout << i << endl;
				break;
			}	
		}
	}
	return 0;
}