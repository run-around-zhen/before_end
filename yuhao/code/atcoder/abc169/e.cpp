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
int l[1000000 + 10], r[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 0, n ){
		cin >> l[i] >> r[i];
	}
	sort(l, l + n);
	sort(r, r+ n);
	if(n % 2 == 1){
		cout << r[n / 2] - l[n / 2] + 1<< endl;
	}
	else{
		int x1 = l[n / 2] + l[n / 2 - 1];
		int y1 = r[n / 2] + r[n / 2 - 1];
		//cout << ans << endl;
		cout << y1 - x1 + 1 << endl;
	}
	return 0;
}