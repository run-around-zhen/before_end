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
int match[300+10], match1[300+10];
template<class T>
struct Dinic{
    const static int N = 210 , M = N * N * 2;
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
int ans = 0;
vi sum;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int m, n;
    cin >> m >> n;
    int x, y;
    G.ini(n + m + 10);
    int s = n + m + 5;
    int t = s - 1;
    rep(i, 1, m + 1){
        G.link(s, i, 1);
    }
    rep(i, 1, n + 1){
        G.link(i + m, t, 1);
    }
    while(cin >> x >> y){
        if(x == -1 && y == -1) break;
        G.link(x, y + m, 1);
    }
    cout << G.run(s, t) << endl;
    rep(i, 0, G.e ){
        if((G.to[i] != s && G.to[i^1] != t) && (G.to[i] != t && G.to[i^1] != s)){
           // cout << G.to[i] << " " << G.to[i^1] - m << endl;
            if(G.cap[i] == 0 )cout << G.to[i^1]  << " " << G.to[i] - m <<endl; 
         }
        i++;
    }
}