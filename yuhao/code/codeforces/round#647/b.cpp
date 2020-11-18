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
bool vis[1100];
int a[1100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		rep(i, 1, n + 1){
			cin >> a[i];
		}
		int ans = -1;
	//	rep(i, 1, n + 1) cout << a[i] << " ";
	//	cout << "!!" << endl;
		rep(i, 1, 1025){
			memset(vis,false,sizeof(vis));
			rep(j, 1, n + 1){
				vis[(a[j] ^ i)] = true;
				//cout << a[j] << " " << (a[j] ^ i ) << endl;
			}
			int flag = 0;
			rep(j, 1, n + 1){
				if(!vis[a[j]]) flag = 1;
			}
			if(!flag){
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}