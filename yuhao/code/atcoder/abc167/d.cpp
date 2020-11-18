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
ll sum = 0;
int deep[200000+10];
bool vis[200000+10];
int res[200000+10];
int a[200000+10];
ll len = 0;
int dfs(int i){
	vis[i] = true;
	sum ++ ;
	deep[i] = sum ;
	res[sum] = i;
	if(!vis[a[i]]) return dfs(a[i]);
	else return sum - deep[a[i]] + 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	ll k;
	cin >> n >> k;
	k ++ ;
	rep(i, 1, n + 1) cin >> a[i];
	len = dfs(1);
	if(k <= sum){
		cout << res[k] << endl;
	}
	else{
		int last = sum - len;
		k -= last;
		k %= len;
	//	cout << sum <<" " << len <<" " << k <<endl;
		if( k == 0 ) cout << res[sum] << endl;
		else cout << res[last + k ] << endl;
	}
	return 0;
}
/*
6 8
6 5 2 5 3 2
*/