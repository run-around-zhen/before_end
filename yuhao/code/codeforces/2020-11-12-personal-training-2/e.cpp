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
int cnt1[100000 + 10], cnt2[100000 + 10], sum1[100000 + 10], sum2[100000 + 10];
vi ans, va, vb;
bool cmp(int a ,int b){
	return a > b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n + 1) {
		int x;
		cin >> x;
		x %= m;
		cnt1[x] ++;
		sum1[i] = cnt1[i] + sum1[i - 1];
	}
	rep(i ,1, n + 1){
		int x;
		cin >> x;
		x %= m;
		cnt2[x] ++;
		sum2[i] = sum2[i - 1] + cnt2[i];
	}
	/*per(i, 0, m){
		rep(j, 0, m){
			int tmp = min(cnt1[j], cnt2[(i - j + m) % m]);
			cnt1[j] -= tmp;
			cnt2[(i - j + m) % m] -= tmp;
			while(tmp) {
				ans.pb(i);
				tmp --;
			}
		}
	}*/
	rep(i, 0, m){
		rep(j, 0, cnt1[i]) va.pb(i);
		rep(j, 0, cnt2[(m - i - 1 + m) % m]){
			if(sz(va)){
				ans.pb((va[va.size() - 1] + m - i - 1) % m);
				//dd(i);
				//dd(m - i - 1);
				va.pop_back();
			}
			else{
				vb.pb(m - i - 1);
			}
		}
	}
	rep(i, 0, sz(va)) ans.pb((va[i] + vb[(int)va.size() - 1 - i]) %m);
	sort(all(ans), cmp);
	for(auto i : ans) cout << i << " ";
	return 0;
}