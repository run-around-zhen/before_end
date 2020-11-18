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
vi v,v1,v2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		v.clear();
		v1.clear();
		v2.clear();
		int n;
		cin >> n;
		if(n <= 3) cout << "-1" <<endl;
		else{
			v.pb(2);
			v.pb(4);
			v.pb(1);
			v.pb(3);
			int last = n - 4;
			int now = 5;
			while(last){
				if(last == 1) {
					v1.pb(now);
					break;
				}
				v1.push_back(now);
				now ++;
				v2.push_back(now);
				now ++ ;
				last -= 2;
			}
			per(i , 0, v1.size()){
				cout << v1[i] << " ";
			}
			for(auto i :v){
				cout << i << " ";
			}
			for(auto i :v2){
				cout << i << " ";
			}
			cout << endl;
		}
	}
	return 0;
}