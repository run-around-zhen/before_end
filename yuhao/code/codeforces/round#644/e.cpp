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
string s[100];
int n, m ;
bool check(string ss){
	rep(i, 0, n){
		int sum = 0;
		rep(j, 0, m){
			if(ss[j] != s[i][j]) sum ++;
		}
		if(sum > 1) return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		
		cin >> n >> m;
		rep(i, 0, n){
			cin >> s[i];
		}
		int flag = 0;
		rep(i, 0, n){
			rep(k, 0, m){
				rep(j, 0, 26){
					string ss = s[i];
					ss[k] = (char)(j + 'a');
					if(check(ss)){
						cout << ss << endl;
						flag = 1;
						break;
					}
				}
				if(flag) break;
			}if(flag) break;
		}
		if(!flag){
			cout << "-1" << endl;
		}
	}
	return 0;
}