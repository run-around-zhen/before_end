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
ll mod = 998244353;
int a[200000 + 10], b[200000 + 10];
map<int, int>cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, m + 1) cin >> b[i];
	int minn = 1e9;
	int j = m;
	per(i, 1, n + 1){
		minn = min(minn, a[i]);
		cnt[minn] ++;
		if(minn == b[j]) j --;
		/*if(a[i] == b[1]){
			if(r == 0) r = i;
			else l = i;
		}*/
	}
	if(j != 0 || minn != b[1]){
		cout << "0" <<endl;
		return 0;
	}
	ll ans = 1;
	rep(i, 2, m + 1){
		ans = ans * cnt[b[i]] % mod;
	}
	cout << ans << endl;
	return 0;
}