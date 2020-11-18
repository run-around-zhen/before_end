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
ll get(ll a, ll b){
	return a * b / __gcd(a, b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		ll n;
		cin >> n;
		ll ans = 1e18;
		int pos2 = -1, pos1 = -1;
		for(int i = 2; i * i <= n ;i ++){
			if(n % i == 0){
				if(n / i * ( i - 1) < ans){
					ans = n / i * (i - 1);
					pos1 = n / i;
					pos2 = n / i * (i - 1);
				}
				int j = n / i;
				if(n / j * ( j - 1) < ans){
					ans = n / j * (j - 1);
					pos1 = n / j;
					pos2 = n / j * (j - 1);
				}
			}
		}
		if(pos1 != -1 )cout << pos1 << " " << pos2 << endl;
		else cout << "1 " << n - 1 << endl;
	}
	return 0;
}