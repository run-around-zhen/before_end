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
struct node{
	int ans, i, j;
};
vector<node>v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	for(int i = 2; i <= 200000; i ++){
		int flag = 0;
		for(int j = 2; j * j <= i; j ++){
			if(i % j == 0){
				flag = 1;
				break;
			}
		}
		if(!flag) prime.pb(i);
	}
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		rep(i, 0, prime.size()){
			vis[pirme[i]] = true;
			rep(j, i + 1, prime.size()){
				if(prime[i] * prime[j] > n) break;
				if(i == j) continue;
				ans.pb({prime[i] * prime[j], prime[i], prime[j]});
				vis[prime[i] * prime[j]] = true;
			}
		}
		rep(i, 0, prime.size()){
			rep(j, i + 1, prime.size()){
				if(prime[i] * prime[j] > n) break;
				int a = prime[i];
				rep(k, 0, 20){
					int b = prime[j];
					rep(q, 0, 20){
						if(k == )
					}
				}
			}
		}
		cout << ans.size() << endl;
		for(auto i : ans){
			cout << i.ans << " " << p[mp(i.i, i.j)][p[mp(i.i, i.j)]]
		}
	}
	return 0;
}