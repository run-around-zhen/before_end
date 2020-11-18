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
const int N = 200000 + 20;
map<int,int> a, b;
int xx[400000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int x;
	int ct = 0;
	rep(i, 1, n + 1){
		cin >> x;
		a[x] ++;
		xx[ct ++] = x;
	}
	int m;
	cin >> m;
	rep(i, 1, m + 1){
		cin >> x;
		b[x] ++ ;
		xx[ct ++] = x;
	}
	xx[ct ++] = 0;
	sort(xx, xx + ct);
	ct = unique(xx, xx + ct) - xx;
	int ans = -1e9;
	int res1 = -1e9, res2 = -1e9;
	int sum = 0 ,sum1 = 0 ;
	rep(i, 0, ct) {
		sum += a[xx[i]];
		sum1 += b[xx[i]];
		int cnt1 = sum * 2 + (n - sum) * 3;
		int cnt2 = sum1 * 2 + (m - sum1) * 3;
		//cout << cnt1 << " " << cnt2 << xx[i] << endl;
		if(cnt1 - cnt2 > ans){
			ans = cnt1 - cnt2;
			res1 = cnt1;
			res2 = cnt2;
		}
		else if(cnt1 - cnt2 == ans && res1 < cnt1){
			res1 = cnt1;
			res2 = cnt2;
		}
	}
	cout << res1 << ":"<< res2 << endl;
	return 0;
}