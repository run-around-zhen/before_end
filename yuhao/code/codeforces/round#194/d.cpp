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
int x[100000],y[100000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m ;
	rep(i, 1, m + 1){
		int a, b;
		cin >> a >> b;
		x[a] = true;
		y[b] = true;
	}
	int ans = 0;
	rep(i, 2, n){
		if(!x[i]) ans ++;
		if(!y[i]) ans ++;
	}
	if(n % 2 == 1 && x[n / 2 + 1] == 0 && y[n / 2 + 1] == 0) ans--;
	cout << ans << endl;
	return 0;
}