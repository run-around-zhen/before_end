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
vi prime;
bool isprime[10000000 + 10];
int MAXN = 1e7 + 5;
void Prime(){
	isprime[1] = true;
	for(int i = 2 ; i < MAXN ; i++ ){
		if(!isprime[i]) prime.pb(i);
		for(int j = 0 ; j < prime.size() ; j++){
			if(i * prime[j] >= MAXN ) break;
			isprime[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		} 
	}
}
int res1[500000 + 10], res2[500000 + 10], a[500000 + 10]; 	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	Prime();
	int n = 5e5;
	//cout << prime[420] * prime[421] << endl;
	//cin >> n;
	/*rep(i, 0, 10){
		cout << prime[i] << " " ;
	}*/
	rep(i, 1, n + 1){
		//cin >> a[i];
		a[i] = 8485553;
	}
	rep(i, 1, n + 1){
		if(!isprime[a[i]]){
			res1[i] = -1;
			res2[i] = -1;
		}
		else{
			for(auto j : prime){
				if(a[i] % j == 0){
					int tmp = a[i];
					int t1 = 1;
					while(tmp % j == 0){
						tmp /= j;
						t1 *= j;
					}
					if(a[i] != t1 && __gcd(a[i], t1 + a[i] / t1) == 1){
						res1[i] = t1;
						res2[i] = a[i] / t1;
						//cout << t1 << endl;
					}
					break;
					
				}

			}
		}
	}
	rep(i, 1, n + 1){
		if(res1[i] != 0){
			cout << res1[i] << " ";
		}
		else{
			cout << "-1" << " ";
		}
	}
	cout <<endl;
	rep(i, 1, n + 1){
		if(res2[i] != 0){
			cout << res2[i] << " ";
		}
		else{
			cout << "-1" << " ";
		}
	}
	return 0;
}