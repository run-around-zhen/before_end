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
int find(int i){
	if(f[i] == i) return f[i];
	else{
		int t = find(f[i]);
		val[i] += val[f[i]];
		f[i] = t;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, m;
	while(cin >> n >> m){
		if(n == 0 && m == 0) break;
		char type;
		cin >> type;
		rep(i, 1, n + 1) f[i] = i;
		if(type == '!'){
			int a, b, w;
			cin >> a >> b >> w;
			f[b] = a;
			val[b] = w;
			
		}
		else {
			int a, b;
			cin >> a >> b;
			int x = find(a);
			int y = find(b);
			if(f[x] != y){
				cout << "UNKNOWN" << endl;
			}
			else{
				cout << val[a] - val[b] << endl;
			}
		}
	}
	return 0;
}