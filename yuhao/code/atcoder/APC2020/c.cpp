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
ll a[1000000 + 10],b[1000000 + 10], c[1000000 + 10], d[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 0, n + 1) cin >> a[i];
	b[0] = 1;
	rep(i, 1, n + 1){
		if(b[i - 1] > 1e17) b[i] = 1e17;
		b[i] = b[i - 1] * 2;
	}
	for(int i = n;i >= 0; i --){
		if(a[i] + sum > b[i]) {
			cout << "-1" << endl;
			return 0;
		}
		sum = (sum + a[i] + 1) / 2;
	}
	int l = 0;
	ll sum = 0, cnt = 2;
	ll ans = 0;
	rep(i, 1, n + 1){
		ll tmp = cnt - sum;
		while(a[i] > tmp){
			ans += (i - l ) * tmp;
			a[i] -= tmp;
			sum += tmp;
			d[l + 1] += tmp;
			d[i] -= tmp;
			if(sum > cnt || l == i) {
				cout <<"-1" << endl;
				return 0;
			}
			l ++ ;
			cnt += d[l];
		}

	}
	cout << ans << endl;
	return 0;
}