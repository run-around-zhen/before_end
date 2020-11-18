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
const int mod = 998244353;
struct node{
	int a;
	int b;
	int c;
	int n;
};

inline bool operator< (const node& a,const node& b){
	if(a.a!=b.a)
	return (a.a)<(b.a);
	if(a.b!=b.b)
	return (a.b)<(b.b);
	if(a.c!=b.c)
	return (a.c)<(b.c);
	return (a.n)<(b.n);
}
map<node, int> F, H, G;
int inv2, inv6;
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
int add(int a , int b){
	return ((ll)a + b) % mod;
	if((ll)a + b >= mod) return a + b - mod;
	return a + b;
}
int mul(int a, int b){
	return (ll)a * b % mod;
}
int f(int  a,int b, int c, int n){
	auto fp=F.find({a, b, c, n});
	if(fp!=F.end()) return (*fp).second;
	if(!n) return F[{a, b, c, n}] = b / c;
	if(!a) return F[{a, b, c, n}] = mul((n + 1), (b / c));
	if(a >= c || b >= c) return F[{a, b, c, n}] = add(add(mul(mul(mul(n, (n + 1)), inv2), (a / c)), mul(n + 1, (b / c))), f(a % c, b % c, c, n));
	return F[{a, b, c, n}] = add(mul(n, (((ll)a * n + b) / c) % mod), - f(c , c - b - 1, a, (((ll)a * n + b) / c - 1) % mod) + mod); 
}
int g(int a, int b, int c, int n);
int h(int a, int b, int c, int n){
	auto fp=H.find({a, b, c, n});
	if(fp!=H.end()) return (*fp).second;
	if(!n) return H[{a, b, c, n}] = mul(b / c, b / c);
	if(!a) return H[{a, b, c, n}] = mul(n + 1, mul(b / c, b / c));
	if(a >= c || b >= c) return H[{a, b, c, n}] = add(add(add(add(add(mul(mul(mul(a / c, a / c), mul(n, n + 1)), mul(add(mul(2, n), 1), inv6)), mul(n + 1, mul(b / c, b / c))), h(a % c, b % c, c, n)), mul(mul(a / c, b / c), mul(n, n + 1))), mul(mul(2, b / c), f(a % c, b % c, c, n))), mul(mul(2, a / c), g(a % c, b % c, c, n)));
	return H[{a, b, c, n}] = add(add(mul(n, mul((((ll)a * n + b) / c) % mod, (((ll)a * n + b) / c) % mod)), - mul(2, g(c, c - b - 1, a, (((ll)a * n + b) / c - 1) % mod)) + mod), - f(c, c - b - 1, a ,(((ll)a * n + b) / c - 1) % mod) + mod);
}
int g(int a, int b, int c, int n){
	auto fp=G.find({a, b, c, n});
	if(fp!=G.end()) return (*fp).second;
	if(!n) return 0;
	if(!a) return  G[{a, b, c, n}] = mul(b / c, mul(mul(n, n + 1), inv2));
	if(a >= c || b >= c) return G[{a, b, c, n}] = add(add(mul(a / c, mul(mul(mul(n, n + 1), add(mul(2, n), 1)), inv6)), mul(b / c, mul(mul(n, n + 1), inv2))), g(a % c, b % c, c, n));
	return G[{a, b, c, n}] = mul(inv2, add(add(mul(mul(n, n + 1), (((ll)a * n + b) / c)) % mod, - h(c, c - b - 1, a, (((ll)a * n + b) / c - 1) % mod) + mod), -f(c, c- b - 1, a, (((ll)a * n + b) / c - 1) % mod) + mod));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	inv2 = qpow(2, mod - 2);
	inv6 = qpow(6, mod - 2);
	int T;
	cin >> T;
	while(T --){
    	F.clear();
   		H.clear();
 		G.clear();
		int a, b, c, n;
		cin >> n >> a >> b >> c;
		cout << f(a, b, c, n) << " " << h(a, b, c, n) << " "  << g(a, b, c, n)  << endl;
 	}
	return 0;
}