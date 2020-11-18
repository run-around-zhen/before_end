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
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int a, b, c;
		cin >> a >> b >> c;
		if(b % 2 == 0 && b){
			rep(i, 0, c) cout <<"1";
			int flag = 1;
			rep(i, 0, b + 1){
				if(flag) cout << "1";
				else cout <<"0";
				flag ^= 1;
				if(i == 0){
					rep(j, 0, a) cout <<"0";
				}
			}
			cout << endl;
			continue;
		}
		if(a != 0){
			rep(i, 0, a + 1){
				cout << "0";
			}
		}
		int flag = 1;
		if(a != 0) flag = 1;
		else if(b != 0)cout <<"0";
		rep(i, 0, b){
			if(flag) cout << "1";
			else cout <<"0";
			flag ^= 1;
		}
		if(b != 0 && !flag){
			rep(i, 0, c) cout << "1";
		}
		else{
			if(c) rep(i, 0, c + 1) cout << "1";
		}
		cout << endl;
	}
	return 0;
}