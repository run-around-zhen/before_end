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
int a[10000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n ;
	int minn = 1e8;
	int sum = 0, res =0;
	rep(i, 1, 2 * n) {
		cin >> a[i];
		if(a[i] < 0) sum ++;
		a[i] = abs(a[i]);
		res += a[i];
		minn = min( minn, a[i]);
	}
	if(n % 2 == 1 || (n % 2 == 0 && sum % 2 == 0)){
		cout << res << endl;
	}
	else{
		cout << res - minn * 2 << endl;
	}
	return 0;
}