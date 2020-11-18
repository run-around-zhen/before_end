#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int>vi;

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define fi first
#define se second
#define de(x) cout<<#x<<"="<<x<<"\n"
#define dd(x) cout<<#x<<"="<<x<<" "
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define lowbit(a) ((a)&-(a))
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
const int N=4e5+5;
int n;
ll a[N];
unordered_map<ll,int> M;
struct LineBase{
	ll d[N],cnt,f[N];
	void init(){
		memset(d,0,sizeof(d));
		cnt=0;
	}
	void Ins(ll x){
		for(int i=63;i>=0;--i){
			if((x>>i)&1){
				if(!d[i]){
					d[i]=x;
					cnt++;
					break;
				}
				else x^=d[i];
			}
		}
	} 
	ll gao(ll x,int i){
		int cnt = 0;
		for(int j = 0;j <= i;++j)if((x>>j&1))cnt++;
		return cnt;
	}
	ll getP(){
		ll res = 0;
		for(int i = 0;i <= 63;++i)
			res |= d[i];
		rep(i , 0 , 64)f[i] =(1ll<<gao(res,i));
		return res;
	}
}LB; 
ll p; 
ll solve(ll l,ll  r){
	ll cnt = 0;
	M.clear();
	for(ll i = l;i <= r;++i){
		ll now = (i&p);
		if(!M.count(now))
			M[now] = 1,cnt++; 
	}
	return cnt;
}
int main()
{
	scanf("%d",&n);
	LB.init();
	rep(i , 1 , n + 1){
		scanf("%lld",&a[i]);
		LB.Ins(a[i]);
	}
	p = LB.getP();
	int q,op;
	scanf("%d",&q);
	ll l , r,ans;
	while(q--){
		scanf("%d%lld%lld",&op,&l,&r);
		if(op == 1)ans = r - l + 1;
		else ans = solve(l , r);
		printf("%lld\n",ans); 
		for(auto i : M){
			cout << i.fi << " " ;
		}
		cout << endl;
	}
	return 0;
}
