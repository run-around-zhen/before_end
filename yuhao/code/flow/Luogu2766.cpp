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
int inf = 1e9;
template<class T>
struct Dinic{
    const static int N = 10101 , M = N * 10;
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
        while(bfs()){
            copy(h , h + n , cur);
            flow += dfs(s, ~0U>>1);
        }
        return flow;
    }
};
Dinic<int> G;
int dp[500 + 10];
int a[500 + 10];
int n;
int id(int i, int  k){
	return i + k * n;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	int ans = 0;
	rep(i, 1, n + 1){
		dp[i] = 1;
		rep(j, 1, i) {
			if(a[i] >= a[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	G.ini(2 * n + 10);
	int s = 2 * n + 5;
	int t = s - 1;
	rep(i , 1, n + 1){
		if(dp[i] == 1) G.link(s, id(i, 0) , 1);
		
		rep(j, 1, i){
			if(dp[j] == dp[i] - 1 && a[j] <= a[i]){
				G.link(id(j, 1), id(i, 0), 1);
			}
		}
        G.link(id(i, 0), id(i, 1), 1);
		if(dp[i] == ans) G.link(id(i, 1), t, 1);
	}
	cout << ans << endl << G.run(s, t) << endl;
    G.cap[0] = inf;
    G.cap[2] = inf;
    G.cap[G.e - 4] = inf ;
    G.cap[G.e - 2] = inf ;
    if( n == 1) cout << "1" << endl;
    else cout << G.run(s, t) << endl;
	return 0;
}