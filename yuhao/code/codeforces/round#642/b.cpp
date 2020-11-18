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
int a[1000000 + 10],b[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n, k;
		cin >> n >> k;
		rep(i, 1, n + 1) cin >> a[i];
		rep(i, 1, n + 1) cin >> b[i];
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		rep(i, 1, k + 1){
			if(a[i] > b[n - i + 1]) break;
			swap(a[i], b[n - i + 1]);
		}
		ll sum = 0;
		rep(i, 1, n + 1) sum += a[i];
		cout << sum  << endl;
	}
	return 0;
}