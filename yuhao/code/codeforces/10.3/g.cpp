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
double get(double a, double b, double c, double d){
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(3);
	double x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	double ans = 0;
	double t1 = 1e9;
	if(x >= x1 && x <= x2){
		if(y < y1){
			t1 = y1 - y;
		}
		else{
			t1 = y - y2;
		}
	}
	if(y >= y1 && y <= y2){
		if(x < x1){
			t1 = x1 - x;
		}
		else{
			t1 = x - x2;
		}
	}
	double t2 = min(get(x, y, x2, y1), min(get(x, y, x1, y2),min(get(x, y, x1, y1), get(x, y, x2, y2))));
	ans = max(ans,min(t1, t2)); 
	cout << ans << endl;
	return 0;
}