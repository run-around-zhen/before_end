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
int a[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n, x;
		cin >> n >> x;
		rep(i, 1, n + 1){
			cin >> a[i];
		}
		int ans = 0;
		int cnt = 0;
		int sum = 0;
		rep(i, 1, n + 1){
			if(a[i] != x) ans = 1;
			sum += a[i];
			if(a[i] == x) cnt ++;
		}
		if(ans == 0){
			cout << ans << endl;
		}
		else if(cnt || sum  ==  n * x){
			cout << "1" << endl;
		}
		else{
			cout <<"2" << endl;
		} 
	}
	return 0;
}