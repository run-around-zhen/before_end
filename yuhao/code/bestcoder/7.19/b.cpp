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
double ans[1000];
double get(int x){
	if(x <= 59) return 0;
	if(x <= 61) return 1.0;
	if(x <= 64) return 1.7;
	if(x <= 66) return 2.0;
	if(x <= 69) return 2.3;
	if(x <= 74) return 2.7;
	if(x <= 79) return 3.0;
	if(x <= 84) return 3.3;
	if(x <= 89) return 3.7;
	if(x <= 94) return 4.0;
	return 4.3;
}
int main(){
	//ios::sync_with_stdio(false);
	////cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	rep(i, 0, 101){
		rep(j, 0, 101){
			rep(k, 0, 101){
				rep(z, 0, 101){
					ans[i + j + k + z] = max(ans[i + j + k + z], 1.0 * get(i) + get(j) + get(k) + get(z));
				}
			}
		}
	}
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		printf("%.1lf\n", ans[n]);
	}
	return 0;
}