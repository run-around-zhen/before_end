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
int sum[1000000 + 10];
map<int, int>ma;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		string s;
		cin >> s;
		int n = s.size();
		ma.clear();
		rep(i, 0, n){
			if(s[i] == '+') sum[i] = 1;
			else sum[i] = -1;
			if(i) sum[i] += sum[i - 1];
			if(ma[sum[i]]) continue;
			else ma[sum[i]] = i + 1;
		}
		ll ans = 0;
		rep(i, 0, n + 1){
			ans += ma[- i - 1];
			//cout << ans << endl;
			if(ma[ - i - 1] == 0) {
				ans += n ;
				break;
			}
		}
		cout << ans << endl;
		rep(i, 0, n) sum[i] = 0;
	}
	return 0;
}