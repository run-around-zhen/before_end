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
char a[100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	string s ="";
	rep(i, 0, 10) cin >> a[i];
	rep(i, 0, 10){
		rep(j, i + 1, 10){
			if(a[i] == a[j]) s+= "1";
			else s+= "0";
		}
	}
	string s1;
	cin >> s1;
	int cnt =0 ;
	rep(i, 0, 45){
		if(s[i] != s1[i]) cnt ++;
	}
	cout << s <<endl << s1 << endl;
	cout << cnt << endl;
	return 0;
}