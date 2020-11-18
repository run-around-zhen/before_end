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
template<class U>
struct node{
    double sum;
    int laze;
    int minn;
    int maxn;
    int num;
};
template<class T>
struct segtree{
    static const int N = 8e5 + 10;
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
        nd[rt].num = nd[rt * 2].num + nd[rt * 2 + 1].num;
    }
    void build(int l, int r, int rt, int a[]){
        if(l == r){
            nd[rt].sum = a[l];
            nd[rt].maxn = a[l];
            nd[rt].minn = a[l];
            nd[rt].num = a[l];
            return ;
        }
        int mid = (l + r) / 2;
        build(l, mid, rt * 2, a);
        build(mid + 1, r, rt * 2 + 1,  a);
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
segtree<double>seg;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, q;
	cin >> n >> q;
	int cnt = 1;
	rep(i, 1, n + 1) {
		cin >> a[i];
		x[cnt ++] = a[i];
	}
	while(q -- ){
		ll type, x, y;
		cin >> type;
		if(type == 1){

		}

	}
	return 0;
}