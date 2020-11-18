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
bool vis[100000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, k;
	cin >> n >> k;
	int ans = n * (n + 1) / 2;
	if(ans % n == k){
		if(n % 2 == 0){
			cout << n << " ";
			rep(i, 1, n / 2){
				cout << i << " " << n - i << " ";
			}
			cout << n / 2 << endl;
		}
		else{
			cout << n << " ";
			rep(i, 1, n / 2 + 1){
				cout << i << " " << n - i << " ";
			}
		}
	}
	else{
		cout << "-1" << endl;
	}
	return 0;
}