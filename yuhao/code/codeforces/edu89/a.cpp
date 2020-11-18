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
	while(T--){
		int a,b;
		cin >> a >> b;
		if( b > a ) swap(a,b);
		int tmp = min(b, a - b);
		int ans = tmp;
		b -= tmp;
		a -= 2 * tmp;
		if(a == b){ 
			ans += (a / 3) * 2;
			a %= 3;
			if(a == 2) ans ++;
		}
		cout << ans << endl;

	}
	return 0;
}