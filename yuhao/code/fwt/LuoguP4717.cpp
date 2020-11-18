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
int a[300000], b[300000], c[300000], d[300000], e[300000], f[300000];
ll mod = 998244353;
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
struct FWT{
    int mod = 998244353;
    int rev = qpow(2, mod - 2);
    int add(int a, int b){
        if(a + b >= mod) return a + b - mod;
        if(a + b < 0) return a + b + mod;
        return a + b;
    }
    int mul(int a, int b){
        return (ll)a * b % mod;
    }
    void fwt(int a[], int n, int op){
        for(int d = 1; d < n; d <<= 1){
            for(int m = d << 1, i = 0; i < n; i += m){
                for(int j = 0; j < d; j ++){
                    int x = a[i + j], y = a[i + j + d];
                    if(op == 0) a[i + j] = add(x, y), a[i + j + d] = add(x, -y);
                    else a[i + j] = mul(add(x, y), rev), a[i + j + d] = mul(add(x, -y), rev);
                    //xor : a[i + j] = add(x, y), a[i + j + d] = add(x, -y);
                    //	  a[i + j] = mul(add(x, y), rev), a[i + j + d] = mul(add(x, -y), rev);
                    //and : a[i + j] = add(x, y);
                    //      a[i + j] = add(x, -y);
                    //or  : a[i + j + d] = add(x, y);
                    //      a[i + j + d] = add(y, -x);
                }
            }
        }
    }
    void fwt1(int a[], int n, int op){
        for(int d = 1; d < n; d <<= 1){
            for(int m = d << 1, i = 0; i < n; i += m){
                for(int j = 0; j < d; j ++){
                    int x = a[i + j], y = a[i + j + d];
                    if(op == 0) a[i + j] = add(x, y);
                    else a[i + j] = a[i + j] = add(x, -y);
                    //xor : a[i + j] = add(x, y), a[i + j + d] = add(x, -y);
                    //	  a[i + j] = mul(add(x, y), rev), a[i + j + d] = mul(add(x, -y), rev);
                    //and : a[i + j] = add(x, y);
                    //      a[i + j] = add(x, -y);
                    //or  : a[i + j + d] = add(x, y);
                    //      a[i + j + d] = add(y, -x);
                }
            }
        }
    }
    void fwt2(int a[], int n, int op){
        for(int d = 1; d < n; d <<= 1){
            for(int m = d << 1, i = 0; i < n; i += m){
                for(int j = 0; j < d; j ++){
                    int x = a[i + j], y = a[i + j + d];
                    if(op == 0) a[i + j + d] = add(x, y);
                    else a[i + j + d] = add(y, -x);
                    //xor : a[i + j] = add(x, y), a[i + j + d] = add(x, -y);
                    //	  a[i + j] = mul(add(x, y), rev), a[i + j + d] = mul(add(x, -y), rev);
                    //and : a[i + j] = add(x, y);
                    //      a[i + j] = add(x, -y);
                    //or  : a[i + j + d] = add(x, y);
                    //      a[i + j + d] = add(y, -x);
                }
            }
        }
    }
    void solve(int a[], int b[], int n){
    	fwt(a, n, 0);
    	fwt(b, n, 0);
    	rep(i, 0, n) a[i] = mul(a[i], b[i]);
    	fwt(a, n, 1);
    }
    void solve1(int a[], int b[], int n){
    	fwt1(a, n, 0);
    	fwt1(b, n, 0);
    	rep(i, 0, n) a[i] = mul(a[i], b[i]);
    	fwt1(a, n, 1);
    }
    void solve2(int a[], int b[], int n){
    	fwt2(a, n, 0);
    	fwt2(b, n, 0);
    	rep(i, 0, n) a[i] = mul(a[i], b[i]);
    	fwt2(a, n, 1);
    }
}Fwt;
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	n = (1 << n);
	rep(i, 0, n) {
		cin >> a[i];
		c[i] = e[i] = a[i];
	}
	rep(i, 0, n){
		cin >> b[i];
		d[i] = f[i] = b[i];
	}
	Fwt.solve(a, b, n);
	Fwt.solve1(c, d, n);
	Fwt.solve2(e, f, n);
	rep(i, 0, n) cout << e[i] << " ";
	cout << endl;
	rep(i, 0, n) cout << c[i] << " ";
	cout << endl;
	rep(i, 0, n) cout << a[i] << " ";
	cout << endl;
	return 0;
}