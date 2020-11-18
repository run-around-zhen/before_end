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
double cal(ll x , ll h, ll c){
	return (double)(1.0 * h * (x + 1) + c * x) / (2 * x + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		ll h, t, c;
		cin >> h >> c >> t;
		if(h <= t){
			cout << "1" << endl;
			continue;
		}
		if( t * 2 <= h + c){
			cout << "2" << endl;
			continue;
		}
		ll sum = (h -t) / (2 * t - h - c);
		double ans1 = cal(sum, h ,c);
		double ans2 = cal(sum + 1, h ,c);
		if(fabs(ans1 - t) > fabs(ans2 - t)){
			cout << sum * 2 + 3 << endl;
		}
		else{
			cout << sum * 2 + 1 << endl;
		}
	}
	return 0;
}