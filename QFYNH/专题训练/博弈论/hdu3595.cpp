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
int n, m;
int sg[1010][1010], step[1010][1010];
int get_sg(int n, int m){
	if(n > m) swap(n, m);
	if(sg[n][m] != -1) return sg[n][m];
	if(n == 0 || m == 0) return sg[n][m] = 0;
	int div = m / n, mo = m % n;
	if(div == 1){
		sg[n][m] = get_sg(mo, n) ^ 1;
		step[n][m] = step[mo][n] + 1;
		return sg[n][m];
	}
	else{
		step[n][m] = get_sg(mo, n) + 1 + step[mo][n];
		return sg[n][m] = 1;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	memset(sg, -1, sizeof(sg));
	while(cin >> T){
		int ans = 0;
		rep(csa, 1, T + 1){
			cin >> n >> m;
			if(n > m) swap(n, m);
			get_sg(n, m);
			de(step[n][m]);
			ans = max(step[n][m], ans); 
		}
		//de(ans);	
		if(ans % 2 == 1){
			cout << "MM" << endl;
		}
		else{
			cout << "GG" << endl;
		}
	}
	de(get_sg(1, 2));
	de(step[1][2]);
	return 0;
}