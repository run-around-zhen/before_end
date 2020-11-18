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
ll A[100000];
ll get(int a, int b){
	return A[a] / A[b] / A[a - b];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll sum = 0 ;
	A[0] = 1;
	rep(i, 1, 30) A[i] = A[i - 1] * i;
	rep(i, 0, 21){
		ll ans = 0;
		rep(j, 0, min(10, 20 - i) + 1){
			ans += get(10, j);
		}
		ans *= get(20, i);
		sum += ans;
	}
	cout << sum << endl;
	return 0;
}