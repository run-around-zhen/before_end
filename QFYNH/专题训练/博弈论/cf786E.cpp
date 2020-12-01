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
int sg[100];
bool vis[100];
int get(int x){
	if(sg[x] != - 1) return sg[x];
	bool vis1[15];
	memset(vis1, false, sizeof(vis1));
	rep(i, 1, x + 1){
		if(!vis[i]){
			vis[i] = true;
			int t = get(x - i);
			if(t < 15) vis1[t] = true;
			vis[i] = false; 
		}
	}
	rep(i, 0, 15){
		if(!vis1[i]){
			return sg[x] = i;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	int ans = 0;
	rep(i, 1, n + 1){
		int x;
		cin >> x;
		memset(sg, -1, sizeof(sg));
		ans ^= get(x);
	}
	if(ans){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
	}
	return 0;
}