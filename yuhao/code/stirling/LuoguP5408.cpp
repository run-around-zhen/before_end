#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(argT i=(a); i<(b); i++)
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
const int M = 2e6 + 10;
typedef unsigned int argT;
typedef unsigned long long returnT;
argT a[M], b[M], c[M], d[M], e[M], f[M];
vi T[M];
struct NTT{
    static const argT G = 3, P = 167772161; //P = C*2^k + 1
    argT N, na, nb, w[2*M], rev[M];
    int add(int a, int b){
    	if(a + b >= P) return a + b - P;
    	return a + b;
    }
    inline returnT kpow(returnT a, argT b){
        returnT c = 1;
        for (; b; b >>= 1,a = a * a % P) if (b & 1) c = c * a %P;
        return c;
    }
    inline void FFT(argT *a, argT f){
        rep(i, 0, N) if (i < rev[i]) swap(a[i], a[rev[i]]);
        for (argT i = 1; i < N; i <<= 1){
        	const argT lim=N / (i << 1);
            for (argT j = 0, t = lim; j < N; j += i << 1)
                for (argT k = 0, l = 0, x, y; k < i; ++k, l += t)
                    x = (returnT) w[f*M+l] * a[j+k+i] % P, y = a[j+k], a[j+k] = add(x, y), a[j+k+i] = add(y, -x + P);
        }
        if (f) for (argT i = 0, x = kpow(N, P-2); i < N; i++) a[i] = (returnT)a[i] * x % P;
    }
    inline void work(){
        argT d = __builtin_ctz(N);
        w[0*M+0] = w[1*M+0] = 1;
        for (argT i = 1, x = kpow(G, (P-1) / N), y = kpow(x, P-2); i < N; i++) {
            rev[i] = (rev[i>>1] >> 1) | ((i&1) << (d-1));
            w[0*M+i] = (returnT)x * w[0*M+i-1] % P, w[1*M+i] = (returnT) y * w[1*M+i-1] % P;
        }
    }
    inline void doit(argT *a, argT *b, argT na, argT nb){ // [0, na)
        for (N = 1; N < na + nb - 1; N <<= 1);
        rep(i, na, N) a[i] = 0;
        rep(i, nb, N) b[i] = 0;
        work(), FFT(a,0), FFT(b,0);
        rep(i, 0, N) a[i] = (returnT)a[i] * b[i] % P;
        FFT(a, 1);
    //    rep(i, 0, N) cout << a[i] << " ";
    }
    priority_queue<pii> H;
    inline void Merge(argT m){
        // m 为size
        while(!H.empty()) H.pop();
        rep(i, 1, m + 1) H.emplace(mp(-(int)T[i].size(), i));
        while(H.size() >= 2){
            argT x = H.top().se; H.pop();
            argT y = H.top().se; H.pop();
            rep(i, 0, (argT)T[x].size()) a[i] = T[x][i];
            rep(i, 0, (argT)T[y].size()) b[i] = T[y][i];
            doit(a, b, T[x].size(), T[y].size());
            argT na = T[x].size() + T[y].size();
            T[x].clear(); T[y].clear();
            rep(i, 0, na) T[x].pb(a[i]);
            H.emplace(- (int)T[x].size(), x);
        }
    }

} ntt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	argT n;
	cin >> n;
	rep(i, 1, n + 1){
		T[i].pb(i - 1);
		T[i].pb(1);
	}
	ntt.Merge(n);
	argT id = ntt.H.top().se;
	rep(i, 0, n + 1) cout << a[i] << " " ;
	cout << endl;
	return 0;
}