#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ld,ld> pii;
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
const int inf=0x3f3f3f3f;
const int maxn=25;
ld line[maxn];
const ld eps=1e-8;
ld dis(pii r)
{
	return sqrtl(r.fi*r.fi+r.se*r.se);
}

pii stright(ld nowx,ld nowy,ld edx,ld edy,ld d)
{
	pii r=mp(edx-nowx,edy-nowy);
	ld di=dis(r);
	pii ans;
	if(fabs(di)<eps)
	{
		ans.fi=nowx+di;
		ans.se=nowy;
	}
	ans.fi=nowx+r.fi/di*d;
	ans.se=nowy+r.se/di*d;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	ld remain=0;
	rep(i,0,n)
	{
		cin>>line[i];
		remain+=line[i];
	}
	ld edx,edy;
	cin>>edx>>edy;
	ld x=0.0,y=0.0;
	if(n==1)
	{
		ld d=dis(mp(edx-x,edy-y));
		if(fabs(d)<=eps)
		{
			cout<<fixed<<setprecision(10)<<line[0]<<" "<<0.0<<"\n";
			return 0;
		}
		pii p=stright(x,y,edx,edy,line[0]);
		cout<<fixed<<setprecision(10)<<p.fi<<" "<<p.se<<"\n";
		return 0;
	}
	rep(i,0,n)
	{
		remain-=line[i];
		pii q=mp(edx-x,edy-y);
		ld d=dis(q);
	//	dd(i);dd(d);dd(line[i]);de(remain);
		if(fabs(d)<eps)
		{
			x+=line[i];
			cout<<fixed<<setprecision(10)<<x<<" "<<y<<"\n";
		}
		else 
	//	dd(i);dd(q.fi);dd(q.se);de(d);
		if(d+line[i]<remain)
		{
			pii go=stright(x,y,edx,edy,line[i]);
			x=2*x-go.fi;
			y=2*y-go.se;
			cout<<fixed<<setprecision(10)<<x<<" "<<y<<"\n";
		}
		else if(d+eps>line[i]+remain)
		{
			pii go=stright(x,y,edx,edy,line[i]);
			x=go.fi;y=go.se;
			cout<<fixed<<setprecision(10)<<x<<" "<<y<<"\n";
		}
		else if(line[i]>d+remain)
		{
			pii go=stright(x,y,edx,edy,line[i]);
			x=go.fi;y=go.se;
			cout<<fixed<<setprecision(10)<<x<<" "<<y<<"\n";
		}
		else
		{
			ld sina=q.se/d,cosa=q.fi/d;
			ld cosb=(d*d+line[i]*line[i]-remain*remain)/(2*d*line[i]);
			ld sinb=sqrtl(1-cosb*cosb);
			ld cosab=cosa*cosb-sina*sinb,sinab=sina*cosb+sinb*cosa;
			x=x+cosab*line[i];
			y=y+sinab*line[i];
			cout<<fixed<<setprecision(10)<<x<<" "<<y<<"\n";
		}
	}
	return 0;
}
/*
2
1000
3
1 2

*/