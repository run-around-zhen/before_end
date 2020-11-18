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
ll mod = 1e9 + 7;
int N;
int rev;
int a[300000 + 10], b[300000 + 10], c[300000 + 10], ans[300000 + 10];
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		b /= 2;
		a = a * a % mod;
	}
	return res;
}
int add(int a,int b){
    if((a+=b)>=mod) a-=mod;
    return a;  
}
int mul(int a,int b){
    return 1ll * a * b%mod;
}
void FWT(int a[],int n){
    for(int d=1; d<n; d<<=1)  
        for(int m=d<<1,i=0; i<n; i+=m)  
            for(int j=0; j<d; j++){  
                int x=a[i+j],y=a[i+j+d];  
                a[i+j]=add(x, y)%mod,a[i+j+d]=add(x, -y+mod)%mod;  
            }
}

void UFWT(int a[],int n){
    for(int d=1; d<n; d<<=1)
        for(int m=d<<1,i=0; i<n; i+=m)
            for(int j=0; j<d; j++){
                int x=a[i+j],y=a[i+j+d];
                a[i+j]=1LL*add(x,y)*rev%mod,a[i+j+d]=(1LL*add(x, -y + mod)*rev%mod+mod)%mod;
            }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	rev = qpow(2, mod - 2);
	//cout << rev << endl;
	N = qpow(2, 18);
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		int x;
		cin >> x;
		a[x] = 1;
		b[x] = 1;
		ans[1] = max(ans[1], x);
	}
//	cout << N << endl;
//	rep(i, 1, 10) cout << a[i] << " ";
 	FWT(a, N);
	FWT(b, N);
	//rep(i, 1, 10) cout << a[i] << " ";
	rep(j, 2, 19){
		rep(i, 0, N){
			c[i] = (ll)a[i] * b[i] % mod;
			a[i] = (ll)a[i] * b[i] % mod;
		}
		FWT(c, N);
		/*rep(i, 1, 10){
			cout << c[i] << " ";
		}
		cout << endl;*/
		per(i, 1, N + 1) if(c[i]) {
			ans[j] = i;
			break;
		}
	}
	rep(i, 1, n + 1){
		if(i <= 18) cout << ans[i] << " ";
		else {
			ans[i] = ans[i - 2];
			cout << ans[i] << " ";
		}
	}
	
	return 0;
}