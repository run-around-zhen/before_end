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
	int a, b, id, flag;
}num[100000 + 10];
vector<node> v, v1;
bool cmp(node a, node b){
	if(a.flag != b.flag) return a.flag < b.flag;
	return a. a > b. a || (a.a == b.a && a.b > b.b);
}
bool cmp1(node a, node b){
	return a.b < b.b || (a.b == b.b && a.a < b. a);
}
bool cmp2(node a, node b){
	if(a.flag != b.flag) return a.flag > b. flag;
	if(a.b > b. b)return true;
	if(a.a < b. a) return true;
	return a.flag > b. flag;
	/*if(a.flag != b.flag){
		return a.flag > b.flag;
	}
	return a.b > b. b ||(a.b == b.b && a. a < b. a);*/
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
		num[i].flag = 0;
	}
	sort(num + 1, num + 1 + n, cmp2);
	rep(i, k + 1, n + 1){
		num[i].flag = 1;
	}
	sort(num + 1, num + 1 + n, cmp);
	rep(i, 1, k + 1){
		num[i].flag = 2;
	}
	sort(num + 1, num + 1 + n, cmp2);
	rep(i, 1, p + 1){
	//	cout << num[i].id << " ";
		dd(num[i].id);de(num[i].flag);
	}
	return 0;
}