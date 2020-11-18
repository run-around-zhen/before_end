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
struct node{
	double val;
	int id;
}a[100000 + 10];
const double eps=1e-7;
bool cmp(node a, node b){
	return a.val > b.val||(fabs(a.val - b.val)<eps && a.id > b.id);
}
double h[100000 + 10];
bool vis[100000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(8);
	int n, k;
	cin >> n >> k;
	n ++;
	rep(i, 1, n + 1) cin >> h[i];
	rep(i, 1, k + 1){
		memset(vis, false, sizeof(vis));
		double g;
		cin >> g;
		g = g * 10 ;
		rep(i, 1, n + 1){
			a[i].val = 1.0 * h[i] - g * i;
			a[i].id = i;
		}
		sort(a + 1, a + 1 + n, cmp);
	/*	rep(i, 1, n + 1){
			cout << a[i].id << " " << a[i].val << endl;
		}*/
		//return 0;
		double ans = 0;
		int minn = 1;
		rep(k, 1, n + 1){
			while(vis[minn]) minn ++;
			//if(minn >n)break;
			if(a[k].id > minn) {
				ans = max(ans, (double)a[k].id - minn);
				if(minn == 1) ans = max(ans, (double)a[k].id - minn);
				else {

					int j = a[k].id, i = minn;
					ans = max(ans, 1.0 * a[k].id - minn + minn - (h[j] - h[i] - g * j + 1.0 * i * (h[i] - h[i - 1])) / (h[i] - h[i - 1] - g));
				}
			}
			vis[a[k].id] = true;
		}
		memset(vis, false, sizeof(vis));
		minn = n;
		per(k, 1, n + 1){
			while(vis[minn]){
				minn --;
			}
			if(a[k].id < minn){
				ans = max(ans, (double)minn - a[k].id);
				if(minn == n) ans = max(ans, (double)minn - a[k].id);
				else{
					int j = a[k].id, i = minn;
					ans = max(ans, 1.0 * minn - a[k].id + 1.0*(h[j] - h[i] - g * j + 1.0 * i *(h[i + 1] - h[i])) / (h[i + 1] - h[i] - g) - i);
				}
 			}
 			vis[a[k].id] = true;
		}
		if(ans == 0){
			cout << "-1" << endl;
		}
		else{
			cout << ans << endl;
		}
	}
	return 0;
}