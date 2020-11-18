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
int cnt = 0;
vi v, prime;
int ans[100000 + 10];
bool vis[100000 + 10];
int acc[100000 + 10];
void cal(int i){
	vis[i] = true;
	cnt ++;
	if(!vis[acc[i]]) cal(acc[i]);
	return ;
}
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = res * a;
		b /= 2;
		a = a * a;
	}
	return res;
}
const int M = 2e6 + 10;
int a[M], b[M], c[M], d[M], e[M], f[M];
vi T[M];
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
    priority_queue<pii> H;
    void Merge(int m){
        // m 为size
        while(!H.empty()) H.pop();
        rep(i, 1, m + 1) H.emplace(mp(-T[i].size(), i));
        while(H.size() >= 2){
            int x = H.top().se; H.pop();
            int y = H.top().se; H.pop();
           // cout <<"!";
            rep(i, 0, T[x].size()) {
            	a[i] = T[x][i];
            //	cout << a[i] << " ";
            }
           // cout << endl;
           // cout <<"!!";
            rep(i, 0, T[y].size()) {
            	b[i] = T[y][i];
            	//cout << b[i] << " ";
            }
          //  cout << endl;
            doit(a, b, T[x].size(), T[y].size());
            int na = T[x].size() + T[y].size();
            /*rep(i, 0, na){
            	cout << a[i] << " ";
            }
            cout << endl;*/
            int len1 = na;
            rep(i, 0, na){
            	if(i != na - 1){
            		a[i + 1] += a[i] / 10;
            		a[i] %= 10;
            	}
            }
           	int tmp = a[na - 1];
           	na --;
           	while(tmp){
           		a[na] = tmp % 10;
           		tmp /= 10;
           		na ++; 
           	}
           	int len2 = na;
           /*rep(i, 0, na){
           		cout << a[i] << " ";
           	}
           	cout << endl;*/
            T[x].clear(); T[y].clear();
            rep(i, 0, na) T[x].pb(a[i]);
            rep(i, 0, na) a[i] = 0;
            H.emplace(- T[x].size(), x);
        }
    }

} ntt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		cin >> acc[i];
	}
	rep(i, 1, n + 1){
		if(!vis[i]) {
			cnt = 0;
			cal(i);
			v.pb(cnt);
		}
	}
	for(int i = 2; i <= 100000; i ++){
		int flag = 0;
		for(int j = 2; j * j <= i; j ++){
			if(i % j == 0){
				flag = 1;
				break;
			}
		}
		if(!flag){
			prime.pb(i);
		}
	}
	for(auto i: v){
		rep(j, 0, (int)prime.size()){
			if(prime[j] * prime[j] > i) break;
			int sum = 0;
			if(i % prime[j] == 0){
				while(i % prime[j] == 0){
					i /= prime[j];
					sum ++;
				}
			}
			ans[prime[j]] = max(ans[prime[j]], sum);
		}
		ans[i] = max(ans[i], 1);
	}
	int m = 1;
	rep(j, 1, 100001){
		if(ans[j]){
			int res = qpow(j, ans[j]);
			//cout << res << endl;
			while(res){
				T[m].pb(res % 10);
				res /= 10;
			}
			m ++;
		}
	}
	ntt.Merge(m - 1);
	//cout << ntt.H.top().se << endl;
	int siz = T[ntt.H.top().se].size();
	per(i, 0, min(n, siz)){
		cout << T[ntt.H.top().se][i];
	}
	/*cout << endl;
	ll sum1 = 0;
	ll tmp1 = 1;
	rep(i, 0, siz){
		sum1 += T[ntt.H.top().se][i] * tmp1;
		tmp1 *= 10;
	}
	cout << sum1 << endl;*/
	return 0;
}