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
int a[10000 + 10];
int n, m;
bool check(int rt){
	int flag = 0;
	rep(i, 1, n + 1){
	//	if(rt % a[i] == 0 && rt != a[i]) return false;
		if(rt % a[i] == 0) flag = 1;
	}
	return flag;
}
ll cal(int m){
	int phi = m;
	for(int i = 2; i * i <= m; i ++){
		if(m % i ==0){
			while(m % i == 0) m /= i;
			phi = phi / i * (i - 1);
		}
	}
	if(m != 1) phi = phi  / m * (m - 1);
	return phi;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	rep(cas, 1, T + 1){
		cin >> n >> m;
		rep(i, 1, n + 1) {
			cin >> a[i];
			a[i] = __gcd(a[i], m);
		}
		cout << "Case #" << cas << ": ";
		ll ans = 0;
		for(int i = 1; i * i <= m ; i ++ ){
			if(m % i != 0 ) continue;
			if(check(i)) {
				ans += cal(m / i) * m / i * i / 2;
				//cout << m / i << "  " << cal(m / i) << endl;
			}
			//cout << ans << endl;
			if(i * i == m) continue;
			if(i == 1) continue;
			if(check(m / i)){
				ans += cal(i) * m  / 2;
			}
		//	cout << ans << endl;
		}
		cout << ans << endl;
	}
	return 0;
}