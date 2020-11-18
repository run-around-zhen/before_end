#include <bits/stdc++.h>
using namespace std;
typedef long long LL; typedef long double LD;
const double eps=1e-9,Pi=acos(-1.0);
const int Maxn=55000;
int N; double R,Num[2*Maxn];
struct Tnode
{
	double st,en;
	Tnode(){} Tnode(double _st,double _en) {st=_st; en=_en;}
}Rad[Maxn];
struct P
{
	double x,y;
	P(){} P(double _x,double _y) {x=_x; y=_y;}
}A[Maxn];
P operator - (P A,P B) {return P(A.x-B.x,A.y-B.y);}
int dcmp(double x) {if (fabs(x)<eps) return 0; else return x<0?-1:1;}
struct Vec
{
	double Dot(P A,P B) {return A.x*B.x+A.y*B.y;}
    double Len(P A) {return sqrt(Dot(A,A));}	};
void init()
{
	scanf(" %d %lf",&N,&R);	
	for (int i=1;i<=N;i++) 
		scanf(" %lf %lf",&A[i].x,&A[i].y);
}
int main()
{
	init(); LL ans=0;
	for (int i=1;i<=N;i++)
	{
	  double len=Vec().Len(A[i]),r1=acos(R/len),r2=atan2(A[i].y,A[i].x);
		Rad[i]=Tnode(r2-r1,r2+r1);
		if (dcmp(Rad[i].st+Pi)<=0) 
			Rad[i].st+=2*Pi;
		if (dcmp(Rad[i].en-Pi)>=0) 
			Rad[i].en-=2*Pi;
		if (Rad[i].st>=Rad[i].en && dcmp(Rad[i].st-Rad[i].en-Pi)<=0) swap(Rad[i].st,Rad[i].en);
		if (Rad[i].en>=Rad[i].st && dcmp(Rad[i].en-Rad[i].st-Pi)>=0) swap(Rad[i].st,Rad[i].en);
			Num[2*i-1]=Rad[i].st; 
			　Num[2*i]=Rad[i].en;
	} 
	sort(Num+1,Num+2*N+1);
	for (int i=1;i<=N;i++)
	{
		int l=lower_bound(Num+1,Num+2*N+1,Rad[i].st)-Num,
			r=lower_bound(Num+1,Num+2*N+1,Rad[i].en)-Num;
		ans+=l<=r?r-l-1:2*N+r-l-1;	
	}
	cout<<ans/2<<endl;
	return 0;
}