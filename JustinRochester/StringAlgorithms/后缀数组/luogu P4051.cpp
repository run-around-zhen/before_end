#include<bits/stdc++.h>
using namespace std;
const int MAXN=1610;
// const int MAXN=1e6+10;
string s;
int n,sa[MAXN],fir[MAXN],sec[MAXN],tot[MAXN];
inline void getSA(){
    n=s.size();
    int num=128;
    for(int i=1;i<=n;i++) ++tot[ fir[i]=s[i-1] ];
    for(int i=1;i<=num;i++) tot[i]+=tot[i-1];
    for(int i=n;i>=1;i--) sa[ tot[fir[i]]-- ]=i;
    for(int k=1;k<n;k<<=1){
        int count=0;
        for(int i=n-k+1;i<=n;i++) sec[++count]=i;
        for(int i=1;i<=n;i++) if(sa[i]>k) sec[++count]=sa[i]-k;
        for(int i=1;i<=num;i++) tot[i]=0;
        for(int i=1;i<=n;i++) ++tot[ fir[i] ];
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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin,s);
    for(int i=0,I=s.size();i<I;i++) s.push_back(s[i]);
    getSA();
    // for(int i=1;i<=n;i++) cout<<sa[i]<<' ';
    for(int i=1;i<=n;i++) if(sa[i]+sa[i]<=n) cout<<s[sa[i]+(n>>1)-2];
    cout.flush();
    return 0;
}