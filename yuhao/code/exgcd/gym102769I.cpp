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
ll exgcd(ll a, ll b, ll &x, ll &y){
	if (!b) { 
		x=1;
		y=0; 
		return a; 
	}
	ll g = exgcd(b, a % b, y, x);
	return y -= a / b * x, g;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	rep(cas, 1, T + 1){
		ll resx  = 0, resy = 0, dx = 0;
		int q;
		cin >> q;
		ll ans = 0;
		while(q --){
			int type;
			cin >> type;
			if(type == 1){
				ll x, y;
				ll a = 0, b = 0;
				cin >> x >> y;
				ll g = exgcd(y, resy, a, b);
				dx = __gcd(dx, abs(y * resx - x * resy) / g);
				resy = g;
				resx = a * x + b * resx;
				if(dx){
					resx = (resx % dx + dx) % dx;
				}
			}
			else{
				ll x, y, w;
				cin >> x >> y >> w;
				if(!resy){
					if((resx && x % resx == 0) || (!resx && !x)) {
						ans += w;
					}
				}
				else if(y % resy == 0){
					x = x - y / resy * resx;
					if((dx && x % dx == 0) || (!x && !dx)){
						ans += w;
					} 
				}
			}
		}
		cout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;
}