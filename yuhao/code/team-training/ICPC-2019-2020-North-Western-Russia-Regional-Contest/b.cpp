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
vi vv;
vector<pair<double, int> >  v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	/*rep(i, 0, 50000 + 1){
		vv.clear();
		int flag = 0;
		sort(all(v));
		rep(j, -25000, 25000 + 1){
			vv.pb(i * j);
		}
		rep(i, 1, n){
			if(sin(vv[i]) <= sin(vv[i - 1])){
				flag = 1;
				break;
			}
		}
		if(!flag){
			cout << i << endl;
			break;
		}
		cout << "fuck" << i << endl;
	}*/
	int ans = 710;
	rep(j, -25000, 25000 + 1){
			vv.pb(ans * j);
	}
	rep(i, 0, n) cout << vv[i] << endl;
	return 0;
}