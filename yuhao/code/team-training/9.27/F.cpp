#include<bits/stdc++.h>

using namespace std;
#define pb push_back
#define rep(i,x,y) for(int i=x;i<y;i++)

void test()
{
	int n;
	cin>>n;
	int ans=0;
	rep(i,0,n)
	{
		int x;
		cin>>x;
		ans^=x;
	}
	rep(i,1,n)
	{
		int a,b;
		cin>>a>>b;
	}
	cout<<(ans==0? "D\n":"Q\n");
	return ;
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
