#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>

using namespace std;
typedef long long LL; typedef long double LD;
const double eps=1e-9,Pi=acos(-1.0);
const int Maxn=100100;
int N,cnt_Con=0;
LL D,A[Maxn],B,sum[Maxn];
LD Maxx;
 struct P
{
    LD x,y;
    P(){} P(LD _x,LD _y){x=_x; y=_y;}   
}S[Maxn],Point;
P operator +(P a,P b){return P(a.x+b.x,a.y+b.y);}
P operator -(P a,P b){return P(a.x-b.x,a.y-b.y);}
P operator *(P a,LD rhs){return P(a.x*rhs,a.y*rhs);}
 struct Vec
{
    LD Cross(P a,P b){return a.x*b.y-a.y*b.x;}  
    LD Dot(P A,P B) {return A.x*B.x+A.y*B.y;}
    void Add_ConHull()
    {
        while (cnt_Con>1 && Cross(S[cnt_Con-1]-S[cnt_Con-2],Point-S[cnt_Con-2])>=0) 
            cnt_Con--;
        S[cnt_Con++]=Point;
    }
};
 void Three(int l,int r)
{
    while (r-l>2)
    {
        int Midl=l+(r-l)/3,Midr=r-(r-l)/3;
        if ((Point.x-S[Midl].x)/(Point.y-S[Midl].y)>(Point.x-S[Midr].x)/(Point.y-S[Midr].y))
        r=Midr; else l=Midl;
    }   
    Maxx=max(Maxx,max((Point.x-S[l].x)/(Point.y-S[l].y),(Point.x-S[r].x)/(Point.y-S[r].y)));
    Maxx=max(Maxx,(Point.x-S[(l+r)/2].x)/(Point.y-S[(l+r)/2].y));
}
 
int main()
{
 N=Get(); D=Get(); LD ans=0;
    for (int i=1;i<=N;i++)
    {
        A[i]=Get(),B=Get(); sum[i]=sum[i-1]+A[i];
        Maxx=(LD)A[i]/(LD)B; Point.x=sum[i]; Point.y=B+i*D;
        Three(0,cnt_Con-1);
        Point.x=sum[i-1]; Point.y=(LL)i*D; 
        Vec().Add_ConHull();
        ans+=Maxx;        //printf("%.6lf %.6lf\n",(double)ans,(double)Maxx);
    }
    printf("%.0lf\n",(double)ans);
    return 0;   
}