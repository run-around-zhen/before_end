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
map<string, int> ma, ma1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		string s;
		cin >> s;
		per(i, 0, s.size()){
			if(s[i] == '/'){
				string ss = "";
				rep(j, 0, i){
					ss += s[j];
					
					//cout << ss << endl;
					
				}ma[ss] ++;break;
			}
		}
		ma1[s] = 1;
	}
	int ans = 0;
	for(auto i : ma1){
		string s = i.fi;
		if(s.size() >= 4){
			int len = s.size();
			if(s[len - 1] == 'j' && s[len - 2] == 'o' && s[len - 3] == 'e' && s[len - 4] == '.'){
				if(ma[s] == 0) ans ++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}