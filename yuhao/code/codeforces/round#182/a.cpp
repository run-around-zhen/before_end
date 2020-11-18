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
int a[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	int sum = 0, sum1 =0 ;
	rep(i, 1, n + 1){
		cin >> a[i];
		if(a[i] == - 1) sum ++;
		else sum1 ++;
	}
	while(m --){
		int l, r;
		cin >> l >> r;
		int cnt = r - l + 1;
		if(cnt % 2 == 0 && sum >= cnt / 2 && sum1 >= cnt / 2){
			cout << "1" << endl;
		}
		else{
			cout << "0" << endl;
		}
	}
	return 0;
}