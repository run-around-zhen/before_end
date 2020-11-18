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
int a[100000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	int n = rand() % 100000 + 1;
	cout << n << endl;
	rep(i, 1, n + 1){
		a[i] = rand() % 1000000000 + 1;
	}
	rep(i, 1, n + 1){
		cout << a[i] << " ";
	}
	cout << endl;
	int q = 1;
	cout << q << endl;
	cout << rand() % n + 1 << endl;
	return 0;
}