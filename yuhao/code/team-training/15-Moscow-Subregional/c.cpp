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
int xx = 0, yy = 1;
int cnt = 0;
int get(int a, int b ,int c, int d){
	cout << a << " " << b << endl;
	int x;
	cin >> x;
	cout << c << " " << d << endl;
	cin >> x;
	/*if(a < 0 || b < 0 || c < 0 || d < 0){
		cout << "!!!" ;
		cout << a << " " << b << " " << c << " " << d << endl; 
	}
	if(a > 1e9 || b  > 1e9 || c  > 1e9 || d  > 1e9){
		cout << "!!!" ;
		cout << a << " " << b << " " << c << " " << d << endl; 
	}
	cnt += 2;
	if(abs(c - xx) + abs(d - yy) < abs(a - xx) + abs(b - yy)) return 1;
	return 0;*/
	return x;
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	int x = 231312312 ;
	int l = 0, r = 1e9;
	int y;
	while(l + 2 < r){
    	int lm=(l + r) >> 1,rm = lm + 1;
    //	cout << l << " " << r << endl;
    	if(get(x, lm, x, rm) == 1){
       		l = lm;
       		y = lm;
    	}
    	else{
    		
        	r = rm;
		}
	}
	//cout <<l  << endl;
	if(l == 1e9){
		y = 1e9;
	}
	else if(l == 1e9 - 1){
		if(get(x, l, x, l + 1) == 1) y = 1e9;
		else y =1e9 - 1;
	}
	else{

		if(get(x, l, x, l + 1) == 1) {
			y = l + 1;
			//cout << l << " " << "???" << endl;
			if(get(x, l + 1, x, l + 2) == 1){
				y = l + 2;
			}
			else{
				y = l + 1;
			}
		}
		else {
			y = l;
			if(get(x, l , x, l + 2) == 1){
				y = l + 2;
			}
			else{
				y = l;
			}
		}
	}
	l = 0, r = 1e9;
	while(l + 2 < r){
    	int lm=(l + r) >> 1,rm = lm + 1;
    	//cout << l << " " << r << endl;
    	if(get(lm, y, rm, y) == 1){
       		l = lm;
       		x = lm;
    	}
    	else{
        	r = rm;
		}
	}
	if(l == 1e9){
		x = 1e9;
	}
	else if(l == 1e9 - 1){
		if(get(l, y, l + 1, y) == 1) x = 1e9;
		else x =1e9 - 1;
	}
	else{
		if(get(l, y, l + 1, y) == 1) {
			x = l + 1;
			if(get(l + 1, y, l + 2, y) == 1){
				x = l + 2;
			}
			else{
				x = l + 1;
			}
		}
		else {
			x = l;
			if(get(l + 1, y , l + 2, y) == 1){
				x = l + 2;
			}
			else{
				x = l;
			}
		}
	}
	//cout << cnt << endl;
	cout << "A "  << x << " " << y << endl;
	return 0;
}