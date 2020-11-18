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
int get(ll sum){
	ll num = 0;
	while(sum){
		num += sum % 10;
		sum /= 10;
	}
	return num;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		ll n, s;
		cin >> n >> s;
		ll now = n;
		if(get(n) <= s){
			cout << "0" << endl;
			continue;
		}
		ll base = 10;
		rep(i, 1, 21){
			now += base - now % base;
			//cout << now << endl;
			if(get(now) <= s){
				cout << now - n << endl;
				break;
			}
			
			base *= 10;
		}
	}
	return 0;
}