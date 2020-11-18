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
vi p;
int a, b, c, d;
int n, m, costa, costb;
double get(double now_a){
	double now_b = b + (1.0 * m - now_a * costa) / costb ;
	now_a += a;
//	cout << now_a << " " << now_b << "!!" << endl;
	if(now_a <= d){
		return 1e18;
	}
	else{
		int t = n / (now_a - d);
		if(t * (now_a - d) == n) t --;
		return t * max(0.0, (double)(c - now_b));
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	rep(i, 2, 100000){
		int flag = 0;
		for(int j = 2; j * j <= i; j ++){
			if(i % j == 0) {
				flag = 1;
				break;
			}
		}
		if(!flag) p.pb(i);
	}
	while(T --){
		cin >> a >> b >> c >> d >> n >> m >> costa >> costb;
		if(a <= b && 1.0 * m / costa + a <= d){
			cout << "-1" << endl;
			continue;
		}
		double l = 0, r = 1.0 * m / costa;
		int cnt = 0;
		while(cnt <=1e4 ){
			cnt ++;
    		double lmid=l+(r-l)/3.0,rmid=l+(r-l)/3.0*2;
   		 	if(get(lmid)<get(rmid))
       		 	r=rmid;
   			else
    	   		l=lmid;

		}
		ll l1 = 0, rr = 1;
		double ans = get(l);
		double eps = 1;
		//cout << ans << endl;
		for(auto i: p){
			//cout << i << endl;
			ll f = i * ans;
			double f1 = 1.0 * i * ans;
			if(fabs(f - f1)< eps){
				eps = fabs(f - f1);
				rr = f;
				l1 = i;
			} 
		}
		ll gcd = __gcd(rr, l1);
		rr /= gcd;
		l1 /= gcd;
		cout << rr << "/" << l1 << endl;
		/*rep(i, 0, 111){
			cout << i << " " << get(i) << endl;
		}*/
	}
	return 0;
}