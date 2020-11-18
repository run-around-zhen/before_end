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
int a[200000 + 10];
vi v;
int dfs(int pos, vi v){
	vi vL, vR;
	/*for(auto i : v){
		cout << a[i] << " ";
	}
	cout << endl;*/
	if(pos == 0) return v.size();
	for(auto i: v){
		if((a[i] >> pos) & 1) vL.pb(i);
		else vR.pb(i);
	}
	int ans = 0;
	int cntl = 0, cntr = 0;
	if(vL.size()){
		cntl = dfs(pos - 1, vL);
	}
	if(vR.size()){
		cntr = dfs(pos - 1, vR);
	}
	if(vL.size()){
		ans = max(ans, cntr + 1);
	}
	if(vR.size()){
		ans = max(ans, cntl + 1);
	}
	//de(cntl);
	return max(max(cntl, cntr), ans);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n + 1) v.pb(i);
	cout << n - dfs(30, v) << endl;
	return 0;
}