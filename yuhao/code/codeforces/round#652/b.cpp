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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n;
		string s;
		cin >> n >> s;
		int flag = 0;
		string ans="";
		rep(i, 0, n){
			if(s[i] == '0'){
				ans += '0';
			}
			else break;
		}
		per(i, 0, n){
			if(s[i] == '1'){
				ans += '1';
			}
			else break;
		}
		if(ans.size() == n){
			cout << ans << endl;
		}
		else{
			cout << "0";
			cout << ans << endl;
		}
	}
	return 0;
}