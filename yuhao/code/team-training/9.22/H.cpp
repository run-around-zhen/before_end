#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rept(i,x,y) for(int i=x;i<=y;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define dd(x) cout<<#x<<"="<<x<<" "
#define de(x) cout<<#x<<"="<<x<<"\n"
#define pb push_back
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;

void dfs(int n)
{
	if(n<=1) return ;
	else if(n==2)
	{
		cout<<345613;
		return ;
	}
	cout<<3;
	rep(i,0,n-2) cout<<42;	
	cout<<4;
	rep(i,0,n-2) cout<<53;
	cout<<5;
	rep(i,0,n-2) cout<<64;
	cout<<6;
	rep(i,0,n-2) cout<<15;
	cout<<1;
	rep(i,0,n-2) cout<<26;
	
	cout<<23;
	rep(i,0,n-3) cout<<13;
	
	cout<<4;
	dfs(n-2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		dfs(n);
		cout<<"\n";
	}
	return 0;
}
