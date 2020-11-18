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
struct node{
	int h, pos;
}a[1000000 + 10];
bool cmp(node a, node b){
	return a.pos < b.pos;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		cin >> a[i].pos >> a[i].h;
	}
	int ans = 0;
	sort(a + 1, a + 1 + n, cmp);
	a[n + 1].pos = 2e9 + 1;
	int last = -2e9;
	rep(i, 1, n + 1){
		if(a[i].pos - a[i].h > last){
			ans ++ ;
			last = a[i].pos;
		}
		else if(a[i].pos + a[i].h < a[i + 1].pos){
			ans ++;
			last = a[i].pos + a[i].h;
		}
		else{
			last = a[i].pos;
		}
		//cout << ans <<endl;
	}
	cout << ans << endl;
	return 0;
}