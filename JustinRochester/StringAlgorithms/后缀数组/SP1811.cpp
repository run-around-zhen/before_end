#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
string s;
int n,m,fir[MAXN],sec[MAXN],sa[MAXN],tot[MAXN],*rk=fir,height[MAXN],h[MAXN];
inline void rsort(){
    for(int i=1;i<=m;i++) tot[i]=0;
    for(int i=1;i<=n;i++) ++tot[fir[i]];
    for(int i=1;i<=m;i++) tot[i]+=tot[i-1];
    for(int i=n;i>=1;i--) sa[ tot[fir[sec[i]]]-- ]=sec[i],sec[i]=0;
}
inline void getSA(){
    n=s.size();
    m=128;
    for(int i=1;i<=n;i++) fir[i]=s[i-1],sec[i]=i;
    rsort();
    for(int k=1;k<n;k<<=1){
        int count=0;
        for(int i=n-k+1;i<=n;i++) sec[++count]=i;
        for(int i=1;i<=n;i++) if(sa[i]>k) sec[++count]=sa[i]-k;
        rsort();
        for(int i=1;i<=n;i++) swap(fir[i],sec[i]);
        fir[sa[1]]=count=1;
        for(int i=2;i<=n;i++)
            fir[sa[i]]=(sec[sa[i]]==sec[sa[i-1]]&&sec[sa[i]+k]==sec[sa[i-1]+k])?count:++count;
        if(count==n) break;
        m=count;
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
string t;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s>>t;
    s+="#"+t;
    getSA();
    getHeight();
    int ans=0;
    for(int i=2;i<=n;i++)
        if( (sa[i]>t.size()&&sa[i-1]<=t.size())||(sa[i]<=t.size()&&sa[i-1]>t.size()) )
            ans=max(ans,height[i]);
    cout<<ans;
    cout.flush();
    return 0;
}