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
int prime[20] = {2, 3, 5 ,7, 11, 13, 17, 19, 23, 29, 31,33};
int solve(int i){
	int ans = i;
	rep(j, 0, 12){
		if(i % prime[j] == 0){
			ans /= prime[j];
			ans *= (prime[j] - 1);
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
/*	rep(i, 1, 100){
		cout <<  i << " " << solve(i) << endl;
	}*/
	int T;
	cin >> T;
	while(T --){
		ll k;
		cin >> k;
		if(k == 1){
			cout << "5" << endl;
		}
		else{
			cout << 5 + k << endl;
		}
	}
	return 0;
}
