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
ll n, k;
int ans = 0;
bool get(string s){
	rep(i, 0, s.size()){
		if(s[i] != s[s.size() - i - 1]) return false;
	}
	return true;
}
bool check(string s){
	string s1 = "", s2 = "";
	rep(i, 0, n){
		s1 += s[i];
		i ++;
	}
	rep(i, 1, n){
		s2 += s[i];
		i ++;
	}
	if(get(s1) || get(s2)) return true;
	return false;
}
string s= "";
int flag = 0;
void dfs(int i){
	if(i == n){
		if(check(s)) ans ++;
		if(k == ans){
			cout << s <<endl;
			flag = 1;
		}
		return ;
	}
	if(flag) return ;
	s.pb('0');
	dfs(i + 1);
	s.pop_back();
	s.pb('1');
	if(flag) return ;
	dfs(i + 1);
	s.pop_back();
	if(flag) return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> s;
	n = 30;
	k = 2e18;
	dfs(s.size());
	cout << ans << endl;
	return 0;
}