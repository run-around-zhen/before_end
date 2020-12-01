#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(ll i=(a); i<(b); i++)
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
vi prime;
bool vis[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	for(int i = 2; i <= 1000000; i ++){
		if(vis[i]) continue;
		for(int j = 1; j * i <= 1000000; j ++){
			vis[i * j] = true;
		}
		prime.pb(i);
	}
	int T;
	cin >> T;
	while(T --){
		ll n;
		cin >> n;
		int maxn = 0;
		ll id = 0;
		ll m = n;
		for(auto i : prime){
			if(i * i > n) break;
			if(n % i == 0){
				int cnt = 0;
				while(n % i == 0){
					n /= i;
					cnt ++;
				}
				if(cnt > maxn){
					maxn = cnt ;
					id = i;
				}
			}
		}
		cout << max(1, maxn) << endl;
		rep(i, 0, maxn - 1) cout << id << " ";
		rep(i, 0, maxn - 1) m /= id;
		cout << m << endl;
	}
	return 0;
}