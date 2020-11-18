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
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		ll a, b;
		cin >> a >> b;
		if(a < b) swap(a, b);
		int flag = 0;
		int ans = 0;
		while(a > b){
			if(a % 2 != 0) {
				flag = 1;
				break;
			}
			a = a / 2;
			if(a < b) {
				flag = 1;
				break;
			}
			ans ++;
		}
		if(flag){
			cout << "-1" << endl;
		}
		else{
			if(ans == 0){
				cout << ans << endl;
			}
			else cout << (ans  - 1) / 3 + 1 << endl;
		}
	}
	return 0;
}