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
ll a[1000000 + 10];
vi prime,v[200000 + 10];
set<ll>s;
bool p[200000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for(int i = 2; i <= 200000; i++){
		int flag = 0;
		for(int j = 2;j * j <= i; j++){
			if(i % j == 0) {
				flag = 1;
				break;
			}
		}
		if(!flag) {
			prime.pb(i);
			p[i] = true;
		}
	}
	rep(i, 1, n + 1) cin >> a[i];
	if(n <= 10){
		rep(i, 1, n + 1){
			rep(j, 1, i){
				s.insert(a[i]*a[j]/(__gcd(a[i],a[j])));
			}
		}
		ll ans = 0;
		for(auto i:s){
			ans = __gcd(ans,i);
		}
		cout << ans <<endl;
		return 0;
	}	
	ll ans = 1;
	rep(i, 1, n + 1){
		for(auto j:prime){
			if(j * j > a[i]) break;
			if(a[i] % j == 0){
			//	cout << a[i] <<" " << j ;
				int t = 0;
				while(a[i] % j == 0){
					a[i] /= j;
					t++;
				}
				v[j].pb(t);
			//	cout<<t << endl;
			}
		}
		if(a[i] != 1 && p[a[i]]) v[a[i]].pb(1);
	}
	//cout << v[2].size() <<" " <<v[3].size() <<endl;
	rep(i, 2, 200001){
		sort(all(v[i]));
		if(v[i].size() == n ){
			rep(j, 0, v[i][1]) ans *= i;
		}
		else if(v[i].size() == n - 1){
			rep(j, 0, v[i][0]) ans *= i;
		}
	}
	cout << ans << endl;
	return 0;
}