#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=2e5+9;
const ll mod=998244353;
const ll Inf=1e18;
ll a[1000009],v[N<<1],fv[N<<1];
char s[30];
bool vis[60];
int Gauss(int n){
	int r=0;
	per(i,0,60){
		rep(j,r+1,n)if(a[j]&(1ll<<i))swap(a[j],a[r]);
		if(~a[r]&(1ll<<i))continue;
		rep(j,r+1,n)if(a[j]&a[r]&(1ll<<i))a[j]^=a[r];
		++r;
	}
	return r;
}
int Gauss_2(int n){
	int r=0;
	per(i,0,60){
		rep(j,r+1,n)if(v[j]&(1ll<<i))swap(v[j],v[r]),swap(fv[j],fv[r]);
		if(~v[r]&(1ll<<i))continue;
		rep(j,r+1,n)if(v[j]&v[r]&(1ll<<i))v[j]^=v[r],fv[j]^=fv[r];
		++r;
	}
	rep(i,r,n)if(fv[i])return -1;
	int R=r;
	r=0;
	per(i,0,60){
		rep(j,r+1,n)if(fv[j]&(1ll<<i))swap(v[j],v[r]),swap(fv[j],fv[r]);
		if(~fv[r]&(1ll<<i))continue;
		rep(j,r+1,n)if(fv[j]&fv[r]&(1ll<<i))v[j]^=v[r],fv[j]^=fv[r];
		++r;
	}
	return R;
}
bool build(ll x,int rank){
	int r=0;
	memset(vis,0,sizeof vis);
	per(mask,0,60){
		if(r==rank)break;
		if(a[r]&(1ll<<mask)){
			if(x&(1ll<<mask))vis[r]=1,x^=a[r];
			r++;
		}
	}
	return x==0;
} 
void solve(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%lld",&a[i]);
	int r=Gauss(n);
	scanf("%s",s);
	if(s[1]=='o'){ 
		int m;
		scanf("%d",&m);
		if(r&1){
			printf("NoSolution\n");
			while(m--){
				ll x;
				scanf("%lld",&x);
			}
		}
		else{
			printf("HaveSolution\n");
			while(m--){
				ll x;
				scanf("%lld",&x);
				if(build(x,r)){
					ll res=0;
					rep(i,0,r){
						if(vis[i]&&(i&1))res^=a[i^1];
					}
					printf("%lld\n",res);
				}
				else{
					printf("-1\n");
				}
			}
		}
	}
	else{
		scanf("%s",s);
		bool ok=r&1;
		int m=0,cnt=0;
		if(s[0]=='H')ok^=0,scanf("%d",&m);
		else ok^=1;
		while(m--){
			ll x,fx;
			scanf("%lld%lld",&x,&fx);
			if(fx==-1){
				if(build(x,r))ok=1;
			}
			else{
				if(!build(x,r)||!build(fx,r)){
					ok=1;
				}
				else{
					v[cnt]=x,fv[cnt++]=fx;
					if(fx)v[cnt]=fx,fv[cnt++]=0;
				}
			}
		}
		int R=Gauss_2(cnt);
		if(R==-1)ok=1;
		if(ok){
			printf("No\n");
			rep(i,0,cnt)v[i]=0,fv[i]=0;
			return;
		}
		int A=0;
		rep(i,0,R)A+=fv[i]?1:-1;
		if(abs(A)<=r-R){
			printf("Yes\n");
		}
		else printf("No\n");
		rep(i,0,cnt)v[i]=0,fv[i]=0;
	}
	rep(i,0,n)a[i]=0;
}
int main(){
	//freopen("text2.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)solve();
} 
/*
8
2 1 5 4 6 7 8 3
check
HaveSolution
10
21 Null
1 2
9 7
3 2
4 2
6 2
8 5
32 Null
15 5
13 5
*/
/*
1
10
268435456 2199291691016 9007199524225026 0 9009398279045130 9007199524225026 0 268435456 2199023255560 0
check
NoSolution
*/