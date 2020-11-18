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
vi a, b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		a.clear();
		b.clear();
		rep(i, 1, 2 * n + 1){
			int x;
			cin >> x;
			if(x % 2 == 0) a.pb(i);
			else b.pb(i);
		}
		int cnt = 0;
		rep(i, 1, (int)a.size()){
			if(cnt == n - 1) break;
			cout << a[i - 1] << " " << a[i] << endl;
			i ++;
			cnt ++;
		}
		rep(i, 1, (int)b.size()){
			if(cnt == n - 1) break;
			cout << b[i - 1] << " " << b[i] << endl;
			i ++;
			cnt ++;
		}

	}
	return 0;
}