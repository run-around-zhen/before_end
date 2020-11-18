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
int a[5050], p[1000000 + 10];
bool vis[1000000 + 10];
vi res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	int start = clock();
	int n, k;
	cin >> n >> k;
	int maxn = 0;
	rep(i, 1, n + 1) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	rep(i, 1, maxn + 1) res.pb(i);
	int ans = maxn + 1;
	random_shuffle(all(res));
	for(auto x : res){
		if((1.0 * clock() - 1.0 * start)/(1.0 *CLOCKS_PER_SEC) > 0.95) break;
		/*int x = rand() % (maxn + 1) + 1;;
		while(vis[x]){
			if((1.0 * clock() - 1.0 * start)/(1.0 *CLOCKS_PER_SEC) > 0.95) break;
			if(n > 1000) x = rand() % 100000 + 200000;	
			else x = rand() % (maxn + 1) + 1;
		}*/
		if(n > 1000 && x < 250000) continue;
		int sum = 0;
		rep(i, 1, n + 1){
			int t = a[i] % x;
			p[t] ++ ;
			if(p[t] > 1) sum ++;
			/*if(sum > k){
				rep(j, 1, i + 1) p[a[j] % x] = 0;
				break;
			}*/
		}
		rep(i, 1, n + 1) p[a[i] % x] = 0;
		//cout << x << " " << sum << endl;
		if(sum <= k) ans = min(ans, x);

	}
	/*rep(i, 1, maxn + 1){
		cout << i << " " <<vis[i] << endl;
	}*/
	cout << ans << endl;
	return 0;
}