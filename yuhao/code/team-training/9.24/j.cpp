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
struct Matri{
	ll a[2][2];
}b[4000000 + 10];
ll d[1000000 + 10];
struct node{
	ll val, id, flag;
}e[1000000 + 10];
Matri operator +(Matri a, Matri b){
	Matri c;
	rep(i, 0, 2){
		rep(j, 0, 2){
			c.a[i][j] = 1e18;
			rep(k, 0, 2){
				c.a[i][j] = min(a.a[i][k] + b.a[k][j], c.a[i][j]);
			}
		}
	}
	return c;
}
void build(int l, int r, int rt){
	if(l == r){
		b[rt].a[0][0] = b[rt].a[1][1] = 1;
		b[rt].a[0][1] = b[rt].a[1][0] = 1e18;
		return ;
	}
	int mid = (l + r) / 2;
	build(l, mid, rt * 2);
	build(mid + 1, r, rt * 2 + 1);
	b[rt] = b[rt * 2] + b[rt * 2 + 1];
}
void updata(int l, int r, int pos,int val, int rt){
	if(l == r){
		if(val == 0){
			b[rt].a[1][0] = 0;
		}
		else if(val == 1){
			b[rt].a[0][1] = 0;
		}
		return ;
	}
	int mid = (l + r) / 2;
	if(pos <= mid) updata(l, mid, pos, val, rt * 2);
	else updata(mid + 1, r, pos, val, rt * 2 + 1);
	b[rt] = b[rt * 2] + b[rt * 2 + 1];
}
bool cmp(node a, node b){
	return a.val < b.val;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n, c, r;
    cin >> n >> c >> r;
    rep(i, 1, n + 1) {
    	cin >> d[i];
    	e[i].val = max(0ll, 1 - d[i]);
    	e[i].id = i;
    	e[i].flag = 0; // zheng
    	e[n + i].val = max(0ll, d[i] + 1);
    	e[n + i].id = i;
    	e[n + i].flag = 1;
    }
    sort(e + 1, e + 1 + 2 * n, cmp);
    build(1, n, 1);
    ll ans = n * r;
    rep(i, 1, 2 * n + 1){
    	updata(1, n, e[i].id, e[i].flag,  1);
    	ans = min(ans, min(min(b[1].a[0][0], b[1].a[1][1]), min(b[1].a[0][1], b[1].a[1][0])) * r + e[i].val * c); 
    }
    cout << ans;

} 