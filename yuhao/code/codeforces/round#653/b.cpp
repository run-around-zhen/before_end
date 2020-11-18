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
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		ll n;
		cin >> n;
		int cnt = 0;
		/*ll x = n;
		while(x % 2 == 0) x /= 2;
		if(x != 1) {
			cout << "-1" << endl;
			continue;
		}*/
		int flag = 0;
		while(n != 1){
			if(n % 6 == 0) n /= 6;
			else n *= 2;
			cnt ++;
			if(cnt  >= 1000){
				flag = 1;
				break;
			}
		}
		if(flag) cout << "-1" << endl;
		else cout << cnt << endl;
	}
	return 0;
}