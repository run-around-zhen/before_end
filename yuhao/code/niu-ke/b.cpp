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
ll a[1000000 + 10];
ll mod = 1e9 + 9;
vi prime;
int ans[1000000 + 10];
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		b /= 2;
		a = a * a % mod;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i ,1 , n + 1) cin >> a[i];
	for(int i = 2; i<= 100000; i ++){
		int flag = 1;
		for(int j = 2 ;j * j <= i ; j ++ ){
			if(i % j == 0){
				flag = 0;
				break;
			}
		}
		if(flag) prime.pb(i);
	}
	//rep(i,0,(int)prime.size())cout<<prime[i] <<endl;
	rep(i, 1, n + 1){
		for(auto j : prime){
			if(j * j > a[i]) break;
			int cnt = 0;
			if(a[i] % j == 0){
				while(a[i] % j == 0){
					a[i] /= j;
					cnt++;
				}
				ans[j] = max(ans[j], cnt);
			}
		}
		if(a[i] != 1) ans[a[i]] = max(ans[a[i]], 1);
	}
	ll res  = 1;
	rep(i, 1, 1000000 + 1){
		if(ans[i]) res = (res *  qpow(i, ans[i])) % mod;
	}
	cout << res << endl;
	return 0;
}