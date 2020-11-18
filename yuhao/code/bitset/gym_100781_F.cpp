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
bitset<200000> a, b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	int ans = 1;
	while(T --){
		int n, m;
		cin >> n >> m;
		int flag = 0;
		a.reset();
		b.reset();
		rep(i, 0, n + 1) a[i] = b[i] = 1;
		while(m --){
			int l, r;
			cin >> l >> r;
			a = (a >> (r - l) | a << (r - l)) & b;
		}
		rep(i, 0, n + 1){
			if(a[i]) flag = 1;
		}
		ans &= flag;
	}
	if(ans){
		cout << "possible" << endl;
	}
	else{
		cout << "impossible" << endl;
	}
	return 0;
}