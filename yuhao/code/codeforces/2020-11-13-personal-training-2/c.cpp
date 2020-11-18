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
struct node{
	int l, r;
}a[1000000 + 10];
const int mod = 1e9 + 7;
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	//int x;
	int ans = 0;
	/*cin >> x;
	rep(i, 0, 32){
		a[i].l = i;
		a[i].r = (i ^ x);
	}
	rep(i, 0, 32){
		rep(j, i + 1, 32){
			if(a[i].l < a[j].l && a[i].r > a[j].r)ans ++;
		}
	}*/
	//de(ans);
	string s;
	cin >> s;
	rep(i, 0, (int)s.size()){
		if(s[i] == '1'){
			ans = (ans + qpow(2, 2 * sz(s) - i - 2)) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}