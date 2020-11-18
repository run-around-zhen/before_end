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
int a[100000 + 10];
vi v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		v.clear();
		rep(i, 1, n + 1) cin >> a[i];
		v.pb(a[1]);
		v.pb(a[2]);
		rep(i, 3, n + 1){
			if(a[i] > a[i - 1] && a[i - 1] > a[i - 2] || a[i] < a[i - 1] && a[i - 1] < a[i - 2]){
				v.pop_back();
				v.pb(a[i]);
			}
			else {
				v.pb(a[i]);
			}
		}
		cout << v.size() << endl;
		for(auto i:v){
			cout <<i  << " ";
		}
		cout << endl;
	}
	return 0;
}