#include <bits/stdc++.h>
using namespace std;
typedef long long LL; typedef long double LD;
const double eps=1e-11;
const int Inf=(int)2e9,Maxn=110;
int N;
double po[Maxn];
struct P
{
    double x,y;
    P(){} P(double _x,double _y){x=_x; y=_y;}   
}A[Maxn];
P operator +(P a,P b){return P(a.x+b.x,a.y+b.y);}
P operator -(P a,P b){return P(a.x-b.x,a.y-b.y);}
P operator *(P a,double rhs) {return P(a.x*rhs,a.y*rhs);}
double Cross(P a,P b){return a.x*b.y-a.y*b.x;}
inline void init()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++) 
        scanf("%lf %lf %lf",&A[i].x,&A[i].y,&po[i]);
}
int main()
{
    init();
    LD ans=0,p;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++){
             if (i!=j) {
                p=1.0*po[i]*po[j];
               for (int k=1;k<=N;k++){
                    if (k!=i && k!=j){
                         if (Cross(A[j]-A[i],A[k]-A[i])>eps) p=p*(1-po[k]);   
                     }
                 }
             }
             ans+=p*Cross(A[i],A[j]);
         }
     }
    printf("%.6f\n",abs((double)ans/2.0));
    return 0;
}