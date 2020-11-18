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
	int n;
	cin >> n;
	string s[1000];
	rep(i, 0, n){
		cin >> s[i];
	}
	int ans = 0;
	rep(i, 0, 26){
		rep(j, 0 ,26){
			int sum = 0;
			rep(k, 0, n){
				int flag = 0;
				rep(t, 0, s[k].size()){
					if(s[k][t] - 'a' != i && s[k][t] - 'a' != j){
						flag = 1;
						break;
					}
				}
				if(!flag){
					sum += s[k].size();
				}
			}
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
	return 0;
}