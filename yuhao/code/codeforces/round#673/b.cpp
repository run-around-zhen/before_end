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
int a[100000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n,k;
		cin >> n >> k;
		rep(i, 1, n + 1){
			cin >> a[i];
		}
		if(k % 2 == 1){
			rep(i, 1, n + 1){
				if(a[i] <= k / 2) cout << "1 ";
				else cout <<"0 ";
			}
			cout << endl;
		}
		else{
			int flag = 1;
			rep(i, 1, n + 1){
				if(a[i] < k / 2) cout << "1 ";
				else if(a[i] > k / 2) cout << "0 ";
				else {
					if(flag){
						cout << "1 ";
						flag = 0;
					}
					else {
						cout << "0 ";
						flag = 1;
					}
				} 
			}
			cout << endl;
		}
	}	
	return 0;
}