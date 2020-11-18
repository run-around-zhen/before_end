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
int a[200000 + 10];
int n;
bool check(int x){
	if(x == n - 1) return true;
	int begin = x + 1;
	int end = n;
	int now = 0;
	while(begin <= end){
		if(a[begin] < a[end]) {
			if(now <= a[begin]) {
				now = a[begin];
				begin ++;
			}
			else return false;	
		}
		else {
			if(now <= a[end]) {
				now = a[end];
				end --;
			}
			else return false;	
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		cin >> n;
		rep(i, 1, n + 1) cin >> a[i];
		int l = 0, r = n - 1;
		int ans = n - 1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(check(mid)) {
				r = mid - 1;
				ans = min(ans, mid);
			}
			else{
				l = mid + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}