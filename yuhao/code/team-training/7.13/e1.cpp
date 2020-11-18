#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define de(x) cout<<#x<<" = "<<x<<"\n"
#define dd(x) cout<<#x<<" = "<<x<<" "
#define mp make_pair
#define mes(p) memset(p,0,sizeof(p))
#define all(x) x.begin(),x.end()
#define rson mid+1,r,rt<<1|1
#define sz(x) (int)x.size()
#define lson l,mid,rt<<1
#define pb push_back
#define ls (rt<<1)
#define se second
#define rs (ls|1)
#define fi first
typedef pair <int ,int > pi;
typedef vector <int > vi;
typedef long long ll;
const int maxn=1000005;
const int mod = 1e9 +7 ;
const int inv2 = (mod + 1)/2;
int a[21][(1<<18)+5];
int add(int a,int b){
    if((a+=b)>=mod) a-=mod;
    return a;  
}
int mul(int a,int b){
    return 1ll * a * b%mod;
}
void fwt(int a[],int n,int t){
    for(int d=1;d<n;d<<=1)
    for(int m=d<<1,i=0;i<n;i+=m)
    for(int j=0;j<d;j++){
        int x=a[i+j], y=a[i+j+d];
        if(t==1){
            a[i+j]=add(x,y), a[i+j+d]=add(x,mod-y);
        }else {
            a[i+j]=mul(add(x,y),inv2), a[i+j+d]=mul(add(x,mod-y),inv2);
        }
    }
}
int ans[25], res[3];
int main(){
    int N= 1<<18;
    int m = 20;
    int n;
    scanf("%d", &n);
    rep(i,0,n){
        int x;
        scanf("%d", &x);
        a[0][x] = 1;
    }
    fwt(a[0], N, 1);
    rep(i, 0, 10){
        cout << a[0][i] << " ";
    }
//  fwt(a[0], N, 0);
    rep(i,1,m){
        rep(j,0,N)
            a[i][j] = mul(a[i-1][j],a[0][j]);
    }
    rep(i,0,m){
        fwt(a[i], N, 0);
    }
    for(int i=m-1;i>=0;i--){
        rep(j,0,N)
            if(a[i][j]!=0) ans[i] = j;
        //ans[i] = max(ans[i], ans[i+1]);
        res[i&1] = max(res[i&1], ans[i]);
    }
    rep(i,1,n+1){
        if(i>1) printf(" ");
        if(i-1 < m) printf("%d", ans[i-1]);
        else printf("%d", res[(i-1)&1]);
    }
    return 0;
}