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
typedef double db;
const db PI = acos(-1);
const int M = 1 << 18 << 1;
int na, nb, a[M], b[M]; 
vector<int> T[M];
const int P = 1009;
struct vir{
    db r, i;
    vir(db r = 0.0, db i = 0.0) : r(r), i(i){}
    inline vir operator +(const vir &c) {return vir(r + c.r, i + c.i);}
    inline vir operator -(const vir &c) {return vir(r - c.r, i - c.i);}
    inline vir operator *(const vir &c) {return vir(r * c.r - i * c.i, r * c.i + i * c.r);}
    inline vir operator !() const {return vir(r, -i);}
    void print() {printf("%lf %lf\n", r, i);}
};
struct FFTMOD{
    static const int M = 1 << 18 << 1;
    int N, L, MASK;
    vir w[M], A[M], B[M], C[M], D[M];
    void FFT(vir p[], int n) {
        for (int i = 1, j = 0; i < n - 1; ++i) {
            for (int s = n; j ^= s >>= 1, ~j & s;);
            if (i < j) swap(p[i], p[j]);
        }
        for (int d = 0; (1 << d) < n; ++d) {
            int m = 1 << d, m2 = m * 2, rm = n >> (d + 1);
            for (int i = 0; i < n; i += m2) {
                for (int j = 0; j < m; ++j) {
                    vir &p1 = p[i + j + m], &p2 = p[i + j];
                    vir t = w[rm * j] * p1;
                    p1 = p2 - t, p2 = p2 + t;
                }
            }
        }
    }
    void doit(int *a, int *b, int na, int nb){
        for (N = 1; N < na + nb - 1; N <<= 1);
        rep(i, 0, na) a[i] = (a[i] % P + P) % P; rep(i, na, N) a[i] = 0;
        rep(i, 0, nb) b[i] = (b[i] % P + P) % P; rep(i, nb, N) b[i] = 0;
        L = 15; MASK = (1<<L) - 1;
        rep(i, 0, N) w[i] = vir(cos(2 * i * PI / N), sin(2 * i * PI / N));
        rep(i, 0, N) {
            A[i] = vir(a[i] >> L, a[i] & MASK);
            B[i] = vir(b[i] >> L, b[i] & MASK);
        }
        mul(a);
    }
    void mul(int *a) {
        FFT(A, N), FFT(B, N);
        rep(i, 0, N) {
            int j = (N - i) % N;
            vir da = (A[i] - !A[j]) * vir(0, -0.5),
                    db = (A[i] + !A[j]) * vir(0.5, 0),
                    dc = (B[i] - !B[j]) * vir(0, -0.5),
                    dd = (B[i] + !B[j]) * vir(0.5, 0);
            C[j] = da * dd + da * dc * vir(0, 1);
            D[j] = db * dd + db * dc * vir(0, 1);
        }
        FFT(C, N), FFT(D, N);
        rep(i, 0, N) {
            ll  da = (ll)(C[i].i / N + 0.5) % P,
                    db = (ll)(C[i].r / N + 0.5) % P,
                    dc = (ll)(D[i].i / N + 0.5) % P,
                    dd = (ll)(D[i].r / N + 0.5) % P;
            a[i] = ((dd << (L * 2)) + ((db + dc) << L) + da) % P;
        }
    }
    priority_queue<pii> H;
    void Merge(int m){
        // m 为size
        while(!H.empty()) H.pop();
        rep(i, 1, m + 1) H.emplace(mp(-T[i].size(), i));
        while(H.size() >= 2){
            int x = H.top().se; H.pop();
            int y = H.top().se; H.pop();
            rep(i, 0, T[x].size()) a[i] = T[x][i];
            rep(i, 0, T[y].size()) b[i] = T[y][i];
            doit(a, b, T[x].size(), T[y].size());
            int na = T[x].size() + T[y].size();
            T[x].clear(); T[y].clear();
            rep(i, 0, na) T[x].pb(a[i]);
            H.emplace(- T[x].size(), x);
        }
    }
} fft;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, 1, m + 1) T[i].pb(1);
    rep(i, 0, n){
        int x;
        cin >> x;
        T[x].pb(1);
    }
    fft.Merge(m);
    cout << T[fft.H.top().se][k] << endl;
    return 0;
}