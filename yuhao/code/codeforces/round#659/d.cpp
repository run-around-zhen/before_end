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
int a[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int ans = 0;
		rep(i, 1, n + 1) {
			cin >> a[i];
			ans ^= a[i];
		}
		if(ans == 0){
			cout << "DRAW" << endl;
			continue;
		}
		per(i, 0, 32){
			int cnt = 0;
			rep(j, 1, n + 1){
				if(a[j] >> i & 1) cnt ++;
			}
			if(cnt % 2 == 0){
				continue;
			}
			else{
				if(cnt % 4 == 1){
					cout << "WIN" << endl;
					break;
				}
				if( cnt % 4 == 3){
					if((n - cnt) % 2 == 1)cout << "WIN" << endl;
					else{
						cout << "LOSE" << endl;
					}
				}
				
				break;
			}

		}

	}
	return 0;
}