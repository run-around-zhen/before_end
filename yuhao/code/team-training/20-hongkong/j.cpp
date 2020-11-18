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
int m;
int d(int x, int y){
	int cnt = 1;
	while(x){
		if(cnt == y) return x % 10;
		x /= 10;
		cnt++;
	}
}
int get(int x){
	int cnt = 0;
	while(x){
		x /= 10;
		cnt++;
	}
	return cnt;
}
int f(int x){
	int k = get(x);
	//cout << k << "!!" << endl;
	int sum = 0;
	rep(i, 1, k){
		rep(j, i + 1, k + 1){
			sum += d(x, i) * d(x, j);
			//cout << x <<" " << i << " " << d(x, i) << endl;
		}
	}
	return sum;
}
bool check(int i){
	if(i % m == f(i) % m) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n >> m;
	int ans = 0;
	int  p;
	rep(i, 10, n + 1){
		if(check(i)) {
		 	cout << i << endl;
			ans ++;
		}
	}
	//cout << p << endl;
	//cout << f(3213131) << endl;
	cout << ans << endl;
	return 0;
}