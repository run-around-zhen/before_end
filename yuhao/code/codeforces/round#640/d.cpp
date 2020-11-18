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
int a[1000000+10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		rep(i, 1, n + 1) cin >> a[i];
		int l = 1, r = n;
		int flag = 0;
		int suma = 0;
		int sumb = 0;
		int ans = 0;
		int resa = 0;
		int resb = 0;
		while(l <= r){
			if(!flag){
				suma += a[l];
				resa += a[l];
				l++;
				if(resa > resb) {
					resb = 0;
					ans ++ ;
					flag = 1;
				}
			}
			else{
				sumb += a[r];
				resb += a[r];
				r--;
				if(resb > resa){
					resa = 0;
					ans ++ ;
					flag = 0;
				}
			}
			
		}
		if((resa != 0 && resb != 0) ) ans ++;
		cout << ans <<" " << suma << " " << sumb << endl;
	}
	return 0;
}