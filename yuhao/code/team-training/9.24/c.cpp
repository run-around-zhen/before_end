#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int  i = (a); i < b; i ++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); i++)
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int b[1000000 + 10];
map<int, int>ma;
vi res;
int ans[1000000 + 10];
struct node{
	int l, r;
}a[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	int flag = 0;
	cin >> n;
	rep(i, 1, n + 1){
		cin >> a[i].l >> a[i].r;
	}
	int m;
	cin >> m;
	rep(i, 1, m + 1){
		cin >> b[i];
		ma[b[i]] = 1;
	}
	int j = 1;
	b[0] = 2e9;
	rep(i, 1, n + 1){
		int cnt = 0;
		if(j!= 1)j --;
		while(b[j] < a[i].l && j <= m) j ++;
		while(b[j] <= a[i].r && j <= m) {
			j ++;
			cnt ++;
		}
		ans[i] = cnt;
	//	cout << i << " " << cnt << endl;
		if(cnt > 2) flag = 1;
	}
	if(flag){
		cout << "impossible" << endl;
		return 0;
	}
	rep(i, 1, n){
		if(ans[i] == 2) continue;
		if(ans[i] == 0) res.pb(a[i].l + 1);
		if(ma[a[i].r] == 0 && ans[i + 1] < 2&& a[i].r == a[i + 1].l){
			ans[i + 1] ++;
			res.pb(a[i].r);
		}
		else{
			if(!ma[a[i].l + 2])res.pb(a[i].l + 2);
			else res.pb(a[i].l + 3);
		}
	}
	if(ans[n] == 0){
		res.pb(a[n]. l + 1);
		res.pb(a[n].l + 2);
	}
	else if(ans[n] == 1){
		if(!ma[a[n].l + 1]) res.pb(a[n].l + 1);
		else res.pb(a[n].l + 2);
	}
	if(flag == 1){
		cout << "impossible" << endl;
	}
	else{
		cout << res.size() << endl;
		for(auto i: res) cout << i << " ";
		cout << endl;
	}
	return 0; 
}
