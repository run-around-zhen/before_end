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
    const static int N = 10101 , M = N * 50;
    int s , t , n , h[N] , cur[N] , lv[N] , q[N] , e , ne[M] , to[M];
    T cap[M] , flow;
    void liu(int u,int v,T w){ to[e] = v;ne[e] = h[u];cap[e] = w;h[u] = e++;}
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
        s = _s , t = _t;
        flow = 0;
        while(bfs()){
            copy(h , h + n , cur);
            flow += dfs(s, ~0U>>1);
        }
        return flow;
    }
};
Dinic<int>G;
struct node{
    int i, j, k;
};
int n, m, d;
int ans;
char maze[25][25];
int dis(int x, int y, int x1, int y1){
    return abs(x - x1) + abs(y - y1);
}
int id(int i, int j, int k){
    return (i - 1) * m + j + n * m * k;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> d;
    G.ini(n * m * 2 + 10);
    int s = 2 * n * m + 4;
    int t = 2 * n * m + 5;
    rep(i, 1, n + 1){
        rep(j, 1, m + 1){
            cin >> maze[i][j];
        }
    }
    rep(i, 1, n + 1){
        rep(j ,1 ,m + 1){
            if(maze[i][j] > '0'){
                G.link(id(i, j, 0), id(i, j, 1), maze[i][j] - '0');
            }
            rep(k, 1, n + 1){
                rep(w, 1, m + 1){
                    if(k == i && w == j ) continue;
                    if(maze[k][w] > '0' && dis(i, j, k, w) <= d){
                        G.link(id(i, j, 1), id(k, w, 0), inf);
                    }
                }
            }
            if(maze[i][j] > '0' && (i <= d || j <= d || n - i + 1 <= d || m - j + 1 <= d)){
                G.link(id(i, j ,1), t, inf); 
            }
        }
    }
    rep(i, 1, n + 1){
        rep(j, 1, m + 1){
            char op;
            cin >> op ;
            if(op == 'L'){
                G.link(s, id(i, j ,0), 1);
                ans ++ ;
            }
        }
    }
  //  cout << ans << endl;
    cout << ans - G.run(s,t) << endl;
    return 0;
}
