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
vi v[2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		v[0].clear();
		v[1].clear();
		rep(i, 0, n){
			if(s[i] == '0') v[0].pb(i);
			else v[1].pb(i);
		}
		while(q -- ){
			int l, r;
			cin >> l >> r;
			l --; r --;
			if(v[s[l] - '0'][0] < l || v[s[r] - '0'][v[s[r] - '0'].size() - 1] > r) cout << "YES" << endl;
			else {
				cout << "NO" << endl;
			}
 		} 
	}
	return 0;
}