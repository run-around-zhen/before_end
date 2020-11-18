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
int n, k;
struct node{
	double d;
	int id;
}v[400000 + 10];
const int N = 400000 + 10;
int sum[N], vis[N];
double  x[N], y[N];
const double eps = 1e-10;
const double pi = acos(-1.0);
void updata(int p, int v){
	for(int x = p; x < N; x += (x & -x)) sum[x] += v;
}
int qry(int p){
	int res = 0;
	for(int x = p; x; x -= (x & -x)) res += sum[x];
	return res;
}
int num;
double dis(ll a, ll b){
	return sqrt(1.0 * a * a + b * b);
}
bool cmp(node a, node b){
	return a.d < b.d;
}
void add(double x, double id){
	num ++;
	v[num].d = x;
	v[num].id = id;

}
ll check(double r){
	ll ans = (ll) n * (n - 1) / 2;
	memset(vis, 0, sizeof(vis));
	num = 0;
	rep(i, 1, n + 1){
		double atc = atan2(1.0 * y[i] , 1.0 * x[i]);
		double aa =  acos(1.0 * r / dis(x[i], y[i]));
		double xx1 = atc - aa;
		double xx2 = atc + aa;
		if(xx1 < -pi) {
			add(xx1 + 2 * pi, i);
		}
		else{
			add(xx1, i);
		}
		if(xx2 > pi){
			add(xx2 - 2 * pi, i);
		}
		else{
			add(xx2, i);
		}
	}
	sort(v + 1, v + 1 + num, cmp);
	rep(i, 1, num + 1){
		//de(v[i].d);
		int id = v[i].id;
		if(vis[id]){
			ans -= qry(i) - qry(vis[id]);
			updata(vis[id], -1);
		}
		else{
			vis[id] = i;
			updata(vis[id], 1);
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(10);
	cin >> n >> k;
	rep(i, 1, n + 1){
		cin >> x[i] >> y[i];
	}
	double l = 0, r = 1e5;
	/*while(r - l > eps){
		double mid = (l + r) / 2;
		if(check(mid) >= k){
			r = mid;
		}
		else{
			l = mid;
		}
	}*/
	de(check(1.001));
	cout << l << endl;
	return 0;
}