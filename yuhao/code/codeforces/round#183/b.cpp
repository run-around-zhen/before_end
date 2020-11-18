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
int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int cal(string s){
	int year = (s[0] - '0' ) * 1000 + (s[1] - '0' ) * 100 + (s[2] - '0' ) * 10 + (s[3] - '0' ) ;
	int mouth = (s[5] - '0' ) * 10 + (s[6] - '0' ) ;
	int day = (s[8] - '0' ) * 10 + (s[9] - '0' ) ;
	int ans = 0;
	rep(i, 1900, year) {
		if(i % 4 == 0 && i != 1900) ans += 366;
		else ans += 365;
	}
	rep(i, 0, mouth - 1){
		ans += a[i];
		if(i == 1 && year % 4 == 0 && year != 1900) ans ++;
	}
	return ans + day;

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s, s1;
	cin >> s >> s1;
	cout << abs(cal(s1) - cal(s))  << endl;
	return 0;
}