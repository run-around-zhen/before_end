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
	int a, b;
	cin >> a >> b;
	int x = abs(a) + abs(b);
	if(a > 0 && b > 0){
		cout << "0 " << x << " " << x << " 0" << endl;
	}
	else if(a < 0 && b > 0){
		cout << -x << " " << 0 << " " << 0 << " " << x << endl;
	}
	else if(a < 0 && b < 0){
		cout << -x << " " << 0 << " " << 0 << " " << -x << endl;
	}
	else{
		cout << "0 " << -x << " " << x << " 0" << endl;
	}
	return 0;
}