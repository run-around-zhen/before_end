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
int a[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(n % 2 == 1){
			int cnt = 0;
			int tt = 2;
			while(cnt < n){
				rep(i, 1, tt / 2 + 1){
					cnt ++ ;
					a[((n + 1)/tt )* i] = cnt;
					if(cnt > n) break;
 				}
 				tt *= 2;
			}
			rep(i, 1, n + 1) cout << a[i] << " ";
			cout << endl;
		}
	}
	return 0;
}