#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(ll i=(a); i<(b); i++)
#define per(i, a, b) for(ll i=(b)-1; i>=(a); i--)
#define sz(a) (ll)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef double db;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<pii> vi;
ll n;
const ll N = 4000000 + 10;
ll cost[N], cnt[N], sum[N], num[N];
vi edge[N];
void pushup(ll l, ll r, ll rt){
	sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
	num[rt] = num[rt * 2] + num[rt * 2 + 1];
	return ;
}
void updata(ll l, ll r, ll pos, ll val, ll flag, ll rt){
	if(l == r){
		num[rt] += 1ll * flag * val;
		sum[rt] += 1ll *flag * val * pos;
		return ;
	}
	ll mid = (l + r) / 2;
	if(pos <= mid) updata(l, mid, pos, val, flag, rt * 2);
	else updata(mid + 1, r, pos, val, flag, rt * 2 + 1);
	pushup(l, r, rt);
	return ;
}
ll qry(ll l, ll r, ll val, ll rt){
	ll mid = (l + r) / 2;
	if(l == r){
	//	de(l);
		return min(num[rt], val / l);
	}
	ll ans = 0;
	if(sum[rt * 2] <= val) ans =  num[rt * 2] + qry(mid + 1, r, val - sum[rt * 2], rt * 2 + 1);
	else ans = qry(l, mid, val , rt * 2);
	pushup(l, r, rt);
	return ans;
}
ll dfs(ll rt, ll val){
	//dd(rt);de(val);
	updata(1, 1000000, cost[rt], cnt[rt], 1, 1);
	priority_queue<ll> q;
	while(!q.empty()) q.pop();
	for(auto i: edge[rt]){
		if(val - 2 * i.se >= 0)q.push(dfs(i.fi, val - 2 * i.se));
	}
	ll ans = qry(1, 1000000, val, 1);
	updata(1, 1000000, cost[rt], cnt[rt], -1, 1);
	if(rt == 1) return max(ans, q.top());
	if(q.size() >= 1) q.pop();
	if(q.size()) return max(ans, q.top());
	else return max(ans, 0ll);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	ll val;
	cin >> n >> val;
	rep(i, 1, n + 1){
		cin >> cnt[i];
	}
	rep(i, 1, n + 1){
		cin >> cost[i];
	}
	rep(i, 2, n + 1){
		ll x, val;
		cin >> x >> val;
		edge[x].pb(mp(i, val));
	}
	cout << dfs(1, val) << endl;
	return 0;
}