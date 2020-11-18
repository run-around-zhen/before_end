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
vi v;
map<vector<int>, int>ma;
int a[100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	int start = clock();
	ll n, k, S, T;
	cin >> n >> k >> S >> T;
	rep(i, 1, n + 1) cin >> a[i];
	int ans = 0;
	while(1){
		if(1.0 * (clock() - start)/CLOCKS_PER_SEC > 2.80) break;
		int t = rand() % k + 1;
		random_shuffle(a + 1, a + 1 + n);
		v.clear();
		ll t1, t2;
		rep(j, 1, t + 1) {
			v.pb(a[j]);
			if(j == 1){
				t1 = a[j];
				t2 = a[j];
				continue;
			}
			t1 = (a[j] | t1);
			t2 = (a[j] & t2);
		}
		if(t1 == T && t2 == S){
			sort(all(v));
			if(ma[v] == 0) {
				ma[v] = 1;
				ans ++;
				/*cout << t1 << " " << t2 <<endl;
				for(auto i:v){
					cout << i << " ";
 				}
 				cout << endl;*/
			}
		}
	}
	cout << ans << endl;
	return 0;
}
