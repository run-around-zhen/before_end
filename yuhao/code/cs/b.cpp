#include <bits/stdc++.h>
using namespace std;
const int Maxn=10010;
const double eps=1e-6;
int N;
struct P
{
    double x,y; 
    P(){} P(double _x,double _y) {x=_x; y=_y;}
}A[Maxn],B[Maxn];
P operator + (P A,P B) {return P(A.x+B.x,A.y+B.y);}
P operator - (P A,P B) {return P(A.x-B.x,A.y-B.y);}
P operator * (P A,double rhs) {return P(A.x*rhs,A.y*rhs);}
P operator / (P A,double rhs) {return P(A.x/rhs,A.y/rhs);}
int dcmp(double x) {if (fabs(x)<eps) return 0; else return x<0?-1:1;}
bool operator == (const P& A,const P &B){return dcmp(A.x-B.x)==0 && dcmp(A.y-B.y)==0;}
bool cmp_ConveHull(P a,P b) {return a.x<b.x||(a.x==b.x && a.y<b.y);}
struct Vec
{
    double Dot(P A,P B) {return A.x*B.x+A.y*B.y;}
    double Len(P A) {return sqrt(Dot(A,A));}
    double Angle(P A,P B) {return acos(Dot(A,B)/Len(A)/Len(B));}
    double Cross(P A,P B) {return A.x*B.y-A.y*B.x;}
  bool SegmenttoSegment(P a1,P a2, P b1, P b2)
    {
        double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),
              c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
        return dcmp(c1)*dcmp(c2)<=0 && dcmp(c3)*dcmp(c4)<=0;
    }
};
inline int Get()
{
    int f=0,v=0; char ch;
    while (!isdigit(ch=getchar())) if (ch=='-') break;
    if (ch=='-') f=1; else v=ch-48;
    while (isdigit(ch=getchar())) v=v*10+ch-48;
    if (f) return -v; else return v;
}
int main()
{
    N=Get();
    for (int i=1;i<=N;i++) scanf("%lf %lf %lf %lf",&A[i].x,&A[i].y,&B[i].x,&B[i].y);
    int ans=0;
    A[N+1]=A[1]; B[N+1]=B[1];
    for (int i=2;i<=N+1;i++) 
        for (int j=i+1;j<=N+1;j++)
            ans+=Vec().SegmenttoSegment(A[i],B[i],A[j],B[j]);
   	printf("%d\n",ans);
    return 0;
}