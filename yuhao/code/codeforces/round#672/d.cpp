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
ll A[1000000 + 10], inv[1000000 + 10];
const int mod = 998244353;
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}
bool cmp(node a, node b){
	return a.l < b.l || (a.l == b.l && a.r < b.r);
}
ll get(int a, int b){
	return A[a] * inv[b] % mod * inv[a - b] % mod;
}
multiset<int>s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, k;
	cin >> n >> k;
	A[0] = 1;
	inv[0] = 1;
	rep(i, 1, n + 1){
		A[i] = A[i - 1] * i % mod;
		inv[i] = qpow(A[i], mod - 2);
	}
	rep(i, 1, n + 1){
		cin >> a[i].l >> a[i].r;
	}
	sort(a + 1, a + 1 + n, cmp);
	ll ans = 0;
	rep(i, 1, n + 1){
		while(s.size() != 0 && (*s.begin()) < a[i].l){
			s.erase((*s.begin()));
		}
		s.insert(a[i].r);
		if((int)s.size() >= k){
			ans += get((int)s.size() - 1, k - 1);
			ans %= mod;
		}
		
		//cout << a[i].l << " " << a[i].r << " " << ans <<  " " << s.size() << endl;
	}
	cout << ans << endl;
	return 0;
}