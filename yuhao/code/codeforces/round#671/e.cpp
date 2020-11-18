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
vi res;
vi b[100], vv;
int a[100000];
set<int>s;
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n;
		s.clear();
		cin >> n;
		int m = n;
		vv.clear();
		rep(i, 0, 80) b[i].clear();
		res.clear();
		int cnt= 0 ;
		for(int i = 2; i * i <= n; i ++){
			if(n % i == 0) {
				s.insert(i);
				s.insert(n / i);
			}
			if(m % i ==0 ){
				while(m % i == 0){
					m /= i;
				}
				res.pb(i);
			}
		}
	//	cout << "!!" << endl;
		s.insert(n);
		while(!s.empty()) {
			if(!vv.size()) {
				int x = *s.begin(); s.erase(s.begin());
				vv.pb(x);
			}
			else {
				for(auto x : s) {
				//	cout << x << " " << vv.back() << endl;
					if(__gcd(x, vv.back()) > 1) {
						vv.pb(x);
						s.erase(x);
						break;
					}
				}
			}
			//cout << s.size() << endl;
		}
		int tt = 0;
		rep(i, 0, (int)vv.size()){
			if(__gcd(vv[i], vv[(i + 1) % (int)vv.size()]) == 1) tt ++;
		}
		for(auto i:vv){
			cout << i << " ";
		}
		cout << endl;
		cout << tt << endl;
	}
	return 0;
}