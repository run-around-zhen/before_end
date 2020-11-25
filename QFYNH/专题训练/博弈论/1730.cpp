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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, m;
	while(cin >> n >> m){
		int ans = 0;
		rep(i, 1, n + 1){
			int l, r;
			cin >> l >> r;
			if(l > r) swap(l, r);
			ans ^= (r - l - 1);
		}
		if(ans){
			cout << "I WIN!" << endl;
		}
		else{
			cout << "BAD LUCK!" << endl;
		}
	}
	return 0;
}