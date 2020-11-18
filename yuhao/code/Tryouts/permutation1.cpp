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
int a[200000 + 10], b[200000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	rep(i, 1, n + 1) a[i] = i;
	int q;
	cin >> q;
	while(q --){
		int type, x;
		cin >> type >> x;
		if(type == 1){
			b[1] = x;
			int flag = 0;
			rep(i, 2, n + 2){
				if(a[i - 1] == x) {
					flag = 1;
					continue;
				}
				b[i - flag] = a[i - 1];
			}
			rep(i, 1, n + 1) a[i] = b[i];
		}
		else if(type == 2){
			int flag = 0;
			rep(i, 1, n + 1){
				if(a[i] == x) {
					flag = 1;
					continue;
				}
				b[i - flag] = a[i];
			}
			b[n] = x;
			rep(i, 1, n + 1) a[i] = b[i];
		}
		else{
			cout << a[x] << endl;
		}
		//rep(i, 1, n + 1) cout << a[i] << " ";
		//cout << endl;
	}
	return 0;
}