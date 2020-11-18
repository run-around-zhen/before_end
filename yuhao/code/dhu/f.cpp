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
	while(T--){
		int n;
		cin >> n;
		int ans1 = 0;
		rep(i, 1, n + 1){
			string s;
			cin >> s;
			int sum = 0;
			rep(j, 0, s.size()){
				if(s[j] == '1') sum ++;
			}
			if(sum % 2 == 1) ans1 ++;
		}
		if(ans1){
			cout << "sdzNB" << endl;
		}
		else{
			cout << "kgNB" << endl;
		}
	}
	return 0;
}