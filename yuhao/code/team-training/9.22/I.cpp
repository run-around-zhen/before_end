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
const int maxn=5e6+5;
char s[maxn],a[maxn],b[maxn];
vector<int> prime;
bool vis[maxn];
int kmp[maxn],la,lb;
bool solve()
{
	//la=strlen(a+1),lb=strlen(b+1);
	int j=0;
	for(int i=2;i<=lb;i++)
	{
		while(j&&b[i]!=b[j+1]) j=kmp[j];
		if(b[j+1]==b[i]) j++;
		kmp[i]=j;
	}
	j=0;
	rept(i,1,la)
	{
		while(j&&b[j+1]!=a[i]) j=kmp[j];
		if(b[j+1]==a[i]) j++;
		if(j==lb) return 1;
	}
	return 0;
}

void init(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) prime.pb(i);
		for(int j=0;i<prime.size();j++)
		{
			if(i*prime[j]>n) break;
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
int n;

bool check(int len)
{
	la=len*2,lb=len;
	for(int i=1;i<=len;i++) a[i]=a[i+len]=s[i];
//	for(int i=1;i<=len*2;i++) cout<<a[i];cout<<"\n";
	for(int i=len;i<n;i+=len)
	{
		for(int j=1;j<=len;j++) b[j]=s[i+j];
		//for(int j=1;j<=len;j++) cout<<b[j];cout<<"\n";
		if(!solve()) return 0;
	}
	return 1;
}
void test()
{
	cin>>n;
	cin>>(s+1);
	if(n==1)
	{
		cout<<"No\n";
		return ;
	}
	bool flag=1;
	rept(i,2,n) if(s[i]!=s[1]) flag=0;
	if(flag)
	{
		cout<<"Yes\n";
		return ;
	}
	rep(i,0,prime.size())
	{
		if(prime[i]*prime[i]>n) break;
		if(n%prime[i]==0)
		{
			//dd(n);de(prime[i]);
			if(check(prime[i])||check(n/prime[i]))
			{
				cout<<"Yes\n";
				return ;
			}
		}
	}
	cout<<"No\n";
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(5000000);
	int q;
	cin>>q;
	while(q--) test();
	return 0;
}
