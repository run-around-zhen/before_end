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
ll a[1000000 + 10];
ll get(ll i){
	ll minn = 10,maxn = 0;
	while(i){
		minn = min(minn, i % 10);
		maxn = max(maxn, i % 10);
		i /= 10;
	}
	return minn * maxn;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		ll n, k;
		cin >> n >> k;
		a[1] = n;
		int flag = 0;
		rep(i, 2, k + 1){
			a[i] = a[i - 1] + get(a[i - 1]);
			if(get(a[i - 1]) == 0){
				cout << a[i] << endl;
				flag = 1;
				break;
			}
			
		}
		if(!flag) cout << a[k] << endl;
	}
	return 0;
}