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
const int M = 64;
ll a[M + 10], f[M + 10];
void add(ll x){
	per(i, 0, M){
		if(x >> i & 1){
			if(a[i]) x ^= a[i];
			else{
				a[i] = x;
				break;
			}
		}
	}
}
ll base = 0;
int cal(ll x, int pos){
	int cnt = 0;
	rep(i, 0, pos + 1) if(base >> i & 1) cnt ++;
	return cnt;
}
void init(){
	int cnt = 0;
	rep(i, 0, M){
		if(a[i]) {
			cnt ++;
			base |= a[i];
		}
		f[i] = 1ll << cal(base, i);
	}
}
ll get(ll x, ll pos){
	return x & ((1ll << pos) - 1);
}
ll get_ans(ll x, ll pos){
	if(pos < 0) return 1;
	int a = x >> pos & 1, b = base >> pos & 1;
//	cout << x << " " << pos << " " << a << " " << b << endl;
	if(a == 0) return get_ans(x, pos - 1);
	if(b == 0) {
		if(pos == 0) return 1;
		else return f[pos - 1];
	}
	else{
		if(pos == 0) return 2;
		else{
			//cout << x << " " << M << endl;
			return get_ans(get(x, pos), pos - 1) + f[pos - 1];
		}
	}
}
ll solve1(ll l, ll r, int pos){
	// l > r
	int a = (l >> pos & 1), b = (r >> pos & 1), c =  (base >> pos & 1);
	ll x = get(l, pos), y = get(r, pos), z = (1ll << pos) - 1 - x;
	if(c){
		if(a == b){
			if(pos == 0) return 1;
			if(x <= y) return f[pos];
			else return f[pos - 1] + solve1(x, y, pos - 1);
		}
		else{
			// a = 1, b = 0; a - 1111111, 0 ~ b
			if(pos == 0) return 2;
			return get_ans(z, pos - 1) + get_ans(y, pos - 1);
		}
	}
	else{
		if(a == b){
			if(pos == 0) return 1;
			else return f[pos - 1];
		}
		else{
			if(pos == 0) return 1;
			else{
				if(x <= y) return f[pos - 1];
				else return solve1(x, y, pos - 1);
			}
		}
	}
}
ll solve(ll l, ll r, int pos){
	int a = (l >> pos & 1), b = (r >> pos & 1), c = (base >> pos & 1);
	ll x = get(l, pos), y = get(r, pos), z = (1ll << pos) - 1 - x;	
	if(a == b){
		if(pos == 0) return 1;
		return solve(l, r, pos - 1);
	}
	else{
		if(!c) {
			if(pos == 0) return 1;
			else {
				if(x <= y) return f[pos - 1];
				else return solve1(x, y, pos - 1);
			}
		}
		else{
			if(pos == 0) return 2;
			else{
				return get_ans(y, pos - 1) + get_ans(z, pos - 1);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1) {
		ll x;
		cin >> x;
		add(x);
	}
	init();
	int q;
	cin >> q;
	while(q --){
		int op;
		ll l, r;
		cin >> op >> l >> r;
		if(op == 1) cout << r - l + 1 << endl;
		else{
			cout << solve(l, r, M - 1) << endl;
		}
	}
	return 0;
}