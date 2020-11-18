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
int b[1000000 + 10];
int id[1000000 + 10];
int who[1000000 + 10];
int siz[1000000 + 10];
vi edge[1000000 + 10];
int dfs_cnt = 0;
void dfs(int rt, int fi){
	//cout << rt << " " << fi << endl;
	id[rt] = dfs_cnt;
	//cout << rt << " " << id[rt] << endl;
	who[dfs_cnt] = rt;
	dfs_cnt ++;
	siz[rt] = 1;
	for(auto i:edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
		siz[rt] += siz[i];
	}
}
struct node{
    int sum;
    int laze;
    int minn;
    int maxn;
};
template<class T>
struct segtree{
    static const int N = 4e6 + 10;
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
            nd[rt].sum = 0;
            nd[rt].maxn = 0;
            nd[rt].minn = 0;
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
segtree<int>seg;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, k;
	cin >> n >> k;
	rep(i, 1, n + 1){
		cin >> b[i];
	}
	stack<pii> st;
	for(int i = n; i >= 1; i --){
		if(st.size() == 0){
			edge[0].pb(i);
			edge[i].pb(0);
			st.push(mp(b[i], i));
		}
		else {
			while(st.size() != 0 && st.top().fi <= b[i]) st.pop();
			if(st.size() == 0){
				edge[0].pb(i);
				edge[i].pb(0);
			}
			else{
				edge[st.top().se].pb(i);
				edge[i].pb(st.top().se);
			}
			st.push(mp(b[i], i));
		}
	}
	dfs(0, -1);
	seg.build(1, n, 1);
	rep(i, 1, k){
		seg.updata(1, n, id[i], id[i] + siz[i] - 1, 1, 1);
		//cout << id[i] << " " << id[i] + siz[i] - 1 << endl;
	}
	rep(i, k, n + 1){
		if(i != k) seg.updata(1, n, id[i - k], id[i - k] + siz[i - k] - 1, -1, 1);
		seg.updata(1, n, id[i], id[i] + siz[i] - 1, 1, 1);
		//cout << id[i - k + 1] << " " << id[i - k + 1] + siz[i - k + 1] - 1 << endl;
		cout << seg.qry(1, n, 1, n, 1).maxn << " ";
	}
	return 0;
}