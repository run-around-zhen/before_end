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
int a[1010];
int n;
set<int>v;
int cal(){
	v.clear();
	rep(j, 1, n + 1){
		v.insert(a[j]);
	}
	//sort(all(v));
	int j = 0;
	for(auto k : v){
		if(k != j){
			return j;
		}
		j ++ ;
	}
	return n;
}
vector<pii>s;
bool cmp(pii a, pii b){
	return a.fi > b.fi;
}
bool vis[1010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		cin >> n;
		rep(i, 1, n + 1) cin >> a[i];
		s.clear();
		cout << 2* n << endl;
		rep(i, 1, n + 1) {
			//a[i] = cal();
			//cout << i << " ";
			s.pb(mp(a[i], i));
		}
		sort(all(s), cmp);
		rep(i, 0, n){
			cout << s[i].se<< "!";
			a[s[i].se] = cal();
		}
		cout << endl;
		rep(i, 1, n + 1){
			cout << a[i] << " ";
		}
		cout << endl;
		rep(i, 1, n + 1){
			int mex =cal();
			if(a[i] < mex) continue;
			else a[i] = mex;
			rep(j, 1, n + 1){
				cout << a[j] << " ";
			}
			cout << endl;
		}
		
		//sort(all(s));
		/*int flag = 0;
		per(i, 1, n + 1){
			int mex = cal();
			if(mex == n) break;
			a[mex + 1] = mex;
			vis[mex + 1] = true;
			rep(j, 1, n + 1){
				cout << a[j] << " ";
			}
			cout << endl;
		//	cout << s[i].se << " ";
		}
		per(i, 1, n + 1){
			if(vis[i]) continue;
			a[i] = cal();
		}
		cout << endl;
		rep(i, 1, n + 1){
			cout << a[i] <<" ";
		}
		cout << endl;*/
	}
	return 0;
}