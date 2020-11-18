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
typedef pair<ll, ll> pii;
typedef vector<int> vi;
int dir[8][2] = {1, 1, 1, 0, 1, -1, 0, 1, 0, -1, -1, 1, -1, 0, -1, -1};
const int MAXN=5000;
pii a[MAXN][MAXN];
map<pair<ll, ll >, bool>ma;
map<pair<ll, ll >, ll> id, sum;
bool check(ll x, ll y){
	return __gcd(x, y) > 1;
}
const double eps=1e-9;
pii add(pii a, pii b){
	if(a.fi == 0 && b.fi == 0) return mp(0, 1);
	ll lcm=(ll)a.se*b.se/__gcd(abs(a.se),abs(b.se));
	pii ans;
	ans.se=lcm;
	ans.fi=lcm/a.se*a.fi+lcm/b.se*b.fi;
	ll gcd=__gcd(abs(ans.fi),abs(ans.se));
	ans.fi/=gcd;
	ans.se/=gcd;
	return ans;
}
pii sub(pii a, pii b){
	if(a.fi == 0 && b.fi == 0) return mp(0, 1);
	ll lcm=(ll)a.se*b.se/__gcd(abs(a.se),abs(b.se));
	pii ans;
	ans.se=lcm;
	ans.fi=lcm/a.se*a.fi-lcm/b.se*b.fi;
	ll gcd=__gcd(abs(ans.fi),abs(ans.se));
	ans.fi/=gcd;
	ans.se/=gcd;
	return ans;
}
pii mul(pii a,pii b)
{
	if(a.fi == 0 && b.fi == 0) return mp(0, 1);
	pii ans;
	ans.fi=a.fi*b.fi;
	ans.se=a.se*b.se;
	ll gcd=__gcd(abs(ans.fi),abs(ans.se));
	ans.fi/=gcd;
	ans.se/=gcd;
	return ans;
}
pii div(pii a,pii b)
{
	if(a.fi == 0 && b.fi == 0) return mp(0, 1);
	pii ans = mul(a,mp(b.se,b.fi));
	if(ans.fi < 0 && ans.se < 0) {
		ans.fi = - ans.fi;
		ans.se = - ans.se;
	}
	return ans;
}
pii ans[MAXN];
pii gau_s(pii a[][MAXN], int n, pii x[]){
	int i, j, k, p;
	for(j = 0; j < n; j ++){
		for(i = j + 1, p = j; i < n; i ++){
			if(sub(a[i][j], a[p][j]).fi < 0){
				p = i;
			}
		}
		if(p != j){ 
			for(k = j; k <= n; k ++){
				swap(a[j][k], a[p][k]);
			}
		}
		for(i = j + 1; i < n ; i ++){
			for(k = n; k >= j; k --){
			//	a[i][k] -= a[j][k] * a[i][j] / a[j][j];
				a[i][k] = sub(a[i][k], mul(a[j][k], div(a[i][j], a[j][j])));
			}
		}
		/*rep(i, 0, n){
   			rep(j, 0, n + 1){
   				cout << a[i][j].fi << "/" << a[i][j].se << " ";
   			}
   			cout << endl;
   		}
   		cout << endl;*/
	}
	for(j = n - 1; j >= 0; j --){
		//x[j] = a[j][n] / a[j][j];
		x[j] = div(a[j][n], a[j][j]);
		for(i = j - 1; i >= 0; i --){
			//a[i][n] -= a[i][j] * x[j];
			a[i][n] = sub(a[i][n], mul(a[i][j], x[j]));
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   	int T;
   	cin >> T;
   	while(T --){
   		ll x, y;
   		cin >> x >> y;
   		ma.clear();
   		id.clear();
   		sum.clear();
   		ma[mp(x, y)] = 1;
   		queue<pair<ll, ll > >q;
   		q.push(mp(x, y));
   		ma[mp(x, y)] = 1;
   		int cnt = 0;
  	 	int flag = 0;
  	 	int num = 1;
  	 	rep(i, 1, 10) num *= i;
  	 	//cout << num << endl;
   		while(!q.empty()){
   			ll xx = q.front().fi;
   			ll yy = q.front().se;
   			id[mp(xx, yy)] = cnt;
   			cnt ++;
   			sum[mp(xx, yy)] ++;
   			if(xx == yy) {
   				flag = 1;
   				break;
   			}
   			q.pop();
   			rep(i, 0, 8){
   				ll xxx = xx + dir[i][0];
   				ll yyy = yy + dir[i][1];
   				if(check(xxx, yyy)){
   					if(!ma[mp(xxx, yyy)]){ 
   						q.push(mp(xxx, yyy));
   						ma[mp(xxx, yyy)] = 1;
   					}
   					sum[mp(xx, yy)] ++;
   				}
   			}
   		}
   		if(flag){
   			cout << "0/1" << endl;
   			while(!q.empty()) q.pop();
   			continue;
   		}
   		ma.clear();
   		q.push(mp(x, y));
   		ma[mp(x, y)] = 1;
   		rep(i, 0, cnt){
   			rep(j, 0, cnt + 1) {
   				a[i][j].fi = 0;
   				a[i][j].se = 1;
   			}
   		}
   		while(!q.empty()){
   			ll xx = q.front().fi;
   			ll yy = q.front().se;
   			a[id[mp(xx, yy)]][id[mp(xx, yy)]] = mp(1, sum[mp(xx, yy)]);
   			q.pop(); 
   			rep(i, 0, 8){
   				ll xxx = xx + dir[i][0];
   				ll yyy = yy + dir[i][1];
   				if(check(xxx, yyy)){
   					a[id[mp(xx, yy)]][id[mp(xxx, yyy)]] = mp(1, sum[mp(xxx, yyy)]);
   					if(!ma[mp(xxx, yyy)]){
   						ma[mp(xxx, yyy)] = 1;
   						q.push(mp(xxx, yyy));
   					}
   				}
   			}
   			a[id[mp(xx, yy)]][id[mp(xx, yy)]] = sub(a[id[mp(xx, yy)]][id[mp(xx, yy)]], mp(1, 1));
   		}
   		rep(i, 0, cnt + 1){
   			a[cnt - 1][i] = mp(1, 1);
   		}
   		/*rep(i, 0, cnt){
   			rep(j, 0, cnt + 1){
   				cout << a[i][j].fi << "/" << a[i][j].se << " ";
   			}
   			cout << endl;
   		}*/
   		gau_s(a,cnt,ans);
   		cout << ans[0].fi << "/" << ans[0].se << endl;
   	}
    return 0;
}