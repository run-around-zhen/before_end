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
int ans[2000000 + 10], sum[2000000 + 10], pos[2000000 + 10];
int n;
int cal(int limit){
	int res = 0;
	int tot = 0;
	for(int i = 1; i <=n ;){
		//cout << pos[4] << endl;
	//	cout << i << " " << limit << " " << tot << " "<< tot + limit << " " << pos[tot + limit] + 1 << endl;
		if(tot + limit >= sum[n]) {
			res ++;
			break;
		}
		i = pos[tot + limit] + 1;
		tot = sum[pos[tot + limit]];
		res ++;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	int maxn = 0;
	rep(i, 1, n + 1) {
		cin >> sum[i];
		maxn = max(maxn, sum[i]);
		sum[i] += sum[i - 1];
		pos[sum[i]] = i;
	}
	//cout << pos[4] << " " << sum[1] << endl;
	rep(i, 1, 1000000 + 1){
		if(pos[i] == 0) pos[i] = pos[i - 1];
	}
	rep(i, maxn, 1000000 + 1){
		ans[i] = cal(i);
	}
	int q;
	cin >> q;
	while(q --){
		int t;
		cin >> t;
		if(t < maxn) cout << "Impossible" << endl;
		else cout << ans[t] << endl;
	}
	return 0;
}