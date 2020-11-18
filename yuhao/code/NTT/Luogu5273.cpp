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
int a[M], b[M], c[M];

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
    }
    void fast_pow(int *a, int *b, int na, int k){
    	b[0] = 1;
    	for (N = 1; N < (na << 1); N <<= 1);
    	work();
    	while(k){
    		FFT(a, 0);
    		if(k & 1){
    			FFT(b, 0);
    			rep(i, 0, N) b[i] = (ll)a[i] * b[i] % P;
    			FFT(b, 1);
    			rep(i, na, N) b[i] = 0;
    		}
    		rep(i, 0, N) a[i] = (ll)a[i] * a[i] % P;
    		FFT(a, 1);
    		rep(i, na, N) a[i] = 0;
    		k >>= 1;
    	}

    }
} ntt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 0, n) cin >> a[i];
	ntt.fast_pow(a, b, n, m);
	rep(i, 0, n) cout << b[i] << " ";
	return 0;
}