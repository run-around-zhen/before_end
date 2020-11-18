#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll,ll> pii;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rept(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define all(x) x.begin(),x.end()
#define pb push_back
#define fi first
#define se second
#define mes(a,b) memset(a,b,sizeof a)
#define mp make_pair
#define dd(x) cout<<#x<<"="<<x<<" "
#define de(x) cout<<#x<<"="<<x<<"\n"
#define debug() cout<<"I love Miyamizu Mitsuha forever.\n"
typedef pair<double,double> pdd;
const double eps=1e-6;
const int inf=0x3f3f3f3f;
const int maxn=25;
pdd p[maxn];
 
double dis(pdd s1,pdd s2)
{
    return sqrt((s1.fi-s2.fi)*(s1.fi-s2.fi)+(s1.se-s2.se)*(s1.se-s2.se));
}
 
double chaji(pdd s1,pdd s2)
{
    return s1.fi*s2.se-s1.se*s2.fi;
}
 
pdd operator -(pdd a,pdd b)
{
    return mp(a.fi-b.fi,a.se-b.se);
}
void test()
{
    int n=20;
    rep(i,0,n) cin>>p[i].fi>>p[i].se;
    rep(i,0,20)
    {
        int p1=-1,p2=-1;
        rep(j,0,n)
        {
            if(i==j) continue;
            double d=dis(p[i],p[j]);
        //  dd(i);dd(j);de(d);
            if(fabs(d-6.00)<=eps){
            	if(p1 != -1) cout << "!! "<< endl;
            	p1=j;
            }
            else {
            	if(fabs(d-9.00)<=eps) {
            		if(p2 != -1) cout << "!!" << endl;
            		p2=j;
            	}
            }
        }
        if(p1==-1||p2==-1) continue;
        if(chaji(p[i]-p[p1],p[i]-p[p2])<0) cout<<"right\n";
        else cout<<"left\n";
     //   return ;
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--) test();
    return 0;
}