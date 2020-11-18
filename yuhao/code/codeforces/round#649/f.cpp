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
map<int ,int >cnt;
map<map<int, int>, int >ma;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	rep(k,3, 2049){
		rep(i, 0, n){
			cnt.clear();
			rep(j, 0, n){
				if(i == j) continue;
				cnt[(i | j )] ++;
			}
			int flag = 0;
			ma[cnt] ++;
			if(ma[cnt] > 1){
				cout <<"fack" << endl;
				return 0;
			}
		//cout << endl;
		}
		cout <<"ok" << " " << k <<endl;
		ma.clear();
	}
	return 0;
}