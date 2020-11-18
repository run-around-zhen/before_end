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
int a[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		rep(i, 1, n + 1) cin >> a[i];
		int cnt = 0;
		rep(i, 1, n + 1){
			if(a[i] != i) cnt++;
		}
		if(cnt == 0){
			cout << "0" << endl;
			continue;
		}
		int pos = n + 1, pos1 = 0;
		rep(i, 1, n + 1){
			if(a[i] != i) {
				pos = i;
				break;
			}
		}
		per(i, 1, n + 1){
			if(a[i] != i){
				pos1 = i;
				break;
			}
		}
		//cout << pos << " " << pos1 << endl;
		int flag = 0;
		rep(i, pos + 1, pos1){
			if(a[i] == i) flag = 1;
		}
		if(flag){
			cout << "2" << endl;
		}
		else{
			cout << "1" << endl;
		}
	}
	return 0;
}