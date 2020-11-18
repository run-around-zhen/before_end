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
const int M = 2000000 + 10;
const db pi = acos(-1);
int  sum[M], cnt[M];
struct vir{
	db r, i;
	vir(db r = 0.0, db i = 0.0) : r(r), i(i){}
	void print() {printf("%f %f\n", r, i);}
	vir operator +(const vir &c) {return vir(r + c.r, i + c.i);}
	vir operator -(const vir &c) {return vir(r - c.r, i - c.i);}
	vir operator *(const vir &c) {return vir(r * c.r - i * c.i, r * c.i + i * c.r);}
} a[M], b[M], w[2][M];

struct FFT{
	int N, na, nb, rev[M];
	void fft(vir *a, int f){
		vir x, y;
		rep(i, 0, N) if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int i = 1; i < N; i <<= 1)
			for (int j = 0, t = N/(i<<1); j < N; j += i<<1)
				for (int k = 0, l = 0; k < i; k++, l += t) 
					x = w[f][l] * a[j+k+i], y = a[j+k], a[j+k] = y+x, a[j+k+i] = y-x;
		if (f) rep(i, 0, N) a[i].r /= N;
	}
	void work(){
		int d = __builtin_ctz(N);
		rep(i, 0, N) {
			rev[i] = (rev[i>>1] >> 1) | ((i&1) << (d-1));
			w[1][i] = w[0][i] = vir(cos(2*pi*i/N), sin(2*pi*i/N));
			w[1][i].i = -w[1][i].i;
		}
	}	
	void doit(vir *a, vir *b, int na, int nb){ // [0, na)
		for (N = 1; N < na + nb - 1; N <<= 1);
		rep(i, na, N) a[i] = vir(0, 0);
		rep(i, nb, N) b[i] = vir(0, 0);
		work(), fft(a, 0), fft(b, 0);
		rep(i, 0, N) a[i] = a[i] * b[i];
		fft(a, 1);
		//rep(i, 0, N) a[i].print();
	}
} fft;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, x;
	cin >> n >> x;
	cnt[0] = 1;
	rep(i, 1, n + 1){
		int xx;
		cin >> xx;
		if(xx < x) sum[i] = 1;
		if(i) sum[i] += sum[i - 1];
		cnt[sum[i]] ++;
	}
	ll ans = 0;
	rep(i, 0, n + 1) ans += (ll)cnt[i] * (cnt[i] - 1) / 2;
	rep(i, 0, n + 1) a[i] = vir(cnt[i], 0);
	rep(i, 0, n + 1) b[n - i] = vir(cnt[i], 0);
	fft.doit(a, b, n + 1, n + 1);
	cout << ans << " ";
	rep(i, n + 1, 2 * n + 1) cout << (ll)(a[i].r + 0.5)<< " ";
	return 0;
}