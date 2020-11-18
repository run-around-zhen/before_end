#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int  i = (a); i < b; i ++)
#define rept(i,a,b) for(int i=a;i<=b;i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); i++)
#define dd(x) cout<<#x<<"="<<x<<" "
#define de(x) cout<<#x<<"="<<x<<"\n"
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
const int maxn=505;

ld s[maxn];
ld ans[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	rept(i,1,n) cin>>s[i];
	rept(i,1,n)
	{
		ans[i]=0;
		ans[i]+=s[i]*((ld)k/n);
//		de(ans[i]);
		ld p=(ld)k/n;
		ld div=n-1,del=n-k;
		for(int j=i-1;del>0;j--)
		{
			if(!j) j+=n;
//			if(i==1) de(j);
			p*=del/div;
			del--;
			div--;
			ans[i]+=s[j]*p;
		}
	}
	rept(i,1,n)
	{
		cout<<fixed<<setprecision(10)<<ans[i];
		if(i==n) cout<<"\n";
		else cout<<" ";
	}
	return 0;
}
