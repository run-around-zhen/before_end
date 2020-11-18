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
int a[100000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	cin >> q;
	while(q --){
		int len;
		cin >> len;
		int ans = 0, res = 0;
		for(int i = 1; i <= n;){
			res ++;
			int flag;
			if(a[i + 1] >= a[i]) flag = 1;
			else flag = -1;
			if(flag == 1){
				int tt = 0;
				rep(j, 1, len){
					if(i + j > n) {
						tt = 1;
						break;
					}
					if(a[j + i] < a[j + i - 1]){
						tt = 1;
						ans += len - j;
						break;
					}
				}
				cout << i << " " << tt << endl;
				if(tt){
					i = i + len;
				}
				else{
					for(int j = len; ; j ++){
						if(i + j > n){
							i = i + j;
							break;
						}
						if(a[j + i] < a[j + i - 1]){
							i = i + j;
							break;
						}
					}
				}
			}
			else{
				int tt = 0;
				rep(j, 1, len){
					if(i + j > n ) {
						tt= 1;
						break;
					}
					if(a[j + i] >= a[j + i - 1]){
						tt = 1;
						ans += len - j;
						break;
					}
				}
				if(tt){
					i = i + len;
				}
				else{
					for(int j = len;; j ++){
						if(i + j > n) {
							i = i + j;
							break;
						}
						if(a[j + i] >= a[j + i - 1]){
							i = i + j;
							break;
						}
					}
				}
			}
			cout << i << " " <<  ans << "!!" <<endl;
		}
		cout << res <<" " <<ans << endl;
	}
	return 0;
}