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
typedef pair<ll, ll> pii;
typedef vector<int> vi;
//map<pair<pair<int, int> ,pair<int, int> >,int >v;
map<pair<pair<ll,ll>,ll>,set<ll> > v;
map<pii, ll> res;
struct node{
	ll x, y;
}p[110];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	rep(cas, 1, T + 1){
		int n;
		cin >> n;
		res.clear();
		v.clear();
		rep(i, 1, n + 1){
			cin >> p[i].x >> p[i].y;
		}
		rep(i, 1, n + 1){
			rep(j, i + 1, n + 1){
				//if(p[i].x == p[j].x || p[i].y == p[j].y) continue; 
				ll x = p[j].x - p[i].x;
				ll y = p[j].y - p[i].y;
				ll gcd = __gcd(abs(x), abs(y));
				x /= gcd;
				y /= gcd;
				if(x < 0){
					x = -x;
					y = -y;
				}
				if(x == 0) y = abs(y);
				ll b = p[i]. y * x - p[i].x * y;
				pii kk = mp(x, y);
				v[mp(kk, b)].insert(i);
				v[mp(kk, b)].insert(j);
			}
		}
		ll ans = 0;
		for(auto i:v){
			res[i.fi.fi] += i.se.size() ;
			//res[i.fi.fi] -= i.se.size() % 2;
			//if(i.se.size() % 2 == 1) flag[i.fi.fi] = 1;
			ans = max(ans, res[i.fi.fi]);
		}
		//cout << ans << endl;
		cout << "Case #"<< cas <<": "<< ans + min(n - ans, 2ll) << endl;
	}
	return 0;
}