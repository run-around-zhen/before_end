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
int res[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	rep(i, 2, 1000000 + 10){
		int flag = 0;
		for(int  j = 2 ; j * j <= i; j ++){
			if(i % j == 0) {
				flag = 1;
				break;
			}
		}
		if(!flag) p.pb(i);
	}
	int ans = 0;
	for(auto i :p){
		if(n % i == 0){
			while(n % i == 0){
				res[i] ++;
				n /= i;
			}
		}
	}
	if(n != 1) ans = 1;
	for(auto i : p){
		if(res[i]){
			rep(j, 1, 100){
				if(j * (1 + j) / 2 > res[i]){
					ans += j - 1;
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}