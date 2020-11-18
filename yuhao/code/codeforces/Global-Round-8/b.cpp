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
ll num[100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll k ;
	string s = "codeforces";
	cin >> k;
	rep(i, 0, 10) num[i] = 1;
	if(k == 1){
		cout <<s << endl;
		return 0;
	}
	ll ans = 1;
	rep(i, 1, 10000){
		rep(j, 0, 10){
			ans = ans / num[j] * ( num[j] + 1);
			num[j] ++;
			if(ans >= k){
				rep(t, 0, 10){
					rep(q, 0, num[t]){
						cout << s[t];
					}
				}
				return 0;
			}
		}
	}
	return 0;
}