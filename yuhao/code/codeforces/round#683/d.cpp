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
int dp[400000 + 10], cnt[200000 + 10], num[200000 + 10], a[200000 + 10];
void add(int x){
	num[cnt[x]] --;
	cnt[x] ++;
	num[cnt[x]] ++;
	return ;
}
void del(int x){
	num[cnt[x]] --;
	cnt[x] --;
	num[cnt[x]] ++;
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
	rep(i, 1, n + 1){
		add(a[i]);
	}
	int mx = 0;
	int pos = 0;
	rep(i, 1, n + 1){
		if(cnt[a[i]] > mx){
			mx = cnt[a[i]];
			pos = a[i];
		}
	}
	rep(i, 1, n + 1){
		if(mx == cnt[a[i]] && pos != a[i]){
			cout << n << endl;
			return 0;
		}
	}
	int ans = 0;
	for(int i = 1; i * i <= n; i ++){
		rep(j, 1, n + 1){
			cnt[j] = num[j] = 0;
		}
		int mx = 0;
		int l = 1;
		rep(j, 1, n + 1){
			add(a[j]);
			mx = max(mx, cnt[a[j]]);
			while(mx > i){
				del(a[l]);
				if(!num[mx]) mx --;
				l ++;
			}
			if(num[mx] >= 2){
				ans = max(ans, j - l + 1);
			}
			//dd(l);dd(j);de(mx);
		}
		//dd(i);
		//dd(cnt[a[n]]);
		//de(ans);
	}
	//de(ans);
	rep(i, 1, n + 1) cnt[i] = 0;
	rep(i, 1, n + 1) add(a[i]);
	rep(i, 1, n + 1){
		if(i == pos || cnt[i] * cnt[i] < n) continue;
		int sum = 0;
		rep(j, 1, 2 * n + 1) dp[j] = 1e9;
		dp[0 + n] = 0;
		rep(j, 1, n + 1){
			if(a[j] == i) sum ++;
			if(a[j] == pos) sum --;
			ans = max(ans, j - dp[sum + n]);
			dp[sum + n] = min(dp[sum + n], j);
		}
	}
	cout << ans << endl;
	return 0;
}