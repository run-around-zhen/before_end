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
vi res;
int a[100000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		cin >> a[i];
	}
	per(i, 0, 31){
		int x = 1 << i;
		int last = x - 1;
		rep(j, 1, n + 1){
			if(a[j] & x){
				res.pb(a[j]);
				last &= a[j];
			}
		}
		if(!last){
			cout << res.size() << endl;
				for(auto k : res){
					cout << k << " ";
				}
				return 0;
			}
			res.clear();
	}
	return 0;
}