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
int a[1000];
bool vis[200000 + 10];
int x[200000 + 10], y[200000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n;
	cin >> n;
	rep(i, 0, 20000 + 1){
		rep(j, 0, 20000 + 1){
			if(i * i + j * j > 20000) break;
			vis[i * i + j * j] = true;
		}
	}
	//cout << "??" << " " << vis[2] << endl;
	rep(i, 1, n + 1){
		cin >> x[i] >> y[i];
		int p = x[i] * x[i] + y[i] * y[i];
		//cout << p  << endl;
		int flag = 0;
		for(int i = 2; i < p; i ++){
			if(p % i == 0){
				if(vis[i] && vis[p / i]) flag = 1;
				//cout << i << " " << vis[i] << endl;
			}
		}
		if(flag){
			cout << "C" << endl;
		}
		else{
			cout << "P" << endl;
		}
	}
	return 0;
}