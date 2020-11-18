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
map<ll, int> ans;
ll a[1000000 + 10];
ll sum[5050][5050];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1) {
		cin >> a[i];
		a[i] ++;
	}
	rep(i, 1, n + 1){
		rep(j, 1, n + 1) sum[i][j] = sum[i - 1][j];
		rep(j, 1, a[i]) sum[i][j] ++;
	}
	rep(i, 1, n + 1){
		rep(j, 1, i){
			ans[(sum[j][a[j]] + sum[i][a[i]] - sum[i][a[j]] - sum[j][a[i]]) * 2 + 1] ++;
		}
	}
	ll res = 0;
	rep(i, 1, n + 1){
        res += sum[i][a[i]];
    }
    /*for(auto i :ans){
    	cout << i.fi << " " << i.se << endl;
    }*/
    auto i = ans.end();
    i --;
    cout << res - (*i).fi <<" " << (*i).se << endl;
	return 0;
}