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
int a[1000000 + 10], b[1000000 + 10];
int main(){
	srand(time(0));
	int start = clock();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	if(n >= 30){
		cout << "1" << endl;
		return 0;
	}
	int ans = n;
	while((1.0 * clock() - start)/CLOCKS_PER_SEC <1.98){
		rep(i, 1, n + 1) b[i] = a[i];
		int num = n;
		while(1){
			if(num == 1) break;
			int pos = rand() % (num - 1)+ 1;
			// rep(i, 1, num + 1){
			// 	cout << b[i] << " ";
			// }
			// cout << endl;
			b[pos] = b[pos] ^ b[pos + 1];
			rep(i, pos + 1, num){
				b[i] = b[i + 1];
			}
			num --;
			// rep(i, 1, num + 1){
			// 	cout << b[i] << " ";
			// }
			// cout << endl;
			rep(i, 1, num){
				if(b[i] > b[i + 1]){
					ans = min(ans, n - num);
					break;
				}
			}
		}
	}
	if(ans != n) cout << ans << endl;
	else cout <<"-1" << endl;
	return 0;
}