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
int a[10000];
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1){
			res=res*a;
		}
		b/=2;
		a=a*a;
	}
	return res;
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		ll sum=0,sum1=0;
		int n;
		cin >> n;
		rep(i,1,n/2){
			sum+=qpow(2,i);
		}
		rep(i,n/2,n){
			sum1+=qpow(2,i);
		}
		sum+=qpow(2,n);
		//cout<<sum<<" "<<sum1<<" "<<abs(sum-sum1)<<endl;
		//cout<<n<<endl;
		cout<<abs(sum-sum1)<<endl;
	}
	return 0;
}