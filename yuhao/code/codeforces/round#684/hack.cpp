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
int main(){
//	freopen("ssss.in", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n = 200000, q = 200000;
	cout << n << " " << q << endl;
	rep(i, 1 , n + 1) {
		if(i == n) cout << n - i + 1 << endl;
		else cout << n - i + 1 << " ";
	}
//	cout << endl;
	rep(i, 1, q + 1){
		cout << "2 1 1000000000" << endl;
	}
	return 0;
}