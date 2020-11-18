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
char s[1000000], s1[1000000], a[1000000];
int cal(int l, int r, char c){
	int ans = 0, ans1 = 0;
	if(l == r){
		if(a[l] != c) {
			ans ++;
			ans1 ++;
			return 1;
		}
		return 0;
	}
	int mid = (l + r) / 2;
	rep(i, l, mid + 1) {
		if(a[i] != c) ans ++;
	}
	rep(i, mid + 1, r + 1) {
		if(a[i] != c) ans1 ++;
	}
	int sum1 = cal(l, mid, c + 1);
	int sum2 = cal(mid + 1, r, c + 1);
	return min(sum2 + ans, sum1 + ans1);

}
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
		cout << cal(1, n, 'a') << endl;
	}
	return 0;
}