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
int n;
int f[200000 + 10], a[200000 + 10];
const int MAXN = 200000;
struct node{
    int sum;
    int ans;
};
template<class T>
struct segtree{
    static const int N = 24e5 + 10;
    node nd[N];
    void build(int l, int r, int rt){
        if(l == r && l > MAXN && l <= n + MAXN){
            nd[rt].sum = 1;
            nd[rt].ans = a[l - MAXN];
            return ;
        }
        if(l == r) return ;
        int mid = (l + r) / 2;
        build(l, mid, rt * 2);
        build(mid + 1, r, rt * 2 + 1);
        nd[rt].sum = nd[rt * 2].sum + nd[rt * 2 + 1].sum;
    }
    void updata(int l, int r, int pos, int val, int x, int rt){
    	if(l == r){
    		nd[rt].sum = val;
    		nd[rt].ans = x;
    		return ;
    	}
    	int mid = (l + r) / 2;
    	if(pos <= mid) updata(l, mid, pos, val, x, rt * 2);
    	else updata(mid + 1, r, pos, val, x, rt * 2 + 1);
    	nd[rt].sum = nd[rt * 2].sum + nd[rt * 2 + 1].sum;
    }
    int qry(int l, int r, int k, int rt){
    	if(l == r){
    		return nd[rt].ans;
    	}
    	int mid = (l + r) / 2;
    	if(nd[rt * 2].sum >= k) return qry(l, mid, k, rt * 2);
    	else return qry(mid + 1, r, k - nd[rt * 2].sum, rt * 2 + 1);
    }
};
segtree<int>seg;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n + 1) {
		a[i] = i;
		f[i] = MAXN + i;
	}
	seg.build(1, 3 * MAXN, 1);
	int q;
	cin >> q;
	int begin = MAXN;
	int end = n + MAXN + 1;
	while(q --){
		int type, x;
		cin >> type >> x;
		if(type == 1){
			seg.updata(1, 3 * MAXN, f[x], 0, 0, 1);
			seg.updata(1, 3 * MAXN, begin, 1, x, 1);
			f[x] = begin;
			begin --;
		}
		else if(type == 2){
			seg.updata(1, 3 * MAXN, f[x], 0, 0, 1);
			seg.updata(1, 3 * MAXN, end, 1, x, 1);
			f[x] = end;
			end ++;
		}
		else{
			cout << seg.qry(1, 3 * MAXN, x, 1) << endl;
		}
	}
	return 0;
}