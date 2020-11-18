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
    void solve(int a[], int b[], int n){
        fwt(a, n, 0);
        fwt(b, n, 0);
        rep(i, 0, n) a[i] = mul(a[i], b[i]);
        fwt(a, n, 1);
    }
}Fwt;