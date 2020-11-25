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
vi edge[100000 + 10];
int a[100000 + 10];
int deep[100000 +10];
map<int, ll> tot_sum, ma1, ma2;
void dfs(int rt, int fi){
	deep[rt] = deep[fi] + 1;
	for(auto i : edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
	}
	return ;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 2, n + 1){
		int x;
		cin >> x;
		edge[x].pb(i);
		edge[i].pb(x);
	}
	dfs(1, 0);
	int ans = 0;
	int maxn = 0;
	rep(i, 1, n + 1){
		maxn = max(maxn, deep[i]);
	}
	maxn %= 2;
	rep(i, 1, n + 1){
		if(deep[i] % 2 == maxn) ans ^= a[i]; 
	}
	ll tot = 0;
	ll cnt1 = 0, cnt2 = 0;
	rep(i, 1, n + 1){
		if(deep[i] % 2 != maxn){
			ma1[a[i]] ++;
			cnt1 ++;
		}
		else {
			ma2[a[i]] ++;
			cnt2 ++;
		}
		tot_sum[a[i]] ++;
	}
	if(ans){
		//de(ans);
		rep(i, 1, n + 1){
			if(deep[i] % 2 == maxn) tot += ma1[ans ^ a[i]];
			//dd(i);de(tot);
		}
		cout << tot << endl;
	}
	else{
		//de(ans);
		for(auto i: ma2){
			//tot += i.se * (i.se - 1) / 2;
			tot += (i.se * ma1[i.fi]);
			//dd(tot);dd(i.fi);de(ma1[i.fi]);
		}
		// de(tot);
		// de(ma1.size());
		// for(auto i: ma1){
		// 	dd(i.fi);de(i.se);
		// }
		// tot += (ll)ma1.size() * (ma1.size() - 1) / 2;
		// tot += (ll)(ma2.size() * (ma2.size() - 1)) / 2;
		tot += cnt1 * (cnt1 - 1) / 2 + cnt2 * ( cnt2 - 1) /2 ;
		cout << tot << endl;
	}
	return 0;
}