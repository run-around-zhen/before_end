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
int a[110][110], b[110][110];
const int mod = 998244353;
struct node{
	int u, v, w;
}e[100000 + 10];
ll mul(int a, int b){
	return (ll)a * b % mod;
}
ll sub(int a, int b){
	if(a - b < 0) return a - b + mod;
	return a - b;
} 
ll add(int a, int b){
	if(a + b >= mod) return a + b - mod;
	return a + b;
}
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = mul(res, a);
		}
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}
void add_egde(int u, int v){
	b[u][v] = sub(b[u][v], 1);
	b[v][u] = sub(b[v][u], 1);
	b[u][u] = add(b[u][u], 1);
	b[v][v] = add(b[v][v], 1);
}
int det(int n){
	int ans = 1;
	rep(i, 1, n){
		rep(j, 1, n){
			a[i][j] = b[i][j];
		}
	}
	rep(i, 1, n){
		rep(j, i + 1, n)while(a[j][i]){
			int t = a[i][i] / a[j][i];
			rep(k, i, n) a[i][k] = sub(a[i][k], mul(a[j][k], t)), swap(a[i][k], a[j][k]);
			ans = mod - ans;
		}
		if(a[i][i] == 0) return 0;
		ans = mul(ans, a[i][i]);
	}
	return ans;
}
void init(int n){
	rep(i, 1, n + 1){
		rep(j, 1, n + 1) a[i][j] = b[i][j] = 0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n, m;
		cin >> n >> m;
		init(n);
		rep(i, 1, m + 1){
			cin >> e[i].u >> e[i].v >> e[i].w;
			add_egde(e[i].u, e[i].v);
		}
		int inv = qpow(det(n), mod - 2);
		int tmp = 1;
		ll res = 0;
		rep(i, 0, 33){
			init(n);
			rep(j, 1, m + 1){
				if((e[j].w >> i) & 1){
					add_egde(e[j].u, e[j].v);
				}
			}
			res = (res + mul(det(n), tmp)) % mod;
			tmp *= 2;
	 	}
	 	cout << mul(res, inv) << endl;
	}
	return 0;
}