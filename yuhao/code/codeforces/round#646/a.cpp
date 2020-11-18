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
		int n, x;
		cin >> n >> x;
		int ans1 = 0, ans2 = 0;
		rep(i, 1, n + 1){
			int tt ;
			cin >> tt;
			if(tt % 2 == 1) ans1++;
			else ans2 ++;
		}
		ans1 --;
		if(ans1 < 0){
			cout << "No" << endl;
			continue;
		}
		//cout << ans2 << endl;
		int tmp = ans1 / 2 * 2;
		x --;
		if(x >= tmp) x-= tmp;
		else x = x % 2;
		if(x <= ans2){
			cout << "Yes"<< endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	return 0;
}