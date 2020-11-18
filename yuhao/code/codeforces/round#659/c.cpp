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
map<pair<char, char>, int> ma;
vi s[30];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		int flag = 0;
	//	ma.clear();
		rep(i, 0, 26)s[i].clear();
		rep(i, 0, n){
			if(a[i] != b[i]) s[a[i] - 'a'].pb(i);
			if(a[i] > b[i]) flag = 1;
		}
		int ans = 0;
		if(flag){
			cout << "-1" << endl;
			continue;
		}
		rep(i, 0, 26){
			if(s[i].size() == 0) continue;
			else {
				char minn = 'z';
				for(auto j : s[i]){
					minn = min(minn, b[j]);
				}
				for(auto j : s[i]){
					if(b[j] == minn) continue;
					//cout << minn << " " << j << endl;
					s[minn - 'a'].pb(j);
				}
			}
			ans ++;
			s[i].clear();
		}
		cout << ans << endl;
	}
	return 0;
}