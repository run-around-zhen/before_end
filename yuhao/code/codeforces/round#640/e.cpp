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
int ans[8000+10];
int sum[8000+10];
bool vis[8000+10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n ;
		int res = 0;
		memset(ans, 0, sizeof(ans));
		memset(vis, false, sizeof(vis));
		rep(i, 1, n + 1){
			int x;
			cin >> x;
			ans[x] ++;
			sum[i] = sum[i-1] + x;
		}
		rep(i, 0, n + 1){
			rep(j, i + 2, n + 1){
				if(sum[j] - sum[i] <= 8000 && !vis[sum[j] - sum[i]]){
					res += ans[sum[j] - sum[i]];
					vis[sum[j] - sum[i]] = true;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}