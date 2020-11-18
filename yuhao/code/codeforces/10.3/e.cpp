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
int n, m, c;
char maze[4040][4040];
int cost[4040];
const int inf = 0x3f3f3f3f;
template<class T>
struct Dinic{
    const static int N = 10100 , M = 1500000;
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
            ll tmp = dfs(s, ~0U >> 1);
            if(tmp >= 1e9) return -1;
            flow += tmp;
        }
        return flow;
    }
};
Dinic<ll>flow;
int id(int x, int y){
	return x * 31 + y;
}
int id1(int x, int y){
	return x * 31 + y + 1000;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	flow.ini(4010);
	//cin >> n >> m >> c;
	n = m = 30;
	c = 1;
	int s = 0, t = 4005;
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			//cin >> maze[i][j];
			if(i == 3 && j == 3){
				flow.link(id1(i, j), t, 1e9);
			}
			else{
				maze[i][j] = '.';
			}
		}
	}
	rep(i, 0, c) cost[i] = 1;
	rep(i, 1, n + 1){
		flow.link(s, id(i, 1), 1e9);
		flow.link(s, id(i, m), 1e9);
	}
	rep(i, 1, m + 1){
		flow.link(s, id(1, i), 1e9);
		flow.link(s, id(n, i), 1e9);
	}
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			if(maze[i][j] >= 'a' && maze[i][j] <= 'z'){
				flow.link(id(i, j), id1(i, j), cost[(int)(maze[i][j] - 'a')]);
			}
			else{
				flow.link(id(i, j), id1(i, j), 1e9);
			}
		}
	}
	rep(i, 1, n + 1){
		rep(j, 1, m + 1){
			if(i != n){
				flow.link(id1(i, j), id(i + 1, j), 1e9);
				flow.link(id1(i + 1, j), id(i, j), 1e9);
			}
			if(j != m){
				flow.link(id1(i, j), id(i, j + 1), 1e9);
				flow.link(id1(i, j + 1), id(i, j), 1e9);
			}
		}
	}
	ll ans =  flow.run(s, t);
	if(ans < 1e9) cout << ans << endl;
	else{
		cout <<"-1" << endl;
	}
	return 0;
}