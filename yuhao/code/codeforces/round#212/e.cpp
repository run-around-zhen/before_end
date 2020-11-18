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
#define inf 0x3f3f3f3f
// sjctxdy
int n, K;
template<class U,class V>
struct MCMF{
    static const int N = 1000, M = 30000;
    int h[N], ing[N], pre[N], to[M], ne[M], e, s, t, n;
    U cap[M]; V dis[N], cost[M];
    void ini(int _n = N){ fill(h , h + (n=_n) , -1);e = 0;}
    void liu(int u,int v,U c,V w){ to[e] = v;ne[e] = h[u];cap[e] = c;cost[e] = w;h[u] = e++;}
    void link(int u,int v,U c,V w){ liu(u,v,c,w);liu(v,u,0,-w); }
    bool spfa(){
        queue<int> Q;
        fill(dis, dis+n, inf);
        Q.push(s), ing[s] = 1, dis[s] = 0;
        while(!Q.empty()){
            int c = Q.front(); Q.pop(); ing[c] = 0;
            for(int k = h[c]; ~k; k = ne[k]) if (cap[k] > 0) {
                int v = to[k];
                if(dis[c] + cost[k] < dis[v]){
                    dis[v] = dis[c] + cost[k];
                    pre[v] = k;
                    if(!ing[v]) Q.push(v) , ing[v] = 1;
                }
            }
        }
        return dis[t] != inf;
    }
    U flow; V mincost;
    pair<U, V> run(int _s,int _t){
        s = _s , t = _t;
        flow = mincost = 0;
        while(spfa()){
            U pl = inf; int p, k;
            for(p = t;p != s;p = to[k^1]) pl = min(pl, cap[k = pre[p]]);
            for(p = t;p != s;p = to[k^1]) cap[k = pre[p]] -= pl, cap[k^1] += pl;
            if(K == 0){
           	 	flow += pl;
            	continue;
        	}
           // cout << mincost << " " << flow << " " << k<< endl;
            if(mincost + pl * dis[t] > K){ 
          	    flow += (K - mincost) / dis[t];
           		break;
       		}
			mincost += pl * dis[t];
            flow += pl;
            if(mincost == K) break;
        }
        return mp(flow, mincost);
    }
};
MCMF<int, int>G;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> K;
	G.ini(n + 10);
	int s = 1, t = n;
	//cout << k << endl;
	rep(i ,1, n + 1){
		rep(j, 1, n + 1){
			int x;
			cin >> x;
			if(x > 0){
				G.link(i, j, x, 0);
               // if(K != 0) {
                	G.link(i, j, K, 1);
                	//cout << "!!" << endl;
              //  }
			}	
		}
	}
	pii ans = G.run(s, t);
	cout << ans.fi << endl;
	return 0;
}