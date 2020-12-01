#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+10;
string s;
int n,fir[MAXN],sec[MAXN],tot[MAXN],sa[MAXN],*rk=fir,h[MAXN],height[MAXN],lpos[MAXN],rpos[MAXN];
inline void rsort(int num){
    for(int i=1;i<=num;i++) tot[i]=0;
    for(int i=1;i<=n;i++) ++tot[fir[i]];
    for(int i=1;i<=num;i++) tot[i]+=tot[i-1];
    for(int i=n;i>=1;i--) sa[ tot[fir[sec[i]]]-- ]=sec[i],sec[i]=0;
}
inline void getSA(){
    n=s.size();
    int num=128;
    for(int i=1;i<=n;i++) fir[i]=s[i-1],sec[i]=i;
    rsort(num);
    for(int k=1;k<n;k<<=1){
        int count=0;
        for(int i=n-k+1;i<=n;i++) sec[++count]=i;
        for(int i=1;i<=n;i++) if(sa[i]>k) sec[++count]=sa[i]-k;
        rsort(num);
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
        while(pos1+h[i]<=n&&pos2+h[i]<=n&&s[pos1+h[i]-1]==s[pos2+h[i]-1])
            ++h[i];
        height[rk[i]]=h[i];
    }
}
int stk[MAXN],cur;
inline void getLRmin(){
    stk[cur=1]=1;
    for(int i=2;i<=n;i++){
        while(cur&&height[stk[cur]]>height[i]) rpos[stk[cur--]]=i;
        lpos[i]=stk[cur];
        stk[++cur]=i;
    }
    while(cur) rpos[stk[cur--]]=n+1;
}
inline void preSA(){
    getSA();
    getHeight();
    getLRmin();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin,s);
    preSA();
    ll Ans=0;
    for(int i=1;i<=n;i++) Ans+=1ll*height[i]*(rpos[i]-i)*(i-lpos[i]);
    Ans=(n+1ll)*n*(n-1)/2-2*Ans;
    cout<<Ans;
    cout.flush();
    return 0;
}