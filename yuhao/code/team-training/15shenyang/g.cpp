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
double t, v1, v2;
const double eps = 1e-15;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	rep(cas, 1, T + 1){
		cin >> t >> v1 >> v2; 
		cout << "Case #" << cas << ": ";
	//	cout<< eps << endl;
		int flag = 0;
		if(v2 - v1 < eps) flag = 1;
		double l = 300.0, r = 600.0;
		int cnt = 0;
		int flag1 = 0, flag2 = 0;
		while(cnt <= 500){
			cnt ++ ;
			double mid = (l + r) / 2.0;
			double t1 = sqrt(300.0 * 300.0 + 1.0 * (mid - 300) * (mid - 300)) / v1;
			double t2 = mid / v2;
			if(t1 - t2 > eps) {
				l = mid;
			}
			else {
				r = mid;
				flag1 = 1;
			}
		}
		//cout << r << endl;
		double tt1 = (600.0 +  (r - 300.0) )/ v1;
		double tt2 = (300.0 + (600.0 - r )) / v2 + t;
		if( flag1 && tt1 - tt2 < eps){
			flag = 1;
		} 
		l = 600.0, r = 900.0;
		cnt = 0;
		while(cnt <= 500){
			cnt ++ ;
			double mid = (l + r) / 2.0;
			double t1 = sqrt(300.0 * 300.0 + (900.0 - mid) * (900.0 - mid)) / v1;
			double t2 =  mid / v2;
			if(t1 - t2 > eps) {
				l = mid;
			}
			else {
				r = mid;
				flag2 = 1;
			}
		}
		//cout << r << endl;
		tt1 = (sqrt((r - 600.0) * (r - 600.0 ) + 300.0 * 300.0) + 900.0) / v1;
		tt2 = (300.0 + (900.0 - r)) / v2 + t;
		if( flag2&&tt1 - tt2 < eps){
			flag = 1;
		}
		if(flag){
			cout <<"Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	return 0;
}