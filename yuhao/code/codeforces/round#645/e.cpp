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
ll a[1000000 + 10], b[1000000 + 10], sum[1000000 + 10];
struct node{
    ll sum;
    ll laze;
    ll minn;
    ll maxn;
};
template<class T>
struct segtree{
    static const int N = 3e6 + 10;
    node nd[N];
    void pushdown(int l, int r, int rt){
        int mid = (l + r) / 2;
        if(nd[rt].laze){
            nd[rt * 2].laze += nd[rt].laze;
            nd[rt * 2 + 1].laze += nd[rt].laze;
            nd[rt * 2].sum += (T) (mid - l + 1) * nd[rt].laze;
            nd[rt * 2 + 1].sum += (T) (r - mid) * nd[rt].laze;
            nd[rt * 2].minn += nd[rt].laze;
            nd[rt * 2 + 1].minn += nd[rt].laze;
            nd[rt * 2].maxn += nd[rt].laze;
            nd[rt * 2 + 1].maxn += nd[rt].laze;
            nd[rt].laze = 0;
        }
        return ;
    }
    void pushup(int l, int r, int rt){
        nd[rt].sum = nd[rt * 2].sum + nd[rt * 2 + 1].sum;
        nd[rt].minn = min(nd[rt * 2].minn, nd[rt * 2 + 1].minn);
        nd[rt].maxn = max(nd[rt * 2].maxn, nd[rt * 2 + 1].maxn);
    }
    void build(int l, int r, int rt){
        if(l == r){
            nd[rt].sum = b[l];
            nd[rt].maxn = b[l];
            nd[rt].minn = b[l];
            return ;
        }
        int mid = (l + r) / 2;
        build(l, mid, rt * 2);
        build(mid + 1, r, rt * 2 + 1);
        pushup(l, r, rt);
    }
    void updata(int l, int r, int ql, int qr, T val, int rt){
        if(l >= ql && r <= qr){
            nd[rt].laze += val;
            nd[rt].sum += (T) (r - l + 1) * val;
            nd[rt].maxn += val;
            nd[rt].minn += val;
            return ;
        }
        pushdown(l, r, rt);
        int mid= (l + r) / 2;
        if(ql <= mid) updata(l, mid, ql, qr, val, rt * 2);
        if(qr > mid) updata(mid + 1, r, ql, qr, val, rt * 2 + 1);
        pushup(l, r, rt);
        return ;
    }
    node qry(int l, int r, int ql, int qr, int rt){
        if(l >= ql && r <= qr){
            return nd[rt];
        }
        pushdown(l, r, rt);
        int mid = (l + r) / 2;
        node ans, ans1, ans2;
        if(ql <= mid && qr > mid) {
            ans1 = qry(l, mid, ql, qr, rt * 2);
            ans2 = qry(mid + 1, r, ql, qr, rt * 2 + 1);
            pushup(l, r, rt);
            ans.sum = ans1.sum + ans2.sum;
            ans.minn = min(ans1.minn, ans2.minn);
            ans.maxn = max(ans1.maxn, ans2.maxn);
            return ans;
        }
        if(ql <= mid) return qry(l, mid, ql, qr, rt * 2);
        else return  qry(mid + 1, r, ql, qr, rt * 2 + 1);;
    }
};
segtree<ll>seg;
int main(){
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, (n + 1) / 2 + 1) cin >> a[i];
	ll x;
	cin >> x;
	rep(i, (n + 1) / 2 + 1, n + 1) a[i] = x;
	rep(i, 1, n + 1){
		sum[i] = sum[i - 1] + a[i];
	}
	if(sum[n] > 0 ){
		cout << n << endl;
		return 0;
	}
	if(sum[n] < 0 && x >= 0){
		cout << "-1" << endl;
		return 0;
	}
	
	int ans = (n + 1) / 2 ;
	//cout << ans << endl;
	int flag = 1;
	rep(i, ans, n + 1){
		b[i - ans + 1] = sum[i] - sum[i - ans];
		if(b[i - ans + 1] <= 0 ) flag = 0;
	}
	if(flag){
		cout << ans << endl;
		return 0;
	}
	/*rep(i ,1, n - ans + 2){
		cout << b[i] << " ";
	}
	cout << endl;*/
	seg.build(1, n - ans + 1, 1);
	int res = -1;
	// cout << seg.qry(1, n - ans + 1, 1, n - ans + 1,1). minn << endl;
	rep(i, ans + 1, n + 1){
	//	cout << "?? " << x << endl;
		seg.updata(1, n - ans + 1, 1, n - i + 1, x, 1);
		if(seg.qry(1, n - ans + 1, 1, n - i + 1, 1).minn  > 0){
			res = i;
			break;
		}
		//cout << n - i + 1 << " " << seg.qry(1, n - i + 1, 1, n - i + 1, 1).minn << endl;
	}
	cout << res << endl;

	return 0;
}