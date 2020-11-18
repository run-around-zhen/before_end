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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int ans = 0, pos = -1;
	rep(i, 1, n + 1){
		int id, x, y, z;
		cin >> id >> x >> y >> z;
		int val = x + 2 * y + 3 * z;
		if(val > ans){
			ans = val;
			pos = id;
		}
	}
	cout << pos << " " << ans << endl;
	return 0;
}