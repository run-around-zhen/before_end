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
typedef pair<ll, int> pii;
typedef vector<int> vi;
ll a[200000 + 10], l[200000 + 10], r[200000 + 10];
bool vis[200000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	priority_queue<pii, vector<pii>, greater<pii> > q;
	int n;
	cin >> n;
	rep(i, 0, n){
		cin >> a[i];
		l[i] = (i - 1 + n) % n;
		r[i] = (i + 1 + n) % n;
		q.push(mp(a[i], i));
	}
	if(n == 1) {
		cout << a[0] << endl;
		return 0;
	}
	while(!q.empty()){
		int id = q.top().se;
		q.pop();
		if(vis[id]) continue;
		a[id] = a[l[id]] + a[r[id]];
		vis[l[id]] = true;
		vis[r[id]] = true;
		if(q.size() == 0) {
			cout << a[id] << endl;
			return 0;
		}
		int L = l[l[id]];
		int R = r[r[id]];
		r[L] = id;
		l[R] = id;
		l[id] = L;
		r[id] = R;
		q.push(mp(a[id], id));
	}
	return 0;
}