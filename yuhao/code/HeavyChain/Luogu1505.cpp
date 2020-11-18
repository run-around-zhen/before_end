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
int N;
int val[200000 + 10];
vi edge[200000 + 10];
vector<pii> g[200000 + 10];
int fa[200000 + 10];
pii link[200000 + 10];
template<class T>
struct node{
    T sum;
    T laze;
    T minn;
    T maxn;
};
template<class T>
struct segtree{
    static const int N = 8e5 + 10;
    node<int> nd[N];
    /*void pushdown(int l, int r, int rt){
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
    }*/
    void pushdown1(int l, int r, int rt){
        if(nd[rt].laze){
            nd[rt * 2].laze ^= 1;
            nd[rt * 2 + 1].laze ^= 1;
            nd[rt * 2].sum *= -1;
            nd[rt * 2 + 1].sum *= -1;
            swap(nd[rt * 2].minn,nd[rt * 2].maxn);
            swap(nd[rt * 2 + 1].minn,nd[rt * 2 + 1].maxn);
            nd[rt * 2].minn *= -1;
            nd[rt * 2 + 1].minn *= -1;
            nd[rt * 2].maxn *= -1;
            nd[rt * 2 + 1].maxn *= -1;
            nd[rt].laze = 0;
        }
    }
    void pushup(int l, int r, int rt){
        nd[rt].sum = nd[rt * 2].sum + nd[rt * 2 + 1].sum;
        nd[rt].minn = min(nd[rt * 2].minn, nd[rt * 2 + 1].minn);
        nd[rt].maxn = max(nd[rt * 2].maxn, nd[rt * 2 + 1].maxn);
    }
    void build(int l, int r, int rt, int a[]){
        if(l == r){
            nd[rt].sum = val[a[l]];
            nd[rt].maxn = val[a[l]];
            nd[rt].minn = val[a[l]];
            return ;
        }
        int mid = (l + r) / 2;
        build(l, mid, rt * 2, a);
        build(mid + 1, r, rt * 2 + 1,  a);
        pushup(l, r, rt);
    }
   /* void updata(int l, int r, int ql, int qr, T val, int rt){
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
    }*/
    void update(int l, int r, int ql, int qr, T val, int rt){
        if(l >= ql && r <= qr){
            nd[rt].laze ^= 1;
            nd[rt].sum *= -1;
            swap(nd[rt].minn,nd[rt].maxn);
            nd[rt].minn *= -1;
            nd[rt].maxn *= -1;
            return ;
        }
        pushdown1(l, r, rt);
        int mid= (l + r) / 2;
        if(ql <= mid) update(l, mid, ql, qr, val, rt * 2);
        if(qr > mid) update(mid + 1, r, ql, qr, val, rt * 2 + 1);
        pushup(l, r, rt);
        return ;
    }
    void update1(int l, int r, int pos, T value, int rt){
        if(l == r){
            nd[rt].sum = value;
            nd[rt].maxn = value;
            nd[rt].minn = value;
            return ;
        }
        pushdown1(l, r, rt);
        int mid= (l + r) / 2;
        if(pos <= mid) update1(l, mid, pos, value, rt * 2);
        else update1(mid + 1, r, pos, value, rt * 2 + 1);
        pushup(l, r, rt);
        return ;
    }
    node<int> qry(int l, int r, int ql, int qr, int rt){
        //cout << l << "  " << " " << r << " " << ql <<" " <<qr << " " << rt <<endl;
        if(l >= ql && r <= qr){
            return nd[rt];
        }
        pushdown1(l, r, rt);
        int mid = (l + r) / 2;
        node<int> ans, ans1, ans2;
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
segtree<int> seg;
struct HeavyChain{
    static const int N = 2e5 + 10;
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
            seg.update(1, n, id[fa], id[a] , z, 1);
            a = par[fa]; fa = top[a];
        }
        if(dep[a] < dep[b]) swap(a, b);
        if(b != a)seg.update(1, n, id[b] + 1, id[a], z, 1);
        // Cal id[b] .. id[a]
        // b is lca
    }
    node<int> Query1(int a, int b, int n){
        int fa = top[a], fb = top[b];
       // cout <<"!!!" <<" " <<fa <<" " << fb << endl;
        node<int>ans,ans1;
        ans.sum = 0;
        ans.minn = 1e9;
        ans.maxn = -1e9;
        while(fa != fb){
            if(dep[fa] < dep[fb]) swap(a, b), swap(fa, fb);
            // Cal id[fa] .. id[a]
         //   cout << "??" << fa <<" " << a <<" " << id[fa] <<" " << id[a] <<endl;
            ans1 = seg.qry(1, n, id[fa], id[a], 1) ;
            ans.sum = ans.sum + ans1.sum;
            ans.minn = min(ans.minn, ans1.minn);
            ans.maxn = max(ans.maxn, ans1.maxn);
            a = par[fa]; fa = top[a];
        }
        if(dep[a] < dep[b]) swap(a, b);
        //ans = (ans + T.qry(1, n, id[b], id[a], 1)) % mod;
      //  cout << "$$$"<<id[b] +1 <<" " << id[a] <<endl;
        if(b != a){
            ans1 = seg.qry(1, n, id[b] + 1, id[a], 1) ;
            ans.sum = ans.sum + ans1.sum;
            ans.minn = min(ans.minn, ans1.minn);
            ans.maxn = max(ans.maxn, ans1.maxn);
        }
        return ans;
        // Cal id[b] .. id[a]
        // b is lca
    }
    void Build(vi g[]){
        dfs(1, 0, g);
        dfs_cnt = 0;
        dfs2(1, 0, g);
    }
}hc;
void dfs(int rt, int fi){
    fa[rt] = fi;
    for(auto i :g[rt]){
        if(i.fi == fi) continue;
        dfs(i.fi, rt);
        val[i.fi] = i.se;
    }
    return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> N ;
    rep(i, 1, N){
        int u, v, w;
        cin >> u >> v >> w;
        u ++;
        v ++;
        edge[u].pb(v);
        edge[v].pb(u);
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
        link[i] = mp(u, v);
    }
    dfs(1, 0);
    hc.Build(edge);
    seg.build(1, N , 1, hc.who);
    int q;
    cin >> q;
    rep(i, 1, q + 1){
        string op;
        int u, v;
        cin >> op;
       // cout << op << endl;
      
        if(op == "C"){
            cin >> u >> v;
            if(fa[link[u].fi] == link[u].se){
               // cout << "??? " << hc.id[link[u].fi] <<endl;
                seg.update1(1, N, hc.id[link[u].fi], v, 1);
            }
            else{
               // cout << hc.id[link[u].se] << "?? "<<endl; 
                seg.update1(1, N, hc.id[link[u].se], v, 1);
            }
         //   cout << "???" << endl;
        }
        else if(op == "N"){
            cin >> u >> v;
            u ++;
            v ++;
            hc.Query(u , v, 0, N);
        }
        else{
            cin >> u >> v;
            u++;
            v++;
            //cout << u << " " << v << endl;
            //cout << endl;
            node<int>ans;
            ans = hc.Query1(u ,v, N);
            if(op == "SUM") cout << ans.sum << endl;
            else if(op == "MAX") cout << ans.maxn << endl;
            else cout << ans.minn << endl;
        }
    }
    return 0;
}
/*
3
0 1 1
1 2 2
1
SUM 0 2
MAX 0 2
N 0 1
SUM 0 2
MIN 0 2
C 1 3
SUM 0 2
MAX 0 2
*/
