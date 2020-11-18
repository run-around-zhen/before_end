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
bool cmp(pii a, pii b){
	return a.fi > b.fi;
}
const int N = 150010;
pii a[N], b[N];
bitset<N>ans, res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n + 1) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	rep(i, 1, m + 1){
		cin >> b[i].fi;
		b[i].se = i;
	}
	sort(a + 1, a + 1 + n, cmp);
	sort(b + 1, b + 1 + m, cmp);
	ans.set();
	int j = 1;
	rep(i, 1, m + 1){
		//
		while(j <= n && a[j].fi >= b[i].fi){
			res.set(a[j].se);
			j ++ ;
		}
		ans &= (res >> (b[i].se - 1));
	}
	cout << ans.count() << endl;
	return 0;
}