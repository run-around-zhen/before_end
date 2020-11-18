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
struct node{
	int t, flag1, flag2;
}a[200000 + 10];
bool cmp(node a, node b){
	return a.t < b.t;
}
bool vis[200000 + 10];
vi v1, v2, v3, ans1, ans2, ans3, ans4;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int sum1 = 0, sum2 = 0, cnt1 = 0, cnt2 = 0;
	rep(i, 0, n){
		cin >> a[i].t >> a[i].flag1 >> a[i].flag2;
	}
	sort(a, a + n, cmp);
	rep(i, 0, n){
		if(a[i].flag1 == 1 && a[i].flag2 == 0 && cnt1 < k) {
			v1.pb(i);
			sum1 += a[i].t;
			cnt1++;
		}
		if(a[i].flag1 == 0 && a[i].flag2 == 1 && cnt2 < k) {
			v2.pb(i);
			sum2 += a[i].t;
			cnt2 ++;
		}
	}
	int ans = 2e9 + 1;
//	priorty_queue<pii, vector<pii>, greater<pii> > q;
	if(cnt1 == k && cnt2 == k) {
		ans = min(ans, sum1 + sum2);
		ans1 = v1;
		ans2 = v2;
	}
	//cout << cnt1 <<" " << cnt2 << " "<<ans << endl;
	int tot = 0;
	rep(i, 0, n){
		if(a[i].flag1 == 1 && a[i].flag2 == 1){
			cnt1 ++;
			cnt2 ++;
			tot += a[i].t;
			if(cnt1 > k && v1.size() != 0){
				sum1 -= a[v1[v1.size() - 1]].t;
				//q.push(mp(a[v1[v1.size() - 1]].t, v1[v1.size() - 1]));
				v1.pop_back();
			}
			if(cnt2 > k && v2.size() != 0){
				sum2 -= a[v2[v2.size() - 1]].t;
				//q.push(mp(a[v1[v1.size() - 1]].t)	
				v2.pop_back();
			}
			v3.pb(i);
			if(cnt1 >= k && cnt2 >= k) {
				//ans = min(ans, sum1 + sum2 + tot);
				if(ans >= sum1 + sum2 + tot && v1.size() + v2.size() + v3.size() <= m) {
					ans1.clear();
					ans2.clear();
					ans3.clear();
					ans1 = v1;
					ans2 = v2;
					ans3 = v3;
					ans = sum1 + sum2 + tot;
					cout << v1.size() << " " << ans1.size() << endl;
				}
			}
		}
		//cout << cnt1 << " " << cnt2 << endl;
	}
	cout << ans << " " << v1.size() + v2.size() + v3.size() << endl;
	if(ans == 2e9 + 1) cout << "-1" << endl;
	else {
		for(auto i:ans1) vis[i] = true;
		for(auto i:ans2) vis[i] = true;
		for(auto i:ans3) vis[i] = true;
		int cc = 0;
		cout << ans1.size() << " " << ans2.size() << " " << ans3.size() << endl;
		rep(i, 0, n){
			if(cc + ans1.size() + ans2.size() + ans3.size() == m) break;
			if(vis[i]) continue;
			ans += a[i].t;
			ans4.pb(i);
			cc ++;
		}
		cout << ans << endl;
		for(auto i:ans1) cout << i << " ";
		for(auto i:ans2) cout << i << " ";
		for(auto i:ans3) cout << i << " ";
		for(auto i:ans4) cout << i << " ";
	}
	return 0;
}