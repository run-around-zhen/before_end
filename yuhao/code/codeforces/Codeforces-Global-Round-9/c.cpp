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
int a[1000000 + 10], minn[1000000 + 10], maxn[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		rep(i, 1, n + 1) cin >> a[i];
		if(a[1] <= a[n]){
			cout << "YES" << endl;

		}
		else{
			cout << "NO" << endl;
		}
		/*int flag = 0;
		minn[0] = 1e9;
		maxn[n + 1] = 0;
		rep(i, 1, n + 1){
			cin >> a[i];
		}
		rep(i, 1, n + 1){
			minn[i] = min(minn[i - 1], a[i]);
		}
		per(i, 1, n + 1){
			maxn[i] = max(maxn[i  + 1], a[i]);
		}
		rep(i, 1, n + 1){
			if(minn[i - 1] < a[i] || maxn[i + 1] > a[i]) continue;
			else flag = 1;
		}
		if(flag){
			cout << "NO" <<endl;
		}
		else{
			cout << "YES" << endl;
		}*/
	}
	return 0;
}	