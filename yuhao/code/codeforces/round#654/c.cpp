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
	int T;
	cin >> T;
	while(T --){
		ll a, b, n, m;
		cin >> a >> b >> n >> m;
		if(a + b < n + m){
			cout << "No" << endl;
			continue;
		}
		if(a > b && a - n > b &&  b < m){
			cout << "No" << endl;
			continue;
		}
		if(a <= b && b - n >= a && a < m){
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
	}
	return 0;
}