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
ll a[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		ll ans = 0 ;
		ll sum = 0;

		rep(i, 1, n + 1){
			cin >> a[i];
			sum += a[i];
			if(a[i] % i) ans ++;
		}
		if(sum % n != 0){
			cout << "-1" << endl;
		}
		else{
			ll avr = sum / n;
			cout << 2 * (n - 1) + ans << endl;
       		rep(i, 2, n + 1){
            	if(a[i] % i == 0){
            		cout << i << " 1 " << a[i] / i << endl;
            	} 
           		else{
            		cout << "1 " << i << " " << i - a[i] % i << endl;
            		cout << i << " 1 " << a[i] / i + 1 << endl; 
            	}
            }
            rep(i, 2,  n + 1){
        		cout << "1 " << i << " " << avr << endl;
     	   }
        }
        
	}
	return 0;
}