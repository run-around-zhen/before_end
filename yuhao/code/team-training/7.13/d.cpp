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
int get(string s){
	return ((s[0] - 'a') * 10 + s[1] - 'a') * 3600 + ((s[3] - 'a') * 10 + s[4] - 'a') * 60 +((s[6] - 'a') * 10 + s[7] - 'a');
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s, s1;
	cin >> s >> s1;
	int ans = get(s1) - get(s);
	if(ans >= 0) cout << ans;
	else cout << get(s) - get(s1);

	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	return 0;
}