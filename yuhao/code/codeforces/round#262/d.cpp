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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll l, r, k;
	cin >> l >> r >> k;
	/*a[1] = 2;
	rep(i, 2, 60) a[i] = a[i - 1] * 2;
	int ll = 60, rr = 0;
	rep(i, 1, 60){
		if(ll >= a[i]) ll = min(ll, i);
		if(rr >= a[i]) rr = max(rr, i);
	}*/
	if(k >= 3){
		ll tt = 1;
		 while(tt <= l) tt *= 2;
    	if(tt + tt / 2 <= r) {
    		cout << "0" << endl;
    		cout << "3" << endl;
       		cout << tt - 1 << " " << tt + tt / 2  << " " << ((tt - 1) ^ (tt + tt / 2 )) << endl;
       		return 0;
       	}
		
	}
	if(l == 1){
		if(r == 1 || r == 2 || k <= 2){
			cout << "1" << endl;
			cout << "1" << endl;
			cout << "1" << endl;
		}
		else {
			cout << "0" << endl;
			cout << "3" << endl;
			cout << "1 2 3" << endl;
		}
	}
	else if(k >= 4){		
		if((l % 2 == 0 && (r >= l + 3))){
			cout << "0" << endl;
			cout << "4" << endl;
			cout << l << " " << l + 1 << " " << l + 2 << " " << l + 3 << endl;
		}
		else if(l % 2 == 1 && (r >= l + 4)){
			l ++;
			cout << "0" << endl;
			cout << "4" << endl;
			cout << l  << " " << l + 1 << " " << l + 2 << " " << l + 3 << endl;
		}
		else{
			if(l % 2 != 0) l ++;
			cout << "1" << endl;
			cout << "2" << endl;
			cout << l << " " << l + 1  << endl;
		}
	}
	else if(k == 1){
		cout << l << endl;
		cout << "1" << endl;
		cout << l << endl;
	}
	else if(k == 3){
		if(l % 2 != 0) l ++;
		cout << "1" << endl;
		cout << "2" << endl;
		cout << l << " " << l + 1  << endl;
	}
	else{
		if(r == l + 1) {
			ll ans = l, ans1 = l + 1, ans2 = (ans ^ ans1);
			cout << min(min(ans1,ans),ans2) << endl;
			if(min(ans, ans1) < ans2){
				cout << "1" << endl;
				cout << min(min(ans1,ans),ans2) << endl;
			}
			else{
				cout << "2" << endl;
				cout << l << " " << l + 1 << endl;
			}
		}
		else{
			if(l % 2 != 0) l ++;
			cout << "1" << endl;
			cout << "2" << endl;
			cout << l << " " << l + 1  << endl;
		}
	}
	return 0;
}