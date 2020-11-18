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
int ans1, ans2;
bool prime[100000 + 10];
vi p;
bool check(int i){
	if(i <= 1e5){
		return prime[i];
	}
	int flag = 0;
	for(auto j:p){
		if(i % j == 0) return false;
	}
	return true;
}
bool check1(int sum){
	rep(i, 2, sum + 1){
		if(check(i) && check(sum - i)){
			ans1 = i;
			ans2 = sum - i;
			return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for(int i = 2;i <= 1e5; i ++ ){
		int flag = 0;
		for(int  j = 2; j * j <= i; j ++ ){
			if(i % j == 0) flag = 1;
		}
		if(!flag){
			prime[i] = true;
			p.pb(i);
		}
	}
	if(check(n)){
		cout << "1" << endl;
		cout << n << endl;
		return 0;
	}
	per(i, 1, n + 1){
		if(check(i)){
			if(check(n - i)){
				cout << "2" <<endl;
				cout << i << " " << n - i << endl;
				return 0;
			} 
			if(check1(n - i)){
				cout << "3" << endl;
				cout << i << " " << ans1 <<" " <<ans2 <<endl;
				return 0;
			}
		}
	}
	return 0;
}