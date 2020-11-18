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
int d[100000 + 10];
set<int> edge[100000 + 10];
map<pii, int>ma;
bool vis[1000000 + 10];
int f[100000 + 10];
vi v;
int find(int i){
	if(f[i] == i){
		return i;
	}
	return f[i] = find(f[i]);
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n + 1) f[i] = i;
	rep(i, 1, m + 1){
		int u, v;
		cin >> u >> v;
		edge[u].insert(v);
		edge[v].insert(u);
		f[find(v)] = find(u);
 	}
 	//cout <<"!!" << endl;
 	queue<int>q;
 	rep(i, 1, n + 1){
 		d[i] = edge[i].size();
 		if(d[i] == 2) {
 			q.push(i);
 			//cout << i << endl;
 			vis[i] = true;
 		}
 	}
 	while(!q.empty()){
 		int x = q.front();
 		cout <<x << endl;
 		q.pop();
 		v.clear();
 		for(auto i: edge[x]){
 			if(!vis[i]) v.pb(i);
 		}
 		//cout << v.size() << endl;
 		edge[v[0]].insert(v[1]);
 		edge[v[1]].insert(v[0]);
 		for(auto i: edge[x]){
 			edge[i].erase(x);
 			//d[i] --;
 			if(d[i] == 2){
 				vis[i] = true;
 				q.push(i);
 			}
 		}
 		
 	}
 	int cnt = 0;
 	int flag = find(1);
 	rep(i, 1, n + 1){
 		if(!vis[i]) cnt ++;
 		if(find(i) != flag){
 			cout << "No" << endl;
 			return 0;
 		}
 	}
 	if(cnt > 2){
 		cout << "No" << endl;
 	}
 	else{
 		cout << "Yes" << endl;
 	}
	return 0;
}