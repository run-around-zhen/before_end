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
const int N=1e6+5;
int _p;
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res =res *a % _p;
		}
		a = a *a % _p;
		b /= 2;
	}
	return res;
}
template <class V>
struct min_25
{
	ll n, w[N];bool pp[N]; int B,cnt,tot,id1[N],id2[N]; V p[N],g[N],h[N],s[N],f_1;
	inline void Init(ll _n){
		n=_n,B=sqrt(n)+1;memset(pp,0,sizeof(pp));
		tot=cnt=0; g[0]=h[0]=s[0]=0; f_1=1;
		init_prime(B),init_sum();
	}
	inline V f(int i,int e){ 
		if(e == 1) return -1;
		return 0;
	}
	inline int get_id(ll x){ return x<=B?id1[x]:id2[n/x];}
	inline void init_prime(int _n){
		rep(i,2,_n){
			if(!pp[i]) p[++tot]=i,s[tot]=(s[tot-1]+i)%_p;
			for(int j=1; j<=tot && i*p[j]<=_n; ++j){
				pp[i*p[j]]=1;
				if(i%p[j]==0) break;
			}
		}
	}
	inline void init_sum(){
		for(ll i=1,j,x,k; i<=n; i=j+1){
			j=n/(n/i),w[++cnt]=x=n/i,x%_p,k=cnt;
			(n/i<=B) ? id1[n/i]=k : id2[j]=k;
			h[k]=x-1;
			g[k]=x*(x+1)%(2*_p)/2-1;
		}
		rep(j,1,tot) for (int i=1; i<=cnt && (ll)p[j]*p[j]<=w[i]; ++i){
			int k=get_id(w[i]/p[j]);
			(h[i]-=(ll)1*(h[k]-(j-1)))%=_p;
			(g[i]-=(ll)p[j]*(g[k]-s[j-1])%_p)%=_p;
		
		}
	}
	inline V F(int k){ return g[k]-h[k];}
	inline V G(int no){ return s[no]-no;}
	V S(ll x, int j){
		if(x<=1 || p[j]>x) return 0;
		int k=get_id(x); V ans=(F(k)-G(j-1))%_p;
		for(int i=j;i<=tot && (ll)p[i]*p[i]<=x; ++i){
			ll t1=p[i],t2=(ll)p[i]*p[i];
			for(int e=1; t2<=x ; ++e,t1=t2,t2=t2*p[i])
				(ans+=((ll)S(x/t1,i+1)*f(i,e)%_p+f(i,e+1)%_p))%_p;
		}
		return ans;
	}
	inline V Solve(){ return ((S(n,1)+f_1)%_p+_p)%_p;}
};
min_25<ll >cal;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		ll n;
		cin >> n >> _p;
		int mod = _p;
 		cal.Init(n +1);
 		cout << ((((n + 3) % mod* (( n ) % mod )%mod*qpow(2,mod -2 ) % mod + cal.Solve()) % mod) % mod-1 + mod) % mod << endl; 
	}
	//cal.Init(n);
	//cout << cal.Solve()  - 1<< endl;
	return 0;
}