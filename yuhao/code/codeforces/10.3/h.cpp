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
bool vis[1000000 + 10];
const int N = 1e6 +5;
vi prime;
int cal(int n){
	for(auto i : prime){
		//cout << i <<  " " << n << endl;
		if(!vis[n - i] && (n - i - i) % 2 == 0){
			return n - i - i;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	rep(i, 2, N + 1){
		int flag = 0;
		for(int j = 2; j * j <= i; j++){
			if(i % j == 0){
				flag = 1;
				break;
			}
		}
		if(flag){
			vis[i] = true;
		}
		else{
			prime.pb(i);
		}
	}
	int n;
	cin  >> n;
	int ans = 0;
	while(n >= 4){
		ans ++;
		n = cal(n);
	}
	cout << ans << endl;
	return 0;
}