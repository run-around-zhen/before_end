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
vi v;
int a[10],b[10];
bool cmp(pii a, pii b){
	return a.fi * a.fi + a.se * a.se > b.fi * b.fi + b.se * b.se;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	int n, r;
	cin >> n >> r;
	rep(i, -r, r + 1){
		rep(j, -r, r + 1){
			if(i * i + j * j <= r * r){
				v.pb(mp(i, j));
			}
		}
	}
	sort(all(v), cmp);
	/*for(auto i : v){
		cout << i.fi << " " << i.se << endl;
	}
	cout << v.size() << endl;*/
	int cnt = 0;
	int len = min((int)v.size(), 30);
	int res = 0;
	while(cnt <= 5e5){
		rep(i, 0, n) a[i] = rand() % len;
		int ans = 0;
		rep(i, 0, n){
			rep(j, i + 1, n){
				ans += (v[a[i]].fi - v[a[j]].fi) * (v[a[i]].fi - v[a[j]].fi) + (v[a[i]].se - v[a[j]].se) * (v[a[i]].se - v[a[j]].se);
			}
		}
		if(ans > res){
			res = ans ;
			rep(i, 0, n) b[i] = a[i];
		}
		cnt ++ ;	
	}
	cout << res << endl;
	rep(i, 0, n){
		cout << v[b[i]].fi << " " << v[b[i]].se << endl;
	}
	return 0;
}