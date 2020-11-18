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
inline ll getLow(ll x,int pos){
	if(pos < 0)return 0;
	pos++;
	ll b = (1ll<<pos) - 1;
	return (x&b);
}
ll getR(ll r,int pos){
	if(pos < 0)return 1;
	//dd(r),de(pos);
	int b1 = (r>>pos&1),b2 = (p>>pos&1);
	if(b1 == 0)return getR(r,pos - 1);
	if(b2 == 0){
		if(pos == 0)return 1;
		return LB.f[pos - 1];
	}
	if(pos == 0)return 2;
	ll ty = getLow(r,pos - 1);
	return getR(ty,pos - 1) + LB.f[pos - 1];
}
ll dfs(ll l,ll r,int pos,int s){
	
	int b1 = (l>>pos&1),b2 = (r>>pos&1),b3 = (p>>pos&1); 
	dd(b1),dd(b2),de(b3);
	if(pos < 0)return s + 1;
	if(!s){
		if(b1 == b2)
			return dfs(l,r,pos-1,0);
		if(!b3){
			if(pos == 0)return 1;
			ll tx = getLow(l,pos - 1),ty = getLow(r,pos-1),mx = (1ll<<(pos)) - 1;
			if(tx <= ty)
				return LB.f[pos - 1];
			return dfs(ty,tx,pos - 1,1);
		}
		else{
			if(pos == 0){return 2;}
			ll tx = getLow(l,pos - 1),ty = getLow(r,pos-1),mx = (1ll<<(pos)) - 1;
			return getR(ty , pos - 1) + getR(mx - tx , pos - 1);
		}
	}
	else{
		if(b3){
			if(b1 == b2){
				if(pos == 0)return 1;
				ll tx = getLow(l,pos - 1),ty = getLow(r,pos-1),mx = (1ll<<(pos)) - 1;
				if(tx < ty)return LB.f[pos - 1] + dfs(tx,ty,pos - 1,1);
				return LB.f[pos];
			}
			else{
				if(pos == 0)return 2;
				ll tx = getLow(l,pos - 1),ty = getLow(r,pos-1),mx = (1ll<<(pos)) - 1;
				return getR(tx , pos - 1) + getR(mx - ty ,pos - 1);
			}
		}
		else{
			if(b1 == b2)return  LB.f[pos - 1];
			else{
				if(pos == 0)return 1;
				ll tx = getLow(l,pos - 1),ty = getLow(r,pos-1),mx = (1ll<<(pos)) - 1;
				if(tx < ty)return dfs(tx,ty,pos - 1,1);
				return LB.f[pos - 1]; 
			}
		} 
	} 
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
	ll l,r,ans;
	while(q--){
		scanf("%d%lld%lld",&op,&l,&r);
		if(op == 1)ans = r - l + 1;
		else ans = dfs(l,r,63,0);		
		printf("%lld\n",ans);
	}
	return 0;
}