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
string s;
int solve(int n, int a, int b, int c, int d){
	int ans = 0;
	rep(i, 0, n){
		if(s[i] == '1'){
			if(c){
				ans ++;
				c --;
			}
			else if(d){
				d --;
				c ++;
			}
			else if(a){
				a --;
				ans ++;
			}
			else if(b){
				b --;
				a ++;
			}
		}
		else{
			if(d){
				d --;
				c ++;
			}
			else if(c){

			}
			else if(b){
				b --;
				a ++;
			}
		}
	}
	return ans;
}
int solve1(int n, int a, int b, int c, int d){
	int ans = 0;
	rep(i, 0, n){
		if(s[i] == '1'){
			if(d){
				d -- ;
				c ++;
			}
			else if(c){
				c --;
				ans ++;
			}
			else if(b){
				b -- ;
				a ++;
			}
			else if(a){
				a --;
				ans ++;
			}
		}
		else{
			if(c){

			}
			else if(d){
				d --;
				c ++;
			}
			else if(a){

			}
			else if(b){
				b -- ;
				a ++;
			}
		}
	}
	return ans ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n ;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cin >> s;
		cout << solve(n ,a ,b, c, d) << " " << solve1(n, a, b, c, d) << endl;
	}
	return 0;
}