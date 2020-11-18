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
bool vis[10000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, m + 1){
		int x, y;
		cin >> x >>y;
		vis[x] = true;
		vis[y] = true;
	}
	rep(i, 1, n + 1){
		if(!vis[i]){
			cout << n - 1 << endl;
			rep(j, 1, n + 1){
				if(i == j ) continue;
				cout << i << " " << j << endl;
			}
			break;
		}
	}
	return 0;
}