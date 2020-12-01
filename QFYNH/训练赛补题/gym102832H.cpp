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
const int MAXN = 400000 + 10;
const int INF = 0x3f3f3f3f;
vector<int> G[MAXN];
int uN;
int Mx[MAXN], My[MAXN];
int dx[MAXN], dy[MAXN];
int dis;
bool used[MAXN];
unordered_map<string, bool> vis;
unordered_map<string, int> id;
int n, m;
bool SearchP(){
	queue<int> Q;
	dis = INF;
	memset(dx, -1, sizeof(dx));
	memset(dy, -1, sizeof(dy));
	for(int i = 0; i < uN; i ++){
		if(Mx[i] == -1){
			Q.push(i);
			dx[i] = 0;
		}
	}
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		if(dx[u] > dis) break;
		int sz = G[u].size();
		for(int i = 0; i < sz; i ++){
			int v = G[u][i];
			if(dy[v] == -1){
				dy[v] = dx[u] + 1;
				if(My[v] == -1) dis = dy[v];
				else{
					dx[My[v]] = dy[v] + 1;
					Q.push(My[v]);
				}
			}
		}
	}
	return dis != INF;
}
bool DFS(int u){
	int sz = G[u].size();
	for(int i = 0; i < sz; i ++){
		int v = G[u][i];
		if(!used[v] && dy[v] == dx[u] + 1){
			used[v] = true;
			if(My[v] != -1 && dy[v] == dis) continue;
			if(My[v] == -1 || DFS(My[v])){
				My[v] = u;
				Mx[u] = v;
				return true;
			}
		}
	}
	return false;
}
int MaxMatch(){
	int res = 0;
	memset(Mx, -1, sizeof(Mx));
	memset(My, -1, sizeof(My));
	memset(used,false, sizeof(used));
	while(SearchP()){
		memset(used, false, sizeof(used));
		for(int i = 0; i < uN; i ++){
			if(Mx[i] == -1 && DFS(i)){
				res ++;
			}
		}
	}
	return res;
}
void build(int m, int maxn){
	de(maxn);
	rep(i, 0, 2 * maxn + 10) G[i].clear();
	string s ="";
	rep(i, 0, m) s += '0';
	rep(i, 0, maxn){
		//de(s);
		rep(j, 0, m){
			string t = s;
			if(t[j] == '9') {
				t[j] = '0';
			}
			else{
				t[j] ++;
			}
			if(!vis[t] && !vis[s]) G[id[s]].pb(id[t]);
			t = s;
			if(t[j] == '0'){
				t[j] = '9';
			}
			else{
				t[j] --;
			}
			if(!vis[t] && !vis[s]) G[id[s]].pb(id[t]);
		}
		int pos = m - 1;
		s[pos] ++;
		if(s[pos] > '9'){
			while(pos >= 0&& s[pos] > '9'){
				s[pos] = '0';
				pos -- ;
				s[pos] ++; 
			}
		}
		//de(s);
		
	}
}
map<int,string > dddd;
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		vis.clear();
		id.clear();
		uN = 0;
		cin >> n >> m;
		string t;
		cin >> t;
		rep(i, 0, m){
			string s;
			cin >> s;
			vis[s] = true;
		}
		string s ="";
		rep(i, 0, n) s += '0';
		int maxn = 1;
		rep(i, 0, n) maxn *= 10;
		//de(maxn);
		int cnt2 = maxn;
		int flag = 0;
		rep(i, 0, maxn){
			if((i + flag) % 2 == 0) {
				id[s] = uN ++;
				dddd[uN - 1] = s;
			}
			else {
				id[s] = cnt2 ++;
				dddd[cnt2 - 1] = s;
			}
			//	dd(s);de(id[s]);

			int pos = n - 1;
			s[pos] ++;
			if(s[pos] > '9'){
				while(pos >= 0&& s[pos] > '9'){
					s[pos] = '0';
					pos -- ;
					s[pos] ++; 
					flag ++;
				}
			}
		}
		// de(maxn);
		// de(cnt2);
		build(n, maxn);
		//de(uN);
		int res1 = MaxMatch();
		//de(res1);
		vis[t] = true;
		build(n, maxn);
		int res2 = MaxMatch();
		//dd(res1);de(res2);
		if(res1 == res2){
			cout << "Bob" << endl;
		}
		else{
			cout << "Alice" << endl;
		}

	}
	return 0;
}
/*
1
3 2 006
003
008
*/