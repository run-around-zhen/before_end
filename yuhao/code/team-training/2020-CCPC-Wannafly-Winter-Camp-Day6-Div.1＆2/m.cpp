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
int ma[100 + 10][10 + 10];
vector<int> v[100 + 10][10 + 10];
struct node{
	int flag, flag1;
}a[110];
int res[110];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	while(k --){
		int x, y, c;
		cin >> x >> y >> c;
		a[x].flag1 = 1;
		if(c){
			a[x].flag = 1;
			if(!ma[x][y]) ma[x][y] = 1;
		}
		//v[x].pb(mp(y, c));
		v[x][y].pb(c);
	}
	rep(i, 1, m + 1){
		rep(j, 1, n + 1){
			if(ma[j][i]) res[i] ++;
		}
	}
	rep(i, 1, n + 1){
		int sum = 0;
		rep(j, 1, m + 1) {
			if(ma[i][j]) sum ++;
		}
		int tot = 0;
		if(a[i].flag1 == 0) {
			cout << "998244353" << endl;
		}
		else if(a[i].flag == 0) {
			cout << "1000000" << endl;
		}
		else if(sum == m){
			cout << "0" << endl;
		}
		else {
			int cnt = 0;
			rep(j, 1, m + 1){
				if(ma[i][j] == 0 && res[j] >= 1) cnt += 20;
				if(ma[i][j] == 0 && res[j] >= n / 2) cnt += 10;
			}
			rep(j, 1, m + 1){
				int sum = 0, maxn = 0;
				rep(t, 0, v[i][j].size()){
					if(v[i][j][t] == 0){
						sum ++;
						maxn = max(maxn, sum);
					}
					else {
						sum = 0;
					}
				}
				if(ma[i][j]) cnt += maxn * maxn;
				else cnt += maxn * maxn + maxn * maxn;
			}
			cout << cnt << endl;
		}

	}
	return 0;
}