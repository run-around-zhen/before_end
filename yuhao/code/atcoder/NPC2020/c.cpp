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
int a[200000 + 10];
int ma[200000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, k;
	cin >> n >> k ;
	rep(i, 1, n + 1){
		cin >> a[i];
	}
	rep(j, 1, k + 1){
		int flag = 0;
		rep(i, 1, n + 1) ma[i] = 0;
		rep(i, 1, n + 1){
			if(i - a[i] <= 1) ma[1] ++;
			else ma[i - a[i]]++;
			if(i + a[i] <= n) ma[i + a[i] + 1] --;
		}
		int sum = 0;
		rep(i, 1, n + 1){
			sum += ma[i];
			a[i] = sum;
			if(sum != n) flag = 1;
		}
		if(flag == 0) break;
	}
	rep(i, 1, n + 1) cout << a[i] << " ";
	return 0;
}