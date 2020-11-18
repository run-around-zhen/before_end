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
const int mod = 998244353;
const int mod1 = 1e9 + 7;
const int bas1 = 19260817;
const int bas = 19491001;

int hash1 = 0;
int hash2 = 0;
const int MAXN = 5e5 + 10;
int sum[MAXN], l[MAXN], r[MAXN], id[MAXN], a[MAXN];
int base[MAXN + 10][3];
pii ha[MAXN];
map<pii, int>cnt;
int add(int a, int b){
//	if(a + b >= mod) return a + b - mod;
	return (a + b)%mod;
}
int add1(int a, int b){
	// if(a + b >= mod1) return a + b - mod1;
	return (a + b)%mod1;
}
int mul(ll a, ll b){
	return (ll)a * b % mod;
}
int mul1(ll a, ll b){
	return (ll)a * b % mod1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	srand(time(0));
	int n;
	cin >> n;
	base[0][0] = base[0][1] = 1;
	rep(i, 1, MAXN) {
		id[i] = i;
		base[i][0] = (ll)base[i - 1][0] * bas % mod;
		base[i][1] = (ll)base[i - 1][1] * bas1 % mod1;
	}
	random_shuffle(id + 1 ,id + MAXN);
	cnt[mp(0, 0)] = 1;
	int j = 0;
	ll ans = 0;
	ha[0] = mp(0, 0);
	rep(i ,1, n + 1){
		cin >> a[i];
		hash1 = add(hash1, - mul(base[a[i]][0], sum[id[a[i]]]) + mod);
		hash2 = add1(hash2, - mul1(base[a[i]][1], sum[id[a[i]]]) + mod1);
		sum[id[a[i]]] = (sum[id[a[i]]] + 1) % 3;
		hash1 = add(hash1, mul(base[a[i]][0], sum[id[a[i]]]));
		hash2 = add1(hash2, mul1(base[a[i]][1], sum[id[a[i]]]));
		ha[i] = mp(hash1, hash2);
		l[a[i]] ++;
		while(l[a[i]] - r[a[i]] > 3){
			cnt[ha[j]] --;
			j ++;
			r[a[j]] ++; 
		}
		ans += cnt[mp(hash1, hash2)];
		cnt[mp(hash1, hash2)] ++;
 	}
 	cout << ans << endl;
	return 0;
}