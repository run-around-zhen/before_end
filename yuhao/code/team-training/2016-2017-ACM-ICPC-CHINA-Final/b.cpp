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
ll bas[100000 + 10];
ll qpow(ll a, ll b){
	return bas[b];
}
char res[100000 + 10];
ll get(ll i){
	if(i % 2 == 1) return qpow(2, i / 2 + 1);
	else return qpow(2, i / 2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	bas[0] = 1;
	rep(i, 1, 100000 + 10) bas[i] = bas[i - 1] * 2;
	rep(cas, 1, T + 1){
		ll n, k;
		cin >> n >> k;
		int flag = 0;
		per(j, 1, n + 2){
			ll ans = 0;
			int i = j - 1;
			if(i % 2 == 0){
				ans = get(i / 2) * qpow(2, i / 2) * 2 - get(i / 2) * get(i / 2);
			}
			else{
				ans = get(i / 2 + 1) * qpow(2, n - i / 2 - 1) + get(i / 2) * qpow(2, n - i / 2) - get(i / 2) * get(i / 2 + 1);
			}
			if(j == n + 1 && k > ans) {
				flag = 1;
				break;
			}
			cout << i << " " <<  ans << endl;
			if(j != n + 1){
				if(k > ans) {
					res[i] = '1';
					k -= ans;
				}
				else{
					res[i] = '0';
				}
			}
		}
		if(flag){
			cout << "NOT FOUND!" << endl;
		}
		else{
			per(i, 0, n) cout << res[i] ;
			cout << endl;
		}
	}
	return 0;
}