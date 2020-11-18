#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=5020;

inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int c[N][N],p[N][N];
int qp[N],t[N],dp[N],fo[N];

int main(void)
{
    int _=read();
    int mod=read();

    for(int i=0;i<N;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++) c[i][j]=1ll*(c[i-1][j-1]+c[i-1][j])%mod;
    }
    for(int i=0;i<N;i++)
    {
        p[i][0]=1;
        for(int j=1;j<N;j++)
        {
            p[i][j]=1ll*p[i][j-1]*i%mod;
        }
    }
    t[0]=0,t[1]=0,t[2]=2;
    for(int i=3;i<N;i++)
    {
        for(int j=1;j<=i-2;j++)
        {
            t[i]=(t[i]+1ll*j*j*j%mod*p[i-1][i-j-2]%mod*c[i-1][j]%mod)%mod;
        }
        t[i]=1ll*(t[i]+(i-1)*(i-1))*i%mod;
    }
    fo[0]=1,fo[1]=1;
    for(int i=2;i<N;i++)
    {
        fo[i]=p[i][i-2];
        for(int j=1;j<i;j++)
        {
            fo[i]=(fo[i]+1ll*c[i-1][j-1]*(j>=2?p[j][j-2]:1)%mod*fo[i-j]%mod)%mod;
        }
    }
    for(int i = 2; i < 10; i ++){
       // cout << t[i] << " ";
    }
    for(int i=2;i<10;i++)
    {
        dp[i]=t[i];
        for(int j=1;j<i;j++)
        {
            dp[i]=(dp[i]+1ll*c[i-1][j-1]*t[j]%mod*fo[i-j]%mod)%mod;
            dp[i]=(dp[i]+1ll*c[i-1][j-1]*(j>=2?p[j][j-2]:1)%mod*dp[i-j]%mod)%mod;
            cout << dp[i] << " ";
        }
    }

    for(;_>0;_--)
    {
        printf("%lld\n",dp[read()]);
    }
    
    return 0;
}