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
const int inf = 1e9;
template<class T>
struct Dinic{
    const static int N = 4100 , M = 2000000;
    int s , t , n , h[N] , cur[N] , lv[N] , e , q[N]  , ne[M] , to[M] , f[M];
    T cap[M] , flow;
    void liu(int u,int v,T w){ to[e] = v;f[e] = u ;ne[e] = h[u];cap[e] = w;h[u] = e++;}
    void link(int u,int v,T w){ liu(u , v , w);liu(v , u , 0);}
    void ini(int _n = N) { fill(h , h + (n=_n) , -1);e = 0;}
    bool bfs(){
        int L = 0 , R = 0;
        fill(lv , lv + n , -1);
        lv[q[R++] = s] = 0;
        while(L < R && !~lv[t]){
            int c = q[L++];
            for(int k = h[c]; ~k ; k = ne[k])
                if(cap[k] > 0 && !~lv[to[k]]) 
                    lv[q[R++] = to[k]] = lv[c] + 1;
        }
        return ~lv[t];
    }
    T dfs(int c,T mx){
        if(c == t) return mx;
        T ret = 0;
        for(int &k = cur[c]; ~k; k = ne[k]){
            if(lv[to[k]] == lv[c] + 1 && cap[k] > 0){
                T flow = dfs(to[k] , min(mx , cap[k]));
                ret += flow;cap[k] -= flow , cap[k^1] += flow;mx -= flow;
                if(!mx) return ret;
            }
        }
        lv[c] = -1;
        return ret;
    }
    T run(int _s,int _t){
      //  rep(i, 0, n + 1) q[i] = 0;
       // rep(i, 0, n + 1) cur[i] = 0;
       /* rep(i,0,e) {
            cap[i] = 1;
            cap[i^1] = 0;
            i ++ ;
        }*/
        s = _s , t = _t;
      //  flow = 0;
        while(bfs()){
            copy(h , h + n , cur);
            flow += dfs(s, ~0U>>1);
        }
        return flow;
    }
};
Dinic<int>G;
bool vis[4000+10];
int go[4000+10];
int f[4000+10];
int find(int rt){
    if(f[rt] == rt) return f[rt];
    return f[rt] = find(f[rt]);
}
void dfs(int rt){
    vis[rt] = true;
    cout << rt << " ";
    if(!vis[go[rt]]&&go[rt]) dfs(go[rt]);
}
int main(){
    //ios::sync_with_stdio(false);
   // cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    rep(i , 1, 4000) f[i] = i;
    G.ini(4010);
    int s = 4005;
    int t = s -1;
    int ans = 1;
    G.link(s, 1, 1);
    G.link(1 + 2000, t, 1);
    //G.run(s, t);
    while(ans - G.run(s, t)<= n){
        ans ++ ;
        G.link(s, ans, 1);
        G.link(ans + 2000, t, 1);
        rep(i, 1, ans){
            int tmp = i + ans;
            int sqr = sqrt(tmp);
            if(sqr * sqr == tmp) {
                G.link(i, ans + 2000 ,1);
            }
        }
        rep(i, 1, ans + 1) f[i] = i;
        rep(i, 0 , G.e){
            if(G.to[i] != s && G.to[i^1] != t && G.to[i] != t && G.to[i^1] != s){
                if(G.cap[i] == 0){
                     go[G.to[i^1]] = G.to[i] - 2000;
                     f[G.to[i] - 2000] =find(G.to[i^1]);
                  }
              }
            i++;
        }
    }
    //cout << G.e << endl;
    cout << ans - 1 << endl;
    rep(i, 1, ans){
        if(f[i] == i){
            dfs(i);
            cout << endl;
        }
    }
  //  cout << ans - 1 << endl;
}