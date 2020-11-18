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
int a[10000], b[1000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while( T--){
		int n;
		cin >> n;
		int flag = 0;
		rep(i, 1, n + 1){
			cin >> a[i];
			if(a[i] < a[i - 1]) flag =1;
		}
		int ans1 = 0,ans2 = 0;
		rep(i, 1, n + 1){
			cin >> b[i];
			if(b[i] == 0 )ans1 = 1;
			else ans2 = 1;
		}
		if(flag == 0 || ans1 + ans2 == 2){
			cout << "Yes" << endl;
		//	continue;
		}
		else{
			cout << "No" << endl;
		}

	}
	return 0;
}