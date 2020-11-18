#include<bits/stdc++.h>

using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rept(i,x,y) for(int i=x;i<=y;i++)
#define pb push_back
#define mp make_pair
const int inf=0x3f3f3f3f;
const int N=1e7+5;
deque<int> q;
stack<int> s;
int a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k,p,q,r,mod;
        scanf("%d%d%d%d%d%d%d",&n,&m,&k,&p,&q,&r,&mod);
        for(int i=1;i<=k;i++){
            scanf("%d",&a[i]);
        }
        for(int i=k+1;i<=n;i++){-
            a[i]=(1ll*p*a[i-1]+1ll*q*r+r)%mod;
        }
        for(int i=1;i<=m-1;i++){
            while(!q.empty()){

            }
        }
        for(int i=m;i<=n;i++){

        }
        for(int i=n;i>=n-m+1;i--){

        }
        for(int i=n-m;i>=1;i--){

        }
    }
}
