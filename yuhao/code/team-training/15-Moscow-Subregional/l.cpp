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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int flag = 0;
	rep(i, 1, n + 1){
		cin >> a[i].l >> a[i].r;
		if(a[i]. r - a[i].l >= 90) flag = 1;
	}
	sort(a + 1, a + 1 + n, cmp);
	int l = -1;
	rep(i, 1, n + 1){
		if(l == -1) l = a[i].r - 90;
		else {
			if(a[i]. r - l <= 180) continue;
			if(a[i].l - l <= 90){
				flag = 1;
				break;
			}
			else{
				l = a[i].r - 90;
			}
		}
	}
	return 0;
}