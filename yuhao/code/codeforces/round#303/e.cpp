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
int a[110][110],flag[110];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		rep(j, 1, n + 1){
			cin >> a[i][j];
			if(a[i][j] == 1) flag[i] = true;
			if(a[i][j] == 2) flag[j] = true;
			if(a[i][j] == 3) {
				flag[i] = true;
				flag[j] = true;
			}
		} 
	}
	int ans = 0;
	rep(i, 1, n + 1) if(!flag[i] ) ans ++;
	cout << ans << endl;
	rep(i, 1, n + 1) if(!flag[i]) cout << i << " ";
	return 0;
}