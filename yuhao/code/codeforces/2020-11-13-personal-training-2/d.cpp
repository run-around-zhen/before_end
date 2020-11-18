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
int a[1000000 + 10], f[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		cin >> a[i];
		f[i] = i + 1;
	}
	queue<pii>q;
	per(i, 0, n){
		if(a[i] > a[i + 1]) q.push(mp(i, 0));
	}
	int ans = 0;
	while(!q.empty()){
		int id = q.front().fi;
		int now = q.front().se;
		q.pop();
		ans = max(ans, now);
		if(f[id] != n + 1 && a[id] > a[f[id]]){
			f[id] = f[f[id]];
			q.push(mp(id, now + 1));
		} 
	}
	cout << ans << endl;
	return 0;
}