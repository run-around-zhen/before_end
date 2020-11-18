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
const int maxn = 600000 + 10;
ll dist[maxn],vis[maxn]; 
int use[maxn];
ll cost[maxn];
map<pair<int,int>,int> link;
ll sum[maxn];
struct node{    		
	int num;
	ll val;        
	node(int a,ll b)
	{
		num = a;
		val = b;
	}
	bool operator<(const node&n) const
	{
		return val > n.val;
	}
};
vector<node> g[maxn]; 
 
void dij(int begin,int n)
{
	priority_queue<node> q;
	memset(vis,0,sizeof(vis));
	for( int i = 1 ; i <= n ; i++ )
	{
		dist[i] = 1e18;           
	}
	dist[begin] = 0;    
	q.push(node(begin,0));   
	while( !q.empty() )    
	{
		int x = q.top().num;
		q.pop();
		if( vis[x] ) continue;          
		vis[x] = 1;
		for( int i = 0 ; i < g[x].size() ; i++ )
		{
			node t = g[x][i];
			if(!vis[t.num] && dist[t.num] > dist[x] + t.val )       
			{
				dist[t.num] = dist[x] + t.val;
				t.val = dist[t.num];
				//cout << x <<" " << t.num <<endl;
				use[t.num] = link[mp(x,t.num)];        
				cost[t.num] = t.val;
				q.push(node{t.num,dist[t.num]}); 
			}
			else if(!vis[t.num] && dist[t.num] == dist[x] + t.val){
				if(cost[t.num] > t.val){
					cost[t.num] = t.val;
					use[t.num] = link[mp(x,t.num)];
					q.push(node{t.num,dist[t.num]});
				}
			}
		}
	}
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,begin;
	cin >> n >> m ; 
	for( int i = 0 ; i < m ; i++ )   
	{
		int x,y,v;
		cin >> x >> y >> v;
		link[mp(x,y)] = i +1 ;
		link[mp(y,x)] = i + 1;
		//cost[i] = v;
		sum[i + 1] = v;
		g[x].push_back(node(y,1));    
		g[y].push_back(node(x,1));
	}
	cin >> begin;
	//cout << begin <<"!! " << endl;
	dij(begin,n);
	ll ans = 0;
	sort(use + 1, use + 1+ n);
	rep(i, 2, n + 1) ans += sum[use[i]];
	cout << ans << endl;
	rep(i, 2, n + 1) cout << use[i] << " ";
    return 0;
}