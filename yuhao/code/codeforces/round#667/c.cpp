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
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n, x, y;
		cin >> n >> x >> y;
		int ans = 0, dd = 0, maxn = 1e9;
		rep(i, 1, n + 1){
			rep(j, i + 1, n + 1){
				if((y - x)% (j - i) != 0) continue;
				int d = (y - x) / (j - i);
				if(x - (i - 1) * d >= 1 && x - (i - 1) * d + (n - 1) * d <= maxn){
					maxn = x - (i - 1) * d + (n - 1) * d;
					ans = x - (i - 1) * d;
					dd = d;
				}
			}
		}
		rep(i, 1, n + 1){
			cout << dd  * (i - 1) + ans <<  " ";
		}
		cout << endl;
	}
	return 0;
}