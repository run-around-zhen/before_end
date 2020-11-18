#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int N = 1e6+10;
int f[N],g[N],ans,n,m,k,t;
int fpow(int x,int p){
    int rs=1;
    while(p){
        if(p&1) rs=1LL*rs*x%MOD;
        x=1LL*x*x%MOD; p>>=1;
    }
    return rs;
}
int C(int n,int m){
    if(n<m){ printf("OHHHHHHHH\n"); return 0; }
    return 1LL*f[n]*g[m]%MOD*g[n-m]%MOD;
}
int solve(){
    if(k==1) return n;
    int rs=0,tp=0;
    for(int i=k;i<=min(n,m);++i){
        rs=(rs+1LL*C(n-i+k-1,k-1)*C(m-i+k-1,k-1)%MOD*C(i-1,k-1))%MOD;
    }
    return rs;
}
int main(){
	srand(time(0));
    f[0]=1; for(int i=1;i<N;++i) f[i]=1LL*f[i-1]*i%MOD;
    g[N-1]=fpow(f[N-1],MOD-2);
    for(int i=N-2;i>=0;--i) g[i]=1LL*g[i+1]*(i+1)%MOD;
    scanf("%d",&t);
    while(t--){
        //scanf("%d %d %d",&n,&m,&k);
        n = rand() % 1000000 + 1;
		m = rand() % 1000000 + 1;
		k = rand() % 1000000 + 1;
		if(k > n) swap(k, n);
		if(k > m) swap(k, m);
        printf("%d\n",solve());
    }
	return 0;
}