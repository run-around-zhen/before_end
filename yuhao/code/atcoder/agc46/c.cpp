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
ll mod = 998244353;
ll A[10000], inv[100000];
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		b /= 2;
		a = a * a % mod;
	}
//	if(res == 0) return 1;
	return res;
}
ll get(ll a, ll b){
	if(a < b) return 0;
	return A[a] * inv[b] % mod * inv[a - b] % mod;
}
ll sum0[10000], sum1[10000];
char s[1000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int k;
	cin >> (s + 1);
	cin >> k;
	int n = strlen(s + 1);
	A[0] = 1;
	inv[0] = 1;
	rep(i, 1, n + 1){
		A[i] = A[i - 1] * i % mod;
		inv[i] = inv[i - 1] * qpow(i, mod - 2) % mod;
		if(s[i] == '1') sum1[i] ++;
		else sum0[i] ++;
		sum1[i] += sum1[i - 1];
		sum0[i] += sum0[i - 1];
	}
	ll ans = 0;
	rep(i, 1, n + 1){
		if(s[i] == '0'){
			int cnt = 0;
			int l = sum0[i - 1];
			int r = sum1[n] - sum1[i];
			rep(j, i + 1, n + 1){
				cnt ++;
				if(cnt > k) break;
				int use = j - i;
				rep(k, 1, min(cnt, r) + 1){
					if(use > r) break;
					if(use == k ) ans = (ans + (get(r, use) * get(use, use - k)  % mod)) % mod;
					else ans = (ans + (get(r, use) * get(use, use - k) * qpow( l, use - k) % mod)) % mod;
					cout << i << " " << j << "!! "<<  r << " " << use << " "<< k << " " << ans <<endl;
					
				}
			}
		}
		cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}