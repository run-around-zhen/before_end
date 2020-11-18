
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int  i = (a); i < b; i ++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); i++)
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
const double eps=1e-5;

int read()
{
	double x;
	cin>>x;
	int ans=x*100+eps;
	return ans;
}
int a[5];

int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	rep(i,0,4) a[i]=read();
	int val=read();
	sort(a,a+4);
	if(a[1]+a[2]+a[3]<=3*val)
	{
		cout<<"infinite\n";
		return 0;
	}
	if(a[0]+a[1]+a[2]>3*val)
	{
		cout<<"impossible\n";
		return 0;
	}
	int ans=val*3-a[1]-a[2];
	cout<<ans/100<<".";
	printf("%02d\n",ans%100);
	return 0;
}
