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
typedef vector<pii> vi;
int d[100000 + 10];
map<pii, int> ma, ma1;
vi ans;
vector<int> acc;
int main(){
	srand(time(0));
	int start = clock();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, m + 1){
		int u, v;
		cin >> u >> v;
		ma[mp(u, v)] = 1;
		ma[mp(v, u)] = 1;
	}
	int cnt = 0;
	int sum = 0;rep(i, 1, n + 1){
			if(d[i] < 2) acc.pb(i);
		}
	while(1){
		sum = 0;
	//	acc.clear();
		ans.clear();
		if((1.0 * clock() - 1.0 * start)/(1.0 *CLOCKS_PER_SEC) > 1.4){
					cout << "-1" << endl;
					return 0;
				}
		
		random_shuffle(all(acc));
		rep(i, 0, acc.size()){
			int u = acc[i], v = acc[(i + 1) % (int)acc.size()];
			if(ma.find(mp(u,v)) == ma.end()){
				ans.pb(mp(u, v));
				//d[u] ++;
				//d[v] ++;
				//ma1[mp(u, v)] = 1;
				//ma1[mp(v, u)] = 1;
				sum ++;
				//cout << u <<" " << v << " "<< sum << endl;
			}
			if(sum == m) break;

		}
		if(acc.size() == 1) break;
		if(sum == m) break;
	}
	//cout <<"!!" << sum << " "<< ans.size() <<endl;
	if(sum != m){
		cout <<"-1" << endl;
		return 0;
	}
	for(auto i:ans){
		cout << i.fi <<" " << i.se << endl;
	}
	return 0;
}	