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
int cnt1[100000 + 10], cnt2[100000 + 10];
vi ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n + 1) {
		int x;
		cin >> x;
		x %= m;
		v1.pb(x);
	}
	rep(i ,1, n + 1){
		int x;
		cin >> x;
		x %= m;
		v2.pb(x);
	}
	sort(all(v1));
	sort(all(v2));
	rep(i, 0, m){
		while(sz(v1)){
			
		}
	}
	for(auto i : ans) cout << i << " ";
	return 0;
}