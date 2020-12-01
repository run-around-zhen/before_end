#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int s[MAXN];
int n,k,fir[MAXN],sec[MAXN],sa[MAXN],tot[MAXN],*rk=fir,height[MAXN],h[MAXN];
int minHeight[20][MAXN],Lb[MAXN];
int lb(int n) { return (n<=1||Lb[n])?Lb[n]:(Lb[n]=lb(n>>1)+1); }
inline int LCP(int l,int r){
    if(l==r) return n-sa[l]+1;
    if(l>r) swap(l,r);
    ++l;
    return min( minHeight[lb(r-l+1)][l] , minHeight[lb(r-l+1)][r-(1<<lb(r-l+1))+1] );
}
inline void getRMQ(){
    for(int i=1;i<=n;i++) minHeight[0][i]=height[i];
    for(int flr=1;n>>flr;flr++)
        for(int i=1;i<=n-(1<<flr)+1;i++)
            minHeight[flr][i]=min(minHeight[flr-1][i],minHeight[flr-1][i+(1<<flr-1)]);
}
inline void getSA(){
    int num=20000;
    for(int i=1;i<=n;i++) ++tot[fir[i]=s[i-1]];
    for(int i=1;i<=num;i++) tot[i]+=tot[i-1];
    for(int i=n;i>=1;i--) sa[ tot[fir[i]]-- ]=i;
    for(int k=1;k<n;k<<=1){
        int count=0;
        for(int i=n-k+1;i<=n;i++) sec[++count]=i;
        for(int i=1;i<=n;i++) if(sa[i]>k) sec[++count]=sa[i]-k;
        for(int i=1;i<=num;i++) tot[i]=0;
        for(int i=1;i<=n;i++) ++tot[fir[i]];
        for(int i=1;i<=num;i++) tot[i]+=tot[i-1];
        for(int i=n;i>=1;i--) sa[ tot[fir[sec[i]]]-- ]=sec[i],sec[i]=0;
        swap(fir,sec);
        fir[sa[1]]=count=1;
        for(int i=2;i<=n;i++)
            fir[sa[i]]=(sec[sa[i]]==sec[sa[i-1]]&&sec[sa[i]+k]==sec[sa[i-1]+k])?count:++count;
        if(count==n) break;
        num=count;
    }
}
inline void getHeight(){
    for(int i=1;i<=n;i++){
        h[i]=max(h[i-1]-1,0);
        int pos1=i,pos2=sa[rk[i]-1];
        while(pos1+h[i]<=n&&pos2+h[i]<=n&&s[pos1+h[i]-1]==s[pos2+h[i]-1]) ++h[i];
        height[rk[i]]=h[i];
    }
}
inline void preSA(){
    getSA();
    getHeight();
    getRMQ();
}
inline int findLen(int pos){
    if(pos+k-1>n) return 0;
    return LCP(pos,pos+k-1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>s[i-1];
    preSA();
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,findLen(sa[i]));
    cout<<ans;
    cout.flush();
    return 0;
}