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
vi edge[100000 + 10];
vector<pair<int, int> > v[500000 + 10], v1[500000 + 10];
struct node1{
    ll l, r, z, val, pos;
}a[500000 + 10];
int n;
struct node{
    ll sum;
    ll laze;
    ll minn;
    ll maxn;
}ans;
template<class T>
struct segtree{
    static const int N = 8e6 + 10;
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
    void build(int l, int r, int rt, int a[]){
        if(l == r){
            nd[rt].sum = a[l];
            nd[rt].maxn = a[l];
            nd[rt].minn = a[l];
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
segtree<ll>seg;
ll res;
struct HeavyChain{
    static const int N = 1e6 + 10;
    int sz[N], wson[N], top[N], dep[N], id[N], dfs_cnt, par[N], who[N];
    void dfs(int rt, int fa, vi g[]){
        sz[rt] = 1;
        par[rt] = fa;
        dep[rt] = dep[fa] + 1;
        int &s = wson[rt] = top[rt] = 0;
        for(auto t : g[rt]) {
            if(t == fa)  continue;
            dfs(t, rt, g);
            sz[rt] += sz[t];
            if(sz[t] >= sz[s]) s = t;
        }
    }
    void dfs2(int rt, int fa, vi g[]){
        id[rt] = ++dfs_cnt;
        who[dfs_cnt] = rt;
        int s = wson[rt];
        if(!top[rt]) top[rt] = rt;
        if(s) top[s] = top[rt], dfs2(s, rt, g);
        for(auto t : g[rt]) if(t != fa && t != s) dfs2(t, rt, g);
    }
    void Query(int a, int b, int z, int n){
        int fa = top[a], fb = top[b];
        while(fa != fb){
            if(dep[fa] < dep[fb]) swap(a, b), swap(fa, fb);
            // Cal id[fa] .. id[a]
            seg.updata(1, n, id[fa], id[a] , z, 1);
            a = par[fa]; fa = top[a];
        }
        if(dep[a] < dep[b]) swap(a, b);
        seg.updata(1, n, id[b], id[a], z, 1);
        // Cal id[b] .. id[a]
        // b is lca
    }
    ll Query1(int a, int b, int z, int n){
        int fa = top[a], fb = top[b];
        while(fa != fb){
            if(dep[fa] < dep[fb]) swap(a, b), swap(fa, fb);
            // Cal id[fa] .. id[a]
            res += seg.qry(1, n, id[fa], id[a], 1).sum;
            a = par[fa]; fa = top[a];
        }
        if(dep[a] < dep[b]) swap(a, b);
        res += seg.qry(1, n, id[b], id[a], 1).sum;
        // Cal id[b] .. id[a]
        // b is lca
        return res;
    }
    void Build(vi g[]){
        dfs(1, 0, g);
        dfs_cnt = 0;
        dfs2(1, 0, g);
    }
}hc;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 2, n + 1){
        int x;
        cin >> x;
        x++;
        edge[i].pb(x);
        edge[x].pb(i);
    }
    hc.Build(edge);
    //seg.build(1, n, 1, hc.who);
    rep(i, 1, m + 1){
        cin >> a[i].l >> a[i].r >> a[i].z;
        a[i].pos = i;
        a[i].l ++;
        a[i].r ++;
        a[i].z ++;
        v1[a[i].l - 1].pb(mp(a[i].pos,a[i].z));
        v[a[i].r].pb(mp(a[i].pos, a[i].z));
    }
    rep(i, 1, n + 1){
        hc.Query(1, i, 1, n);
        for(auto j : v[i]){
            res = 0;
            a[j.fi].val += hc.Query1(1, j.se, 1, n);
        }
        for(auto j : v1[i]){
            res = 0;
            a[j.fi].val -= hc.Query1(1, j.se, 1, n);
        }
    }
    rep(i, 1, m + 1){
        cout << (a[i].val % 201314 + 201314) % 201314<< endl;
    }
    return 0;
}
/*
5 1
0
0
1
1
1 4 3
*/
