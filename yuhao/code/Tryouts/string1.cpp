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
int a[200000 + 10];
struct node{
    ll sum;
};
const int mod = 1e9 + 7;
ll doit(ll a, ll b){
	if(a + b >= mod) return a + b - mod;
	return a + b;
}
const int MAXN = 1000000;
int cnt =0 ;
template<class T>
struct segtree{
    static const int N = 8e6 + 10;
    node nd[N];
    void pushup(int l, int r, int rt){
        nd[rt].sum = doit(nd[rt * 2].sum, nd[rt * 2 + 1].sum);
    //    nd[rt].sum %= mod;
    }
    void build(int l, int r, int rt){
        if(l == r){
            nd[rt].sum = 0;
            return ;
        }
        int mid = (l + r) / 2;
        build(l, mid, rt * 2);
        build(mid + 1, r, rt * 2 + 1);
        pushup(l, r, rt);
    }
    void updata(int l, int r, int ql, int qr, T val, int rt){
        if(l >= ql && r <= qr){
            nd[rt].sum += (T) (r - l + 1) * val;
          //  nd[rt].sum %= mod;
            return ;
        }
        int mid = (l + r) / 2;
        if(ql <= mid) updata(l, mid, ql, qr, val, rt * 2);
        if(qr > mid) updata(mid + 1, r, ql, qr, val, rt * 2 + 1);
        pushup(l, r, rt);
        return ;
    }
    ll qry(int l, int r, int ql, int qr, int rt){
        if(l >= ql && r <= qr){
            return nd[rt].sum;
        }
        int mid = (l + r) / 2;
        ll ans = 0;
        if(ql <= mid) ans += qry(l, mid, ql, qr, rt * 2);
        if(qr > mid) ans += qry(mid + 1, r, ql, qr, rt * 2 + 1);
        return ans % mod;
    }
};
segtree<ll>seg, rev_seg;
ll base[2 * MAXN + 10];
ll inv[2 * MAXN + 10];
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		b /= 2;
		a = a * a % mod;
	}
	return res;
}
int len = 1;
int get(string s){
	return (s[len - 1] - '0') * 2 + (s[len] - '0');
}
ll cal(int l, int r){	
	return (ll)seg.qry(1, 2 * MAXN, l, r, 1) * inv[l]% mod;
}
ll rev_cal(int l, int r){
	return (ll)rev_seg.qry(1, 2 * MAXN, l, r, 1) * inv[l] % mod;
}
string xans = "11";
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	inv[0] = 1;
	base[0] = 1;
	inv[1] = qpow(29, mod - 2);
	base[1] = 29;
	rep(i, 2, 2000000 + 1){
		base[i] = base[i - 1] * 29 % mod;
		inv[i] = inv[i - 1] * inv[1] % mod;
	}
	seg.build(1, MAXN * 2, 1);
	rev_seg.build(1, MAXN * 2, 1);
	int Q;
	cin >> Q;
	
	int begin = MAXN, end = MAXN - 1;
	int rev_begin = MAXN, rev_end = MAXN - 1;
	int k1 = 1, k2 = 1;
	while(Q --){
		int type;
		cin >> type;
		type ^= (k1 * 2 + k2);
		if(type == 0){
			char x;
			cin >> x;
			begin --;
			seg.updata(1, 2 * MAXN, begin, begin, (ll)(x - 'a' + 1) * base[begin] % mod, 1);
			rev_end ++;
			rev_seg.updata(1, 2 * MAXN, rev_end, rev_end, (ll)(x - 'a' + 1) * base[rev_end] % mod, 1);
			
		}
		else if(type == 1){
			char x;
			cin >> x;
			end ++;
			seg.updata(1, 2 * MAXN, end, end, (ll)(x - 'a' + 1) * base[end] % mod, 1);
			rev_begin --;
			rev_seg.updata(1, 2 * MAXN, rev_begin, rev_begin, (ll)(x - 'a' + 1) * base[rev_begin] % mod, 1);
		}
		else if(type == 2){
			len ++;
			int t;
			cin >> t;
			if(t == 0){
				cout << "Yes" << endl;
				k1 = k2;
				k2 = 1;
				continue;
			}
			int flag = 0;
			int len = end - begin + 1;
			int tmp = len / t;
			if(tmp == 1){
				flag = 1;
			}
			else{
				if(cal(begin, begin + (tmp - 1) * t - 1) == cal(begin + t ,begin + tmp * t - 1)){
					flag = 1;
				}
			}
			if(tmp * t != len){
				if(cal(begin, begin + len % t - 1) != cal(end - len % t + 1, end)) flag = 0;
			}
			if(flag){
				cout << "Yes" << endl;
			k1 = k2;
				k2 = 1;
			}
			else{
				cout << "No" << endl;
				k1 = k2;
				k2 = 0;
			}
		}
		else if(type == 3){
			len ++;
			if(cal(begin, end) == rev_cal(rev_begin, rev_end)){
				cout << "Yes" << endl;
				k1 = k2;
				k2 = 1;
			}
			else{
				cout << "No" << endl;
				k1 = k2;
				k2 = 0;
			}
		}
	}
	return 0;
}