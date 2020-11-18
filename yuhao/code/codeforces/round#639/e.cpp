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
vi edge[200000+10],v[200000+10],v1[200000+10];
int dp[200000+10][2];
int d[200000+10];
int f[200000+10];
bool vis[200000+10],vis1[200000+10];
queue<int>q;
struct node{
	int val,pos,flag;
};
vector<node>s[200000+10];
bool cmp(node a,node b){
	return a.val> b.val;
}
int find(int rt){
	if(f[rt]==rt) return rt;
	return f[rt]=find(f[rt]);
}
vector<pair<int,int> > fa[200000+10][2];
char ans[200000+10];
/*void dfs(int rt,int fi){
	vis[rt]=true;
	for(auto i:edge[rt]){
		if(i==fi) continue;
		if(!vis[i]) dfs(i,rt);
		if(dp[i][1]>dp[i][0]){
			dp[rt][0]+=dp[i][1];
			fa[rt][0].pb(mp(i,1));
		}
		else{
			dp[rt][0]+=dp[i][0];
			fa[rt][0].pb(mp(i,0));
		}
		dp[rt][1]+=dp[i][0];
		fa[rt][1].pb(mp(i,0));
	}
	dp[rt][1]+=1;
}
void dfs1(int rt,int fi,int flag){
	if(flag) res[rt]=1;
	for(auto i:fa[rt][flag]){
		if(i.fi==fi) continue;
		dfs1(i.fi,rt,i.se);
	}
}*/
void dfs(int i){
	vis[i]=true;
	for(auto rt:v[i]){
		if(!vis[rt]) dfs(rt);
	}
}
void dfs1(int i){
	vis1[i]=true;
	for(auto rt:v1[i]){
		if(!vis1[rt]) dfs1(rt);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	rep(i,1,n+1) f[i]=i;
	rep(i,0,m){
		int a,b;
		cin >> a >> b;
		edge[a].pb(b);
		edge[b].pb(a);
		v[a].pb(b);
		v1[b].pb(a);
		f[a]=find(f[b]);
		d[b]++;
	}
	rep(i,1,n+1){
		if(d[i]==0){
			q.push(i);
			//vis[i]=true;
		}
	}
	int res=0;
	while(!q.empty()){
		int rt=q.front();
		q.pop();
		for(auto i:v[rt]){
			d[i]--;
			if(d[i]==0){
				q.push(i);
			}
		}
	}
	rep(i,1,n+1){
		if(d[i]){
			cout<<"-1"<<endl;
			return 0;
		}
	}
	rep(i,1,n+1){
		if(vis[i]||vis1[i]) ans[i]='E';
		else{
			ans[i]='A';
			res++;
		}
		dfs(i);
		dfs1(i);
	}
	cout<<res<<endl;
	rep(i,1,n+1){
		cout<<ans[i];
	}
	/*rep(i,1,n+1){
		if(!vis[i]){
			dfs(i,0);
		//	cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<i<<endl;
			if(dp[i][1]>dp[i][0]){
				dfs1(i,0,1);
				ans+=dp[i][1];
			}
			else{
			//	dfs1(i,0,0);
				ans+=dp[i][0];
			}
		}
	}
	cout<<ans<<endl;
	rep(i,1,n+1){
		if(res[i]) cout<<"A";
		else cout<<"E";
	}
	/*rep(i,1,n+1){
		s[f[i]].pb({dp[i][0],i,0});
		s[f[i]].pb({dp[i][1],i,1});
	}
	rep(i,1,n+1){
		sort(all(s[i]),cmp);
	}
	rep(i,1,n+1){
		if(s[i].size()==0) continue;
		dfs1(s[i][0].pos)
	}*/

	
	return 0;
}