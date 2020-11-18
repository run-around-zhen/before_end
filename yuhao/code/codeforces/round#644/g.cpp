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
map<string, int >ma;
int n, m;
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a ;
		}
		a = a * a;
		b /= 2;
	}
	return res;
}
string get(ll t){
	string s = "";
	string tt = "";
	while(t){
		if(t & 1){
			s.pb('1');
		}
		else{
			s.pb('0');
		}
		t /= 2;
	}
	while(tt.size() + s.size() < m) tt.pb('0');
	rep(i, 0, s.size()){
		tt += s[s.size() - i - 1];
	}
	return tt;
}
string s[200];
ll get(ll a, ll b){
	if(a == b + 1 || a == b || a + 1 == b) return 0;
	if(a > b) return 1;
	return  -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		cin >> n >> m;
		ma.clear();
		rep(i, 0, n){
			cin >> s[i];
			ma[s[i]] = 1;
		}
		//cout <<"??" << endl;
		ll t = qpow(2, m - 1) - 1;
		while(ma[get(t)]) {
			t ++;
		}
		//cout << get(t) << endl;
		//continue;
		int ans1 = 0, ans2 = 0;
		rep(i, 0, n){
			if(s[i] < get(t)) ans1 ++;
			else ans2 ++;
		}
		ll minn = t, maxn = t;
		//cout << ans1 << " " << ans2 << " " << get(t) << endl;
		//continue;
		//int sum1 = 0, sum2 = 0;
		int flag = get(ans1, ans2);
		ll tmp = qpow(2, m) - n;
		while(1){
			//cout << ans1 << " " << ans2 << " " << t  <<" " << get(t)<< endl;
			if(t - ans1  == (tmp - 1)/ 2){
				cout << get(t) << endl;
				break;
			}
			if(t - ans1 > tmp / 2){
				t = minn - 1;
				minn = min(minn, t);
			//	sum2 ++;
				while(ma[get(t)]) {
					t --;
					minn = min(minn, t);
				}
				ans1 = 0;
				ans2 = 0;
				rep(i, 0, n){
					if(s[i] < get(t)) ans1 ++;
					else ans2 ++;
				}
			}
			else{
				t = maxn + 1;
				//sum1 ++;
				maxn = max(maxn, t);
				while(ma[get(t)]) {
					t ++;
					maxn = max(maxn, t);
				}
				ans1 = 0;
				ans2 = 0;
				rep(i, 0, n){
					if(s[i] < get(t)) ans1 ++;
					else ans2 ++;
				}
			}
			//cout << ans1 << " " << ans2 << " " << get(t) << endl;
			//break;
		}

	}
	return 0;
}