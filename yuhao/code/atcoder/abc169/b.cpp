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
ll a[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		cin >> a[i];
	}
	sort(a + 1, a+ 1 + n);
	ll sum = 1;
	ll maxn = 1e18;
	rep(i, 1, n + 1){
		if(sum == 0 || a[i] == 0){
			cout << "0" << endl;
			return 0;
		}
		if(maxn / a[i] < sum ){
			cout << "-1" << endl;
			return 0;
		}
		sum *= a[i];
	}
	if(sum <= maxn)cout << sum << endl;
	else cout << "-1" << endl;
	return 0;
}