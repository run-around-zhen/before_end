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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		ll res = 0;
		ll n, k, l1, r1, l2, r2;
		cin >> n >> k >> l1 >> r1 >> l2 >> r2;
		if(k <= max(0ll, min(r1, r2) - max(l1, l2)) * n){
			cout << "0" << endl;
			continue;
		}
		k = k - max(0ll, min(r1, r2) - max(l1, l2)) * n;
		if(min(r1, r2) >= max(l1, l2)){
			ll sum = abs(r1 - r2) + abs(l1 - l2);
			if(sum * n >= k){
				cout << k << endl;
			}
			else{
				cout << sum * n + (k - sum * n) * 2 << endl;
			}
			continue;
		}
		if(l1 > r2){
			swap(r1, r2);
			swap(l1, l2);
		}
		ll use = l2 - r1;
		ll now = r2 - l1;
		if(now >= k){
			cout << k + use << endl;
			continue;
		}
		k -= now;
		res += use + now;
		n --;
		if(use >= now){
			cout << 2 * k + res << endl;
			continue;
		}
		int flag = 0;
		while(n){
			-- n;
			if(k <= now){
				cout << res + min(k * 2, use + k) << endl;
				flag = 1;
				break;
			}
			res += use + now;
			k -= now;
		}
		if(!flag) {
			cout << res + 2 * k << endl;
		}
	}
	return 0;
}