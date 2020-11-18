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
int a[10000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	int maxn = -1e9;
	rep(i, 1, n + 1){
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	rep(i, 1, n + 1){
		int space = ceil(50 * 1.0 * a[i] / maxn);
		cout << "+";
		rep(j, 1, space + 1) cout << "-";
		cout << "+";
		cout << endl;
		cout << "|";
		rep(j, 1, space + 1){
			if(j == space){
				if(maxn == a[i]) cout << "*";
				else cout << " ";
			}
			else{
				cout << " ";
			}
		}
		cout << "|";
		cout << a[i] << endl;
		cout << "+";
		rep(j, 1, space + 1) cout << "-";
		cout << "+";
		cout << endl;
	}
	return 0;
}