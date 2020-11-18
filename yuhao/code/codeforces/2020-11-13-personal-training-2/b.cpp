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
int num = 1;
struct node{
	int l, r;
}a[110];
bool vis[110];
int flag = 0;
void dfs(int l, int r, int op){
	//dd(l);de(r);
	//vis[i] = true;
	rep(i, 1, num){
		if(vis[i]) continue;
//		vis[i] = true;
		if(a[i].l < l && a[i].r > r){
			vis[i] = true;
			if(i == op){
				flag = 1;
				return;
			}
			dfs(a[i].l, a[i]. r, op);
		}
		if(l < a[i].r && l > a[i].l){
			vis[i] = true;
			if(i == op){
				flag = 1;
				return;
			}
			dfs(a[i].l, max(a[i].r, r), op);
		}
		  if(r < a[i].r && r > a[i].l){
			vis[i] = true;
			if(i == op){
				flag = 1;
				return;
			}
			dfs(min(a[i].l, l),a[i].r, op);
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		int op;
		cin >> op;
		int l, r;
		cin >> l >> r;
		if(op == 1) {
			a[num].l = l;
			a[num].r = r;
			num ++;
		}
		else{
			memset(vis, false, sizeof(vis));
			vis[l] = true;
			flag = 0;
			//dfs(a[l].l, a[l].r, r);
			//if(a[r].l > a[l].l && a[r].r < a[l].r) flag = 1;
			//if(a[l].l > a[r].l && a[l].r < a[r].r) flag = 1;
			if(flag){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}