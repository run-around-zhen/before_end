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
int a[1000000 + 10];
vi edge[200000 + 10];
bool vis[200000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	int T;
	cin >> T;
	while(T --){
		int n, m;
		cin >> n >> m;
		rep(i, 1, n + 1) {
			a[i] = i;
			edge[i].clear();
		}
		rep(i, 1, m + 1){
			int u, v;
			cin >> u >> v;
			edge[u].pb(v);
			edge[v].pb(u);
		}
		
		int cnt = 0;
		while(1){
			cnt ++ ;
			memset(vis, false, sizeof(vis));
			int flag = 0;
			random_shuffle(a + 1, a + 1 + n);
			rep(i, 1, 4 * n / 7 + 1){
				vis[a[i]] = true;
			}
			rep(i, 1, n + 1){
				int flag1 = 0, flag2 = 0;
				for(auto j : edge[i]){
					if(j < i && !vis[j]) flag1 = 1;
					if(j > i && !vis[j]) flag2 = 1;
				}
				if(flag1 + flag2 == 2) {
					
					flag = 1;
					break;
				}
			}
			if(!flag){
				cout << 4 * n / 7 << endl;
				rep(i, 1, 4 * n / 7 + 1){
					cout << a[i] << " ";
				}
				cout << endl;
				break;
			}
		}
	}

	return 0;
}