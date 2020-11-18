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
int n;
bool get(int x){
	if(__gcd(x, n / x) == 1) return true;
	return false;
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int cnt = 0;
	while(cin >> n){
		int ans = 0;
		for(int i = 1; i * i <= n ;i ++ ){
			if(n % i != 0) continue;
			if(get(i)) ans += i;
			if(i * i == n) continue;
			if(get(n / i)) ans += n / i;
		}
		cnt += ans;
		cout << "f(" << n << ") = " << ans << endl;
		//cout << cnt << endl;
	}
	return 0;
}