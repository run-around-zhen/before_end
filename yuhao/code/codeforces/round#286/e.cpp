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
bool check(string s){
	rep(i, 0, s.size()){
		if(s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;
	cin >> s;
	rep(i, 0, s.size() + 1){
		rep(k, 0, 26){
			string s1 = "";
			rep(j, 0, i) s1 += s[j];
			s1 += (char)(k + 'a');
			rep(j, i, s.size()) s1 += s[j];
			if(check(s1)){
				cout << s1 << endl;
				return 0;
			}
		}
	}
	cout << "NA" << endl;
	return 0;
}