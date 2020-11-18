#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<iterator>
#include<utility>
#include<algorithm>
//#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
#define mp make_pair
#define fi first
#define se second
#define All(x) (x).begin(),(x).end()
#define Y1 "YES"
#define N1 "NO"
#define ENDL '\n'
#define count2(x) __builtin_popcount(x)
#define countleadingzero(x) __builtin_clz(x)
inline ll read(){//not solve LLONG_MIN LMAX=9,223,372,036,854,775,807
    ll s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0' && ch<='9')s=s*10+ch-'0',ch=getchar();
    return s*w;
}
typedef __uint128_t returnT;
typedef unsigned long long argT;
const static int N=1e6+7;
returnT g[N],sp[N],h[N],n,w[N];
argT Sqr,m,p[N],id1[N],id2[N],tot,cntp;
bool isp[N];
inline returnT f(argT p){
    return p;
}
inline returnT calc(returnT n){
    return (1+n)*n/2-1;
}
void prime(argT n){
    cntp=0;isp[1]=1;
    for(argT i=2;i<n+1;++i){
        if(!isp[i])p[++cntp]=i;
        for(argT j=1;j<=cntp&&i*p[j]<=n;++j){
            isp[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
    for(argT i=1;i<=cntp+1;++i)sp[i]=sp[i-1]+f(p[i]);
    p[++cntp]=INT_MAX;
}
argT solve(argT _n){
    argT n=_n;
    if(n==0)return 0;
    m=0;Sqr=sqrt(n);
    tot=upper_bound(p+1,p+cntp+1,Sqr)-(p+1);
    for(argT i=1,j;i<=n;i=j+1){
        j=n/(n/i);
        w[++m]=n/i;
        g[m]=calc(w[m]);
        w[m]<=Sqr?id1[w[m]]=m:id2[j]=m;
    }
    for(argT j=1;j<tot+1;++j){
        for(argT i=1;i<=m&&p[j]*p[j]<=w[i];++i){
            returnT t=w[i]/p[j];
            returnT k=t<=Sqr?id1[t]:id2[n/t];
            g[i]-=f(p[j])*(g[k]-sp[j-1]);
        }
    }
    return g[1];
}
int main(){
    prime(1e5+1);
    int t=read();
    while(t--){
        ll n=read();
        int k=read();solve(n+1);
        returnT ans = (returnT)n*(3+n)/2+g[1]-4 ;
        printf("%d\n",(int)(ans%k));
    }
    return 0;
}