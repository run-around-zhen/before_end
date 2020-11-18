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
string s;
int check(int i){
	int sum = 0;
	rep(j, 0, i){
		if(s[j] == '0') sum++;
	}
	rep(j, i, s.size()){
		if(s[j] == '1') sum++;
	}
	return sum;
}
int check1(int i){
	int sum = 0;
	rep(j, 0, i){
		if(s[j] == '1') sum++;
	}
	rep(j, i, s.size()){
		if(s[j] == '0') sum++;
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		
		cin >> s;int ans = s.size();
		rep(i, 0, s.size()){
			//cout <<check1(i) << " ";
			ans = min(ans, check(i));
			ans = min(ans, check1(i));
		}
		cout << ans << endl;
	}

	return 0;
}