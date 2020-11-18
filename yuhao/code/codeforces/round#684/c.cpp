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
int a[200000 + 10];
const int N = 800000 + 10;
struct segtree{
	int minn[N], laze[N];
	ll sum[N];
	void pushdown(int l, int r, int rt){
		if(laze[rt]){
			int mid = (l + r) / 2;
			minn[rt * 2] = minn[rt * 2 + 1] = laze[rt];
			sum[rt * 2] = (ll)laze[rt] * (mid - l + 1);
			sum[rt * 2 + 1] = (ll)laze[rt] * (r - mid);
			laze[rt * 2] = laze[rt * 2 + 1] = laze[rt];
			laze[rt] = 0;
		}
		return ;
	}
	void pushup(int l, int r, int rt){
		minn[rt] = min(minn[rt * 2], minn[rt * 2 + 1]);
		sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
		return ;
	}
	void build(int l, int r, int rt){
		if(l == r){
			minn[rt] = sum[rt] = a[l];
			return ;
		}
		int mid = (l + r) / 2;
		build(l, mid, rt * 2);
		build(mid + 1, r, rt * 2 + 1);
		pushup(l, r, rt);
	}
	void updata(int l, int r, int ql, int qr, int val, int rt){
		if(ql <= l && qr >= r){
			minn[rt] = val;
			sum[rt] = (ll)(r - l + 1) * val;
			laze[rt] = val;
			return ;
		}
		pushdown(l, r, rt);
		int mid = (l + r) / 2;
		if(ql <= mid) updata(l, mid, ql, qr, val, rt * 2);
		if(qr > mid) updata(mid + 1, r, ql, qr, val, rt * 2 + 1);
		pushup(l, r, rt);
	}
	int qry_minpos(int l, int r, int ql, int qr, int val, int rt){
		//dd(l);dd(r);dd(ql);dd(qr);de(val);
		if(l == r) return l;
		pushdown(l, r, rt);
		int mid = (l + r) / 2;
		if(ql <= mid && minn[rt * 2] <= val) return qry_minpos(l, mid, ql, qr, val, rt * 2);
		else  return qry_minpos(mid + 1, r, ql, qr, val, rt * 2 + 1);
		pushup(l, r, rt);
	}
	ll qry_sum(int l, int r, int ql, int qr, int rt){
		if(l >= ql && r <= qr) return sum[rt];
		pushdown(l, r, rt);
		int mid = (l + r) / 2;
		ll ans = 0;
		if(ql <= mid) ans += qry_sum(l, mid ,ql, qr, rt * 2);
		if(qr > mid) ans += qry_sum(mid + 1, r, ql, qr, rt * 2 + 1);
		pushup(l, r, rt);
		return ans;
	}
	int qry_rpos(int l, int r, ll val, int rt){
		//dd(l);dd(r);dd(val);dd(sum[rt]);de(sum[rt * 2]);
		if(l == r) return l;
		pushdown(l, r, rt);
		int mid = (l + r) / 2;
		int ans = 0;
		if(sum[rt * 2] <= val) ans = qry_rpos(mid + 1, r, val - sum[rt * 2], rt * 2 + 1);
		else ans = qry_rpos(l, mid, val, rt * 2);
		pushup(l, r, rt);
		return ans;
	}
}seg;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, q;
	cin >> n >> q;
	rep(i, 1, n + 1){
		cin >> a[i];
	}
	seg.build(1, n + 1, 1);
	while(q --){
		int op, x, y;
		cin >> op >> x >> y;
		if(op == 1){
			int pos = seg.qry_minpos(1, n + 1, 1, n, y, 1);
			seg.updata(1, n + 1, pos, x, y, 1);
		}
		else{
			int ans = 0;
			while(x <= n){
				int pos = seg.qry_minpos(1, n + 1, x, n, y, 1);
				//dd(y);de(pos);
				ll presum = 0;
				if(pos != 1) presum = seg.qry_sum(1, n + 1, 1, pos - 1, 1);
				//de(presum);
				int r = seg.qry_rpos(1, n + 1, y + presum, 1);
				y -= seg.qry_sum(1, n + 1, 1, r - 1, 1) - presum ;
				ans += r - pos;
				x = r;
				//dd(y);de(r);
				//break;
			}
			cout << ans << endl;
			//cout << endl;
		}
	}
	return 0;
}
/*
10 6
10 10 10 6 6 5 5 5 3 1
2 3 50
2 4 10
1 3 10
2 2 36
1 4 7
2 2 17


*/