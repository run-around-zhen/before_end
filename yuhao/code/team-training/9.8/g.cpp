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
const int N = 2e5 + 5;
ll g[N + 10], dp[N + 10];
ll mu[N + 10], flag[N + 10], p[N + 10], d_x[N + 10], d_kx[N + 10],f[N + 10], h[N + 10],sum_mu[N + 10], sum_d_kx[N + 10], sum_d_x[N + 10], sum[N + 10], sum_f[N + 10];
const int mod = 1e9 + 7;
ll hh[N + 10];
ll T, k, x;
void get_mu(){
    int tot=0; mu[1]=1;
    for(int i = 2;i < N; i ++){
        if(!flag[i]){
            p[++tot]=i;
            mu[i]=-1;
        }
        for(int j = 1;j <= tot && i * p[j] < N;j ++){
            flag[i * p[j]]=true;
            if(i % p[j]==0){
                mu[i*p[j]]=0;
                break;
            }
            else mu[i*p[j]]=-mu[i];
        }
    }
}
ll qpow(ll a,ll b){
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

void init(){
	get_mu();
	rep(i, 1, N + 1) d_x[i] = qpow(i, (ll)x * k);
	rep(i, 1, N + 1) sum_d_x[i] = (sum_d_x[i - 1] + d_x[i] * mu[i] + mod) % mod;
	rep(i, 1, N + 1) f[i] = abs(mu[i]);
	rep(i, 1, N + 1) hh[i] = (hh[i - 1] + qpow(i, k)) % mod;
	rep(i, 1, N + 1) h[i] = qpow(hh[i], x);
	rep(i, 1, N + 1) d_kx[i] = qpow(i, (ll) k * x + 1);
	rep(i, 1, N + 1) sum_d_kx[i] = (sum_d_kx[i - 1] + d_kx[i] * f[i] + mod) % mod;
}
ll get_h(int n){
	return h[n];
}
ll get_g(int n){
	if(g[n] != -1) return g[n];
	ll ans = 0;
	for(int l = 1,r;l <= n;l = r + 1){
    	int d = n / l;
    	r = n / d;
    	ans = (ans + (ll)(sum_d_x[r] - sum_d_x[l - 1] + mod) % mod * get_h(n / l) % mod) % mod;
	}
	return g[n] = ans;
}
ll get_dp(int n){
	if(dp[n] != -1) return dp[n];
	ll ans = 0;
	for(int l = 1,r;l <= n;l = r + 1){
    	int d = n / l;
    	r = n / d;
    	ans = (ans + (ll)(sum_d_kx[r] - sum_d_kx[l - 1] + mod)% mod * get_g(n / l) % mod) % mod;
	}
	return dp[n] = ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> T >> k >> x;
	memset(dp, -1, sizeof(dp));
	memset(g, -1, sizeof(g));
	init();
	while(T --){
		int n;
		cin >> n;
		cout << get_dp(n) << endl;
	}
	return 0;
}
/*
9 1 3
56
5
20
56
5
20
56
5
20
*/