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
const int N = 1510;
bitset<N> in[N], out[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("triatrip.in","r",stdin);
	freopen("triatrip.out","w",stdout)
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		rep(j, 1, n + 1){
			char s;
			cin >> s;
			if(s == '+') {
				in[i][j] = true;
				out[j][i] = true;
			}
		}
	}
	ll ans = 0;
	rep(i, 1, n + 1){
		rep(j, 1, n + 1){
			if(i == j) continue;
			if(out[i][j]) ans += (in[i] & out[j]).count();
		}
	}
	cout << ans / 3<< endl;
	return 0;
}