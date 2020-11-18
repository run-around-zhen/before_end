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
int a[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n, x;
		cin >> n >> x;
		int sum = 0;
		rep(i, 1, n + 1){
			cin >> a[i];
			sum += a[i];
		}
		int res1 = 0, res2 = 0; 		
		rep(i, 1, n + 1){
			if(a[i] % x == 0) res1 ++;
			else break;
		}
		per(i, 1, n + 1){
			if(a[i] % x ==0) res2 ++;
			else break;
		}
		if(sum % x !=	0){
			cout << n << endl;
			continue;
		}
		if(res1 == n){
			cout << "-1" << endl;
		}
		else{
			if(sum % x == 0){
				cout << n -min(res1, res2) - 1<< endl;
			}
			else cout << n - min(res1 , res2) << endl;
		}
		
	}
	return 0;
}