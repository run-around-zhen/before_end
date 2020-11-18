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
bool vis[10000 + 10], vis1[10000 + 10];
int a[10000+ 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n + 1){
		memset(vis, false, sizeof(vis));
		int  j = 0;
		while(!vis[j]){
			cout << j << " ";
			vis[j] = true;
			vis1[j] = true;
			j += a[i];
			j %= m;
		}
		cout << endl;
	}
	int ans = 0;
	rep(i, 1, m + 1){
		if(vis1[i]){
			cout << i << " ";
			ans += i;
		}
	}
	cout << ans << endl;
	return 0;
}