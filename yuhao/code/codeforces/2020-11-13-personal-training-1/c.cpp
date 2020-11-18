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
	int a, b, id;
}num[100000 + 10];
vector<node> v, v1;
bool cmp(node a, node b){
	return a. a > b. a || (a.a == b.a && a.b > b.b);
}
bool cmp1(node a, node b){
	return a.b < b.b || (a.b == b.b && a.a > b. a);
}
bool cmp2(node a, node b){
	return a.b > b. b ||(a.b == b.b && a. a < b. a);
}
bool cmp3(node a, node b){
	return a.b < b. b ||(a.b ==b.b && a.a > b.a);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, p, k;
	cin >> n >> p >> k;
	rep(i, 1, n + 1){
		cin >> num[i].a >> num[i].b;
		num[i].id = i;
	}
	sort(num + 1, num + 1 + n, cmp1);
	sort(num + 1 + p - k, num + n + 1, cmp);
	int maxn = 2e9;
	rep(i, p - k + 1, p + 1){
		maxn = min(maxn, num[i].b);
	}
	rep(i, 1, n + 1){
		if(i >= p - k  + 1&& i <= p) continue;
		if(num[i].b >= maxn) {
			v1.pb(num[i]);
			continue;
		}
		v.pb(num[i]);
	}
	sort(all(v), cmp2);
	/*for(auto i : v){
		de(i.id);
	}*/
	sort(all(v1), cmp3);
	rep(i, p - k + 1, p + 1){
		cout << num[i].id << " ";
	}
	rep(i, 0, min(sz(v),p - k)){
		cout << v[i].id << " ";
	}
	rep(i, min(sz(v), p - k), p - k){
		cout << v1[i - min(sz(v), p - k)].id << " ";
	}
	return 0;
}