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
int a[1000000 + 10], num[1000000 + 10];
map<int, int> l, r;
struct segtree{
	void pushup(int l, int r, int rt){
		num[rt] = min(num[rt * 2], num[rt * 2 + 1]);
	}
	void build(int l, int r, int rt){
		if(l == r) {
			num[rt] = a[l];
			return ;
		}
		int mid = (l + r) / 2;
		build(l, mid, rt * 2);
		build(mid + 1, r ,rt * 2 + 1);
		pushup(l, r, rt);
	}
	int qry(int l, int r, int ql, int qr, int rt){
		if(l >= ql && r <= qr){
			return num[rt];
		}
		int mid = (l + r) / 2;
		int ans = 1e9;
		if(ql <= mid) ans = min(ans, qry(l, mid , ql, qr, rt * 2));
		if(qr > mid) ans = min(ans, qry(mid + 1, r ,ql, qr, rt * 2+ 1));
		pushup(l, r, rt);
		return ans;
	}
}seg;
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		rep(i, 1, n + 1) cin >> a[i];
		seg.build(1, n, 1);
		l.clear();
		r.clear();
		rep(i, 1, n + 1){
			if(!l[a[i]]) l[a[i]] = i;
		}
		per(i, 1, n + 1){
			if(!r[a[i]]) r[a[i]] = i;
		}
		priority_queue<pii, vector<pii>, greater<pii> > ql;
		priority_queue<pii> qr;
		for(auto i : l){
			ql.push(mp(i.se, i.fi));

		}
		for(auto i : r){
			qr.push(mp(i.se, i.fi));
			
		}
		int maxnl = -1, maxnr = -2;
		int l = 0, r = n;
		int flag = 0;
		// while(!ql.empty()){
		// 	pii x = ql.top();
		// 	dd(x.fi);de(x.se);
		// 	ql.pop();
		// }
		// while(!qr.empty()){
		// 	pii x = qr.top();
		// 	dd(x.fi);de(x.se);
		// 	qr.pop();
		// }
		int ansx, ansy;
		while(!ql.empty() && !qr.empty()){
			int idl, idr, x, y;
			while(!ql.empty() && !qr.empty()){
				x = ql.top().se;
				idl = ql.top().fi;
				y = qr.top().se;
				idr = qr.top().fi;
				//dd(x);dd(y);
				maxnl = max(maxnl, x);
				maxnr = max(maxnr, y);
				//dd(maxnl);de(maxnr);
				l = idl + 1;
				r = idr - 1;
				if(maxnl < maxnr) ql.pop();
				else if(maxnr < maxnl) qr.pop();
				else break;
			}
			// dd(x);
			// dd(y);
			// dd(maxnl);
			// de(maxnr);
			if(idr <= idl) break;
			while(!ql.empty()){
				int xx = ql.top().se;
				if(xx > maxnl) {
					l = ql.top().fi;
					break;
				}
				ql.pop();
			}
			while(!qr.empty()){
				int xx = qr.top().se;
				if(xx > maxnr) {
					r = qr.top().fi;
					break;
				}
				qr.pop();
			}
			//dd(l);de(r);
			if(ql.size() == 0) l =n;
			if(qr.size() == 0) r = 1;
			//dd(l);de(r);
			if(l <= r){
				if(seg.qry(1, n, l, r, 1) == maxnr){
					flag = 1;
					ansx = l - 1;
					ansy = r  - l + 1;
					break;
				}
				if(l - 1 > idl){
					if(seg.qry(1, n, l - 1, r, 1) == maxnr){
						flag = 1;
						ansx = l - 2;
						ansy = r  - (l - 1) + 1;
						break;
					}
				}
				if(r + 1 < idr){
					if(seg.qry(1, n, l, r + 1, 1) == maxnr){
						flag = 1;
						ansx = l - 1;
						ansy = r + 1  - l + 1;
						break;
					}
				}
			}
			else{
				rep(i, idl + 1, idr){
					if(a[i] == maxnl) {
						flag = 1;
						ansx = i -1;
						ansy = 1;
						break;
					}
				}
			}
			// ql.pop();
			// qr.pop();
		}
		// int maxnl = -1, maxnr = - 1;
		// int l = 1, r = n;
		// while(l <= r){
		// 	maxnl = max(maxn, a[l]);
		// 	maxnr = max(maxn, a[r]);
		// 	while(maxnl != maxnr && l <= r){
		// 		if(maxnl < maxnr) l ++;
		// 		else if(maxnr < maxnl) r ++;
		// 		maxnl = max(maxnl, a[l]);
		// 		maxnr = max(maxnr, a[r]); 
		// 	}

		// }
		if(flag){
			cout << "YES" << endl;
			cout << ansx << " " << ansy <<" "<< n - ansx - ansy << endl;
		}
		else{
			cout << "NO" << endl;
		}
	//	cout << flag << endl;
	}
	return 0;
}