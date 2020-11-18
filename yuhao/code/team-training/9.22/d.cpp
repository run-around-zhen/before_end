#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rept(i,x,y) for(int i=x;i<=y;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define dd(x) cout<<#x<<"="<<x<<" "
#define de(x) cout<<#x<<"="<<x<<"\n"
#define pb push_back
typedef pair<int,int> pii;
const int N = 300000 + 5;
struct Node { int val, sum, fa, son[2]; bool rev; };
int ans[N], edge[N][2];
struct LCT {
    static const int N = ::N;
    Node nd[N]; int sta[N];
    // if(no root) return 1
    void init(){
		memset(nd, 0, sizeof(nd));
		memset(sta,0, sizeof(sta));
	}
    bool nrt(int x) {
        int fa = nd[x].fa;
        return nd[fa].son[0] == x || nd[fa].son[1] == x;
    }
    void up(int x) {
        if(!x) return ;
        int ls = nd[x].son[0], rs = nd[x].son[1];
        nd[x].sum = nd[ls].sum + nd[rs].sum + nd[x].val;
    }
    void gao(int x) {
        if(!x) return ;
        nd[x].rev ^= 1, swap(nd[x].son[0], nd[x].son[1]);
    }
    void down(int x) { if(nd[x].rev) gao(nd[x].son[0]), gao(nd[x].son[1]), nd[x].rev = 0; }
    int id(int u) { return nd[nd[u].fa].son[1] == u; }
    void rot(int x) {
        int y = nd[x].fa, z = nd[y].fa;
        int l = id(x), r = (l ^ 1), s = nd[x].son[r];
        if(nrt(y)) nd[z].son[id(y)] = x; nd[x].son[r] = y; nd[y].son[l] = s;
        if(s) nd[s].fa = y; nd[y].fa = x; nd[x].fa = z;
        up(y), up(x);
    }
    void splay(int x) {
        int top = 0;
        for(int i = x; ; i = nd[i].fa) {
            sta[++top] = i;
            if(!nrt(i)) break;
        }
        while(top) down(sta[top--]);
        while(nrt(x)) {
            int y = nd[x].fa;
            if(nrt(y)) (id(x) ^ id(y)) ? rot(x) : rot(y);
            rot(x);
        }
    }
    void access(int x) { for(int y = 0; x ; y = x, x = nd[x].fa) splay(x), nd[x].son[1] = y, up(x); }
    // 鎹㈡牴
    void makeroot(int x) { access(x); splay(x); gao(x); }
    // 鎵炬牴
    int findroot(int x) {
        access(x); splay(x);
        while(nd[x].son[0]) down(x), x = nd[x].son[0];
        splay(x);
        return x;
    }
    // 鍔犺竟
    bool link(int x, int y) {
        makeroot(x);
        if(findroot(y) != x) {
			nd[x].fa = y;
			return false;
		}
		else{
			return true;
		}
    }
    // 鍒犺竟
    void cut(int x, int y) {
        makeroot(x);
        if(findroot(y) == x && nd[y].fa == x && !nd[y].son[0]) nd[y].fa = nd[x].son[1] = 0, up(x);
    }
    // nd[y]: 璺緞淇℃伅
    void path(int x, int y) { makeroot(x); access(y); splay(y); }
    // 鍗曠偣淇敼
    void upd(int x, int c) { splay(x); nd[x].val = c; up(x); }
}T;
int main(){
	int _;
	scanf("%d", &_);
	while(_ --){
	//	memset(T.nd, 0, sizeof(T.nd));
	//	memsetT(T.sta, 0, sizeof(T.sta));
	T.init();
		memset(ans, 0, sizeof(ans));
		memset(edge, 0, sizeof(edge));
		int n, m, q;
		scanf("%d %d %d", &n, &m, &q);
		rep(i, 1, m + 1) scanf("%d %d", &edge[i][0], &edge[i][1]);
		int i = 1, t = 1;
		while(t <= m){
		//	T.path(edge[i][0], edge[i][1]);
			if(i <= m && !T.link(edge[i][0], edge[i][1])){
				i ++;
			}
			else{
				ans[t] = i;
				T.cut(edge[t][0], edge[t][1]);
				t ++;
			}
		}
		int last = 0;
		while(q --){
			int u, v;
			scanf("%d %d", &u, &v);
			u = (u ^ last) % m + 1;
			v = (v ^ last) % m + 1;
			if(u > v) swap(u, v);
			if(v >= ans[u]) {
				printf("Yes\n");
				last = 1;
			}
			else{
				printf("No\n");
				last = 0;
			}
		}

	}
}
