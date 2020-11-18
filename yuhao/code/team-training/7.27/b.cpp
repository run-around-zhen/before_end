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
const int mod = 1e9 + 7;
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		b /= 2;
		a = a * a % mod;
	}
	return res;
}
int res[100]; 
bool add(int x){
	per(i, 0, 5){
		if(x >> i & 1){
			if(!res[i]){
				res[i] = x;
				return true;
			}
			else{
				x ^= res[i];
			}
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int cnt =0 ;
	rep(i, 0, 32){
		rep(j, 0, 32){
 			rep(k, 0, 32){
 				rep(q, 0, 32){
 					rep(z, 0, 32){
 						memset(res, 0, sizeof(res));
 						if(add(i) && add(j) && add(k) &&add(q) && add(z)){
 						//cout << i << " " << j << " " << k << endl;
 							cnt ++;
 						}
 					}
 				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}