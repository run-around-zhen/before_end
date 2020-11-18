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
	string s, t;
	cin >> s >> t;
	int len = s.size();
	int ans = 0;
	rep(i, 0, len){
		if(s[i] != t[i]) ans ++ ;
	}
	if(ans % 2 == 0){
		int last = ans / 2;
		int t1 = 0,t2 = 0;
		rep(i, 0, len){
			if(s[i] != t[i]){
				if(t1 < t2){
					cout << s[i];
					t1 ++;
				}
				else{
					cout << t[i];
					t2 ++;
				}
			}
			else{
				cout << s[i];
			}
		}
	}
	else{
		cout << "impossible";
	}
	return 0;
}