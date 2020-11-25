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
int sg[2000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);	
	int T;
	cin >> T;
	while(T --){
		int n, m;
		cin >> n >> m;
		rep(i, 1, n + 1){
			rep(j, 1, m + 1){
				int x;
				cin >> x;
				sg[i + j] ^= x;
			}
		}
		int flag = 0;
		rep(i, 1, n + m + 1) if(sg[i]) flag = 1;
		if(!flag){
			cout << "Jeel" << endl;
		}
		else{
			cout << "Ashish" << endl;
		}
		rep(i, 1, n + m + 1) sg[i] = 0;
	}
	return 0;
}
