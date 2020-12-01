#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
char s[MAXN],t[MAXN],*ps=s,*pt=t;
int n,sa[MAXN],fir[MAXN],sec[MAXN],tot[MAXN],*rk=fir,h[MAXN],height[MAXN];
int minHeight[20][MAXN],Lb[MAXN];
int lb(int n) { return (n<=1||Lb[n])?Lb[n]:(Lb[n]=lb(n>>1)+1); }
inline int LCP(int i,int j){
    if(i==j) return n-sa[i]+1;
    if(i>j) swap(i,j);
    i++;
    return min( minHeight[lb(j-i+1)][i] , minHeight[lb(j-i+1)][j-(1<<lb(j-i+1))+1] );
}
inline void getRMQ(){
    for(int i=1;i<=n;i++) minHeight[0][i]=height[i];
    for(int flr=1;n>>flr;flr++)
        for(int i=1;i<=n-(1<<flr)+1;i++)
            minHeight[flr][i]=min(minHeight[flr-1][i],minHeight[flr-1][i+(1<<flr-1)]);
}
inline void getSA(){
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
        else num=count;
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
inline char getUpper(){
    char c=0;
    while(!isupper(c)) c=getchar();
    return c;
}
inline void work(int lim){
    int head=1,tail=lim;
    while(head<=tail){
        int len=LCP(rk[head],rk[n-tail+1]);
        if(s[head+len-1]<s[tail-len-1]) *(pt++)=s[head-1],head++;
        else *(pt++)=s[--tail];
    }
    *(pt++)=0;
}
int main(){
    int N;
    scanf("%d",&N);
    n=(N<<1|1);
    for(int i=1;i<=N;i++) *(ps++)=getUpper();
    *(ps++)='#';
    for(char *p=ps-2;p>=s;p--) *(ps++)=*p;
    getSA();
    getHeight();
    getRMQ();
    work(N);
    for(int i=1,I=strlen(t);i<=I;i++){
        putchar(t[i-1]);
        if(i%80==0) putchar('\n');
    }
    return 0;
}