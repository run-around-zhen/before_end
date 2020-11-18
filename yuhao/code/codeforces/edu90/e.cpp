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
int n, k;
ll get(ll i){
	ll sum = 0;
	while(i){
		sum += i % 10;
		i /= 10;
	}
	return sum;
}
ll check(ll i){
	ll sum = 0;
	rep(j, 0, k + 1){
		sum += get(i + j);
	}
	return sum;
}
ll res = 1e18;

int go(int tt){
	ll ans = 0;
		ll tmp = 1;
	while(tt){
			if(tt < 10) {
				ans = ans + tt * tmp;
				tt = 0;
			}
			else {
				ans = ans + 9 * tmp;
				tt -= 9;
			}
			tmp *= 10;
		}
		//cout << ans << endl;
		for(ll i = max(ans - 10, 0ll ); i < ans + 10; i ++){
			if(i > ans && n - check(i) > 10) break;
			if(check(i) == n  ) {
				res = i;
				break;
			}
		}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		res = 1e18;
		cin >> n >> k;
		int tt = n / ( k + 1);
		
		while(tt <= n){
			go(tt);
			if(res != 1e18) break;
			tt ++;
			//cout << res << " " << tt << endl;
		}
		if(res == 1e18){
			cout << "-1"<<endl;
		}
		else{
			cout << res << endl;
		}
	}
	return 0;
}