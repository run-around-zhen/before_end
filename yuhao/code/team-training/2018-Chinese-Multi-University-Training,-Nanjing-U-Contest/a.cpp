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
const int M = 2e6 + 10;
int a[M], b[M], c[M], d[M], e[M], f[M];

struct NTT{
    static const int G = 3, P = 998244353; //P = C*2^k + 1
    int N, na, nb, w[2][M], rev[M];
    ll kpow(ll a, int b){
        ll c = 1;
        for (; b; b >>= 1,a = a * a % P) if (b & 1) c = c * a %P;
        return c;
    }
    void FFT(int *a, int f){
        rep(i, 0, N) if (i < rev[i]) swap(a[i], a[rev[i]]);
        for (int i = 1; i < N; i <<= 1)
            for (int j = 0, t = N / (i << 1); j < N; j += i << 1)
                for (int k = 0, l = 0, x, y; k < i; k++, l += t)
                    x = (ll) w[f][l] * a[j+k+i] % P, y = a[j+k], a[j+k] = (y+x) % P, a[j+k+i] = (y-x+P) % P;
        if (f) for (int i = 0, x = kpow(N, P-2); i < N; i++) a[i] = (ll)a[i] * x % P;
    }
    void work(){
        int d = __builtin_ctz(N);
        w[0][0] = w[1][0] = 1;
        for (int i = 1, x = kpow(G, (P-1) / N), y = kpow(x, P-2); i < N; i++) {
            rev[i] = (rev[i>>1] >> 1) | ((i&1) << (d-1));
            w[0][i] = (ll)x * w[0][i-1] % P, w[1][i] = (ll) y * w[1][i-1] % P;
        }
    }
    void doit(int *a, int *b, int na, int nb){ // [0, na)
        for (N = 1; N < na + nb - 1; N <<= 1);
        rep(i, na, N) a[i] = 0;
        rep(i, nb, N) b[i] = 0;
        work(), FFT(a,0), FFT(b,0);
        rep(i, 0, N) a[i] = (ll)a[i] * b[i] % P;
        FFT(a, 1);
    //    rep(i, 0, N) cout << a[i] << " ";
    }
    void get_inv(int *a, int *b, int na){
        if(na == 1) {
            b[0] = kpow(a[0], P - 2);
            return ;
        }
        get_inv(a, b, (na + 1) >> 1);
        for (N = 1; N < (na << 1); N <<= 1);
        work();
        rep(i, 0, na) c[i] = a[i];
        rep(i, na, N) c[i] = 0;
        FFT(c, 0), FFT(b, 0);
        rep(i, 0, N) b[i] = 1ll * (2 - 1ll * c[i] * b[i] % P + P) % P * b[i] % P;
        FFT(b, 1);
        rep(i, na, N) b[i] = 0;
     //   rep(i, 0, N) cout << b[i] << " ";
    }
    void get_ln(int *a, int *b, int na){
        rep(i, 0, na - 1) d[i] = (ll)(a[i + 1]) * (i + 1) % P;
        rep(i, na, N) d[i] = 0;
        d[na - 1] = 0;
        get_inv(a, b, na);
        doit(b, d, na, na);
        per(i, 1, na) b[i] = (ll) b[i - 1] * kpow(i, P - 2) % P;
        b[0] = 0;
 //       rep(i, 0, na) cout << b[i] << " ";
    }
    void get_exp(int *a, int *b, int na){
        if(na == 1) {
            b[0] = 1;
            return ;
        }
        get_exp(a, b, (na + 1) >> 1);
        for(int i = 0; i < (na << 1) ; i ++) f[i] = 0;
        get_ln(b, f, na); 
        for (N = 1; N < (na << 1); N <<= 1); 
        work();
        f[0] = ((ll)a[0] + 1 - f[0] + P) % P;
        rep(i, 1, na) f[i] = ((ll)a[i] - f[i] + P) % P;
        FFT(f, 0);
        FFT(b, 0);
        rep(i, 0, N) b[i] = (ll)b[i] * f[i] % P;
        FFT(b, 1);
        rep(i, na, N) b[i] = f[i] = 0;
       // rep(i, 0, na) cout << b[i] << " ";
    }
    void get_pow(int *a, int *b, int na, int k){
        get_ln(a, e, na);
        rep(i, 0, na) e[i] = (ll)e[i] * k % P;
        get_exp(e, b, na);
         //rep(i, 0, na) cout << b[i] << " ";

    }
    void fast_pow(int *a, int *b, int na, int k, int maxn){
        // k 为快速幂次数 maxn为所求答案 复杂度o(n)(log)(log)
        for (N = 1; N < max(((maxn + 1) << 1),(na << 1)); N <<= 1);
        rep(i, na, N) a[i] = 0;
        rep(i, 0, N) b[i] = 0;
        b[0] = 1;
        work();
        while(k){
            FFT(a, 0);
            if(k & 1){
                FFT(b, 0);
                rep(i, 0, N) b[i] = (ll)a[i] * b[i] % P;
                FFT(b, 1);
                rep(i, max(na, maxn + 1), N) b[i] = 0;
            }
            rep(i, 0, N) a[i] = (ll)a[i] * a[i] % P;
            FFT(a, 1);
            rep(i, max(na, maxn + 1), N) a[i] = 0;
            k >>= 1;
        }
        // rep(i, 0, N) cout << b[i] << " ";
    }
} ntt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n, m, k;
		cin >> n >> m >> k;
		if((n - 1) * m < k ) {
			cout << "0" << endl;
			continue;
		}
		rep(i, 0, n) a[i] = 1;
		ntt.get_pow(a, b, max(n, k + 1), m);
		cout << b[k] << endl;
		rep(i, 0, max(n, (k + 1)) << 1) b[i] = a[i] = c[i] = d[i] = e[i] = f[i] = 0;
		//cout << k << endl;
		//
	}
	
	return 0;
}