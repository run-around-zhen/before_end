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
const double eps = 1e-8;
double a[55][55], b[55][55];
double det(int n) { // det(a[1..n-1][1..n-1])
	double ans = 1.0;
	rep(i, 1, n){
		rep(j, 1, n){
			a[i][j] = b[i][j];
			//cout << a[i][j] << " ";
		}
		//cout << endl;
	}
	rep(i, 1, n) {
		rep(j, i + 1, n) {
			while(fabs(a[j][i]) > eps) {
				double t = a[i][i] / a[j][i];
				rep(k, i, n) a[i][k] = (a[i][k] - a[j][k] * t), swap(a[i][k], a[j][k]);
				ans = - ans;
			}
		}
		if(fabs(a[i][i]) < eps) return 0;
		ans = ans * a[i][i];
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	double ans = 1;
	rep(i, 1, n + 1){
		rep(j, 1, n + 1){
			cin >> b[i][j];
			if(fabs(1 - b[i][j]) < eps) b[i][j] -= eps;
			if(i < j) ans *= (1 - b[i][j]);
			b[i][j] /= (1 - b[i][j]);
		}
	}
	rep(i, 1, n + 1){
		rep(j, 1, n + 1){
			if(i == j) continue;
			b[i][i] += b[i][j];
			b[i][j] = - b[i][j];
		}
	}
	cout << fabs(ans * det(n));
	return 0;
}