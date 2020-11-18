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
const double eps = 1e-6;
const double PI = acos(-1.0);
double HL;
double get(double x, double y,double arc){
	y -= HL / 3;
	double xx = x * cos(arc) - y * sin(arc);
	double yy = x * sin(arc) + y * cos(arc);
	yy += HL / 3;
	return yy;
}
double L, x, y, vx, vy;
ll check(double times){
	ll ans = 0;
	ans += abs(floor(1.0 * get(x + vx * times, y + vy * times, 0) / HL));
	ans += abs(floor(1.0 * get(x + vx * times, y + vy * times, 120.0 / 180.0 * PI) / HL));
	ans += abs(floor(1.0 * get(x + vx * times, y + vy * times, 240.0 / 180.0 * PI) / HL)); 
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int k;
		cin >> L >> x >> y >> vx >> vy >> k;
		HL = sqrt(3.0) * L / 2;
	//	cout << HL << endl;
		double l = 0, r = 1e12;
		while(r - l > eps){
			double mid = (l + r) / 2;
			if(check(mid) >= k) r = mid;
			else l = mid;
		}
		cout << setiosflags(ios::fixed) << setprecision(8) << (l + r) / 2 << endl;;
	}
	return 0;
}