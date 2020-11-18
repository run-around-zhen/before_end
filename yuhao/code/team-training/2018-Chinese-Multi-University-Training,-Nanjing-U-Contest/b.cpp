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
typedef vector<double> vi;
const double eps = 1e-10;
const double PI = acos(-1);
double q;
double w;
vi a, vv;
double area;
double ans = 1e18;
bool cmp(double a, double b){
	return a > b;
}
void check(double a, double b, double c){
	//cout << a << " " << b << " " << c << endl;
	if(area / a * 2 - w > eps) return ;
	double aa1 = acos((1.0 * a * a + b * b - c * c )/ ( 2.0 * a * b));
	if(aa1 < 0 ) return ;
	double t3 = PI / 2 - aa1;
	double aa2 = acos(w / b);
	double t2 = PI / 2 - aa1 - aa2;
	if(w - b > eps ) t2 = 1e9;
	double aa3 = acos(w / a);
	double t1 = PI / 2  - aa3;
	if(w - a > eps) t1 = 1e9;
	double res1 = sin(aa3) * a;
	double res2 = sin(aa2) * b;
//	cout << a << " " << b << " " << c << " " << t1 << " "<< t2 << " " << t3 << endl;	
	/*if(t2 - t1 > -eps && t3 - t1 > -eps){
		if(ans - res1 > eps) ans = res1;
	}*/
	if(t1 - t2 > -eps && t3 - t2 > -eps){
		double tmp  = a * sin(aa2 + aa1);
		if(res2 - tmp > eps) tmp = res2;
		if(ans - tmp > eps) ans = tmp;
	} 
	/*if(w - a > -eps){
		double tmp = area / a * 2;
		if(ans - tmp > eps) ans = tmp;
	}
	else */
	if(t1 - t3 > -eps && t2 - t3 > -eps){
		double bb1 = aa1;
		double bb2 = asin(w / a);
		double bb3 = PI - bb1 - bb2;
		double tmp = a * cos(bb2) + b * cos(bb3);
		if(ans - tmp > eps) ans = tmp;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		a.clear();
		vv.clear();
		ans = 1e18;
		double x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		cin >> w;
		a.pb(sqrt(1.0 * (x1 - x2) * (x1 - x2) + 1.0 * (y1 - y2) * (y1 - y2)));
		a.pb(sqrt(1.0 * (x1 - x3) * (x1 - x3) + 1.0 * (y1 - y3) * (y1 - y3)));
		a.pb(sqrt(1.0 * (x2 - x3) * (x2 - x3) + 1.0 * (y2 - y3) * (y2 - y3)));
		sort(all(a), cmp);
		double p = 1.0 * (a[0] + a[1] + a[2]) / 2;
		area = sqrt(p * (p - a[0]) * (p - a[1]) * (p - a[2]));
		rep(i, 0, 3) vv.pb(2 * area / a[i]);
		sort(all(vv));
		if(vv[0] - w > eps){
			cout <<"impossible" << endl;
			continue;
		}
		//do{
			rep(i, 0, 3){
				rep(j, 0, 3){
					if(i == j) continue;
					rep(k, 0, 3) {
						if(i == k || j == k) continue;
						check(a[i], a[j], a[k]);
					}
				}
			}
		//}while(next_permutation(all(a)));
		cout<<fixed<<setprecision(10) << ans << endl;
	}
	
	return 0;
}
/*
5
0 0 3 0 0 4 10
0 0 3 0 0 4 1
0 0 3 0 0 4 10
0 0 3 0 0 4 1
0 0 3 5 2 5 5
*/
/*
2
0 0 1 3 4 2 3
2 3 1 3 2 5 3
8968979 312312 31323123 45235 3141 343 32231321
*/