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
int sum[30];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n, k;
		cin >> n >> k;
		string a, b;
		cin >> a >> b;
		int flag = 0;
		rep(i, 0, n){
			sum[a[i] - 'a'] ++ ;
			sum[b[i] - 'a'] --;
		}
		rep(i, 0, 26){
			if(sum[i] < 0 || sum[i] % k != 0){
				flag = 1;
				break;
			}
			sum[i + 1] += sum[i];
		}
		rep(i, 0, 26) sum[i] = 0;
		if(flag){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		} 
	}
	return 0;
}