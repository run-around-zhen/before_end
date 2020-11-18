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
struct node{
	int val, pos;
}a[200000 + 10];
int x[200000 + 10], b[2000000 + 10];
int sum[200000 + 10];
map<int, int >f, ma;
bool cmp(node a, node b){
	if(a.val < b.val) return true;
	if(a.val == b.val) return a.pos < b.pos;
	return false;
}
set<int>ss[200000 + 10];
int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T --){
    	f.clear();
    	ma.clear();
    	int n;
    	cin >> n;
    	rep(i, 1, n + 1){
    		sum[i] = 0;
    		cin >> a[i].val;
    		a[i].pos = i;
    		x[i] = a[i].val;
    		ma[a[i].val] ++;
    		b[i] = a[i].val;
    	}
    	int ans = 0;
    	sort(a + 1, a + 1 + n, cmp);
    	sort(x + 1, x + 1 + n);
    	int num = unique(x + 1, x + 1 + n) - (x + 1);
    	rep(i, 1, num + 1) {
    		f[x[i]] = i;
    		sum[i] = ma[x[i]] + sum[i - 1];
    	}
    	rep(i, 1, n + 1){
    		ss[f[b[i]]].insert(i);
    	}
    	int l = 1, r = 1;
    	stack<int>s;
    	while(1){
    		auto i = ss[f[a[r].val]].rbegin();
    		auto j = ss[f[a[r].val]].rend();
    		int t = 0;
    		while(1){
    			if(s.size() == 0) break;
    			if( i == j || (*i) < s.top()) break;
    			i ++;
    			t ++ ;
    			ans = max(ans, (int)s.size() + t); 
    		}
    		int maxn = 1e9;
    		while(!s.empty() && s.top() > a[r]. pos){
    			maxn = 	(maxn, b[s.top()]);
    			s.pop();
    		}
    		//cout << s.size() << " " << maxn << endl;
    		if(s.size() != 0 && maxn != 1e9){
    			while(s.size()) s.pop();
    			if(maxn == a[r - 1].val){
    				for(auto i: ss[f[a[r - 1].val]]) {
    					if(i < a[r].pos) s.push(i);
    					else break;
    				}
    			}
    		}
    		s.push(a[r].pos);
    		while(r + 1<= n && a[r + 1].pos > a[r].pos) {
    			s.push(a[r + 1]. pos);
    			r ++;
    		}
    		ans = max(ans, (int)s.size());
    		//cout << ans << endl;
    		r ++;
    		if(r >= n + 1) break;

    	}
    	rep(i, 1, num + 1) ss[i].clear();
    	cout << n -ans << endl;
    	
    }

}