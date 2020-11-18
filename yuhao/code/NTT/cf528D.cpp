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
const int M = 800000 + 10;
const db pi = acos(-1);
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
int id(char a){
	if(a == 'A') return 0;
	else if(a == 'T') return 1;
	else if(a == 'C') return 2;
	else  return 3;
}
int ans[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	string s, t;
	cin >> s >> t;
	reverse(all(t));
	rep(q, 0, 4){
		rep(i, 0, m) {
			if(id(t[i]) == q) b[i] = vir(1, 0);
			else b[i] = vir(0, 0);
		}
		int last = -1e9;
		rep(i, 0, k) if(id(s[i]) == q) last = i;
		rep(i, 0, n){
			if(i + k < n && id(s[i + k]) == q  ) last = i + k;
			if(abs(last - i) <= k){
				a[i] = vir(1, 0);
			}
			else{
				a[i] = vir(0, 0);
			}
		}
		/*rep(i, 0, n){
			cout << a[i].r << " ";
		}
		cout << endl;
		rep(i, 0, m){
			cout << b[i].r << " ";
		}
		cout << endl;*/
		fft.doit(a, b, n, m);
		rep(i, 0, fft.N) ans[i] += (int)((a[i].r) + 0.5);
	}
	int res = 0;
	rep(i, m - 1, n + 1) if(ans[i] == m) res ++;
	cout << res << endl;
	return 0;
}