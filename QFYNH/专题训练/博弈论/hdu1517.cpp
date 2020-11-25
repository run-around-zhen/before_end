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
	int n;
	while(cin >> n){
		int r = 9;
		int cnt = 0;
		while(r < n){
			if(cnt % 2 == 0) r *= 2;
			else r *= 9;
			cnt ++;
		}
		if(cnt % 2 == 0){
			cout << "Stan wins." << endl;
		}
		else{
			cout << "Ollie wins." << endl;
		}
	}
	return 0;
}