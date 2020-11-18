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
int a[100][100], b[10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	rep(i, 1, 6){
		rep(j, 1, 6) cin >> a[i][j];
	}
	rep(i, 1, 6) b[i] = i;
	int ans = 0;
	do{
		int sum = 0;
		rep(i, 1, 6){
			rep(j, i, 6){
				sum += a[b[j]][b[j + 1]];
				sum += a[b[j + 1]][b[j]];
				j ++;
			}
		}
		ans = max(ans, sum);
		/*rep(i, 1, 6) {
			cout << b[i] << " " ;
		}
		cout << sum << endl;*/
	}while(next_permutation(b + 1, b + 6));
	cout << ans << endl;
	return 0;
}