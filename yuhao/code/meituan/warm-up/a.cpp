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
	string s = "713486295249357861856219473675948132428731956391625784182593647937164528564872319";
	int cnt = 0;
	rep(i, 1, 10){
		rep(j, 1, 10){
			cout << s[cnt] << " " ;
			cnt ++;
		}
		cout << endl;
	}
	return 0;
}