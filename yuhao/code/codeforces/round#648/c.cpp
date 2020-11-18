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
int a[2000000 + 10], b[2000000 + 10], id[2000000 + 10], res[2000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1) cin >>a[i];
	rep(i ,1, n + 1) {
		cin >> b[i];
		id[b[i]] = i;
	}
	rep(i, 1, n + 1){
		res[(i - id[a[i]] + n) % n] ++;
	}
	int sum = 0;
	rep(i, 0, n + 1){
		sum = max(sum, res[i]);
	}
	cout << sum << endl;
	return 0;
}