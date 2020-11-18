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
bool vis[100];
int a[110];
vi ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		ans.clear();
		int n;
		cin >> n;
		rep(i ,1, n * 2 + 1) cin >> a[i];
		rep(i, 1, n * 2 + 1){
			if(!vis[a[i]]) {
				vis[a[i]] = true;
				ans.pb(a[i]);
			}
		}
		for(auto i : ans){
			cout << i << " ";
		}
		cout << endl;
		rep(i, 1, n + 1) vis[i] = false;
	}
	return 0;
}