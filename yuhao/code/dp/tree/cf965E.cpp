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
const int N = 1e5 + 10;
int n;
bool lef[N];
vi g[N];
struct Trie {
	static const int N = ::N;
	int son[N][26], id[N];
	int ne() { fill_n(son[n], 26, -1); return n++; }
	void ini() { n = 0; ne(); }
	void insert(const string &s) {
		int u = 0;
		for (auto ch : s) {
			int &v = son[u][ch - 'a'];
			if (!~v) { v = ne(); g[u].pb(v); }
			u = v;
		}
		lef[u] = true;
	}
	multiset<int> s[N];
	void dfs(int rt, int deep){
		for(auto i :g[rt]){
			dfs(i, deep + 1);
			for(auto j: s[i]){
				s[rt].insert(j);
			}
		}
		if(lef[rt]){
			s[rt].insert(deep);
		}
		else if(rt){
			auto i = s[rt].rbegin();
			s[rt].erase(s[rt].find(*i));
			s[rt].insert(deep);
		}
	}
	ll solve(){
		dfs(0, 0);
		ll ans = 0;
		for(auto i:s[0]) ans += i;
		return ans;
	}
}trie;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	trie.ini();
	rep(i, 1, n + 1){
		string s;
		cin >> s;
		trie.insert(s);
	}
	cout << trie.solve() << endl;
	return 0;
}