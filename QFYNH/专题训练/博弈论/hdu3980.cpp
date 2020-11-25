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
int n, m;
int s[1010];
int sg(int x){
	if(s[x] != -1) return s[x];
	if(x < m) return s[x] = 0;
	bool vis[1010];
	memset(vis, false, sizeof(vis));
	rep(i, 0, x - m + 1){
		//dd(x);dd(i);de(x - m - i);
		vis[sg(i) ^ sg(x - m - i)] = true;
	}
	rep(i, 0, n + 1){
		if(!vis[i]) {
			s[x] = i; 
			break;
		}
	}
	return s[x];
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	rep(cas, 1, T + 1){
		cin >> n >> m;
		memset(s, -1, sizeof(s));
		cout << "Case #" << cas << ": ";
		if(n < m){
			cout << "abcdxyzk" << endl;
		}
		else{
			if(sg(n - m)) cout << "abcdxyzk" << endl;
			else cout << "aekdycoin" << endl;
		}
		//dd(sg(0));dd(sg(1));dd(sg(2));
	}
	return 0;
}
/*
1
3 1 
*/