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
const int inf = 1e9 + 10;
template<class T>
struct Dinic{
    const static int N = 41000 , M = 2000000;
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
int dir[8][2]={2, 1, 1, 2, -1, -2 , -2, -1, -1, 2, -2, 1, 1, -2, 2, -1};
int n;
bool check(int x, int y){
    return x>=1 && y>=1 && x<= n && y<= n;
}
int id(int x, int y){
    return (x - 1) * n + y ;
}
int maze[210][210];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int m;
    cin >> n >> m;
    rep(i, 1, m + 1){
        int x, y;
        cin >> x >> y;
        maze[x][y] = 1;
    }
    G.ini( n * n + 10);
    int s =  n * n + 5;
    int t = s - 1;
    int tot = 0;
    rep(i, 1, n + 1){
        rep(j, 1, n + 1){
            if(maze[i][j] == 1 ) continue;
            tot += 1;
            if((i + j) % 2 == 0){
                G.link(s, id(i, j), 1);
                rep(k, 0, 8){
                    int xx = i + dir[k][0];
                    int yy = j + dir[k][1];
                    if(check(xx, yy) && !maze[xx][yy]){
                        G.link(id(i, j), id(xx, yy), inf);
                      //  cout << i << " " << j << " " << xx << " " << yy << " " << id(i,j) << endl;  
                    }
                }
            }
            else{
                G.link(id(i, j), t, 1);
            }
        }
    }
    cout << tot - G.run(s, t);
}