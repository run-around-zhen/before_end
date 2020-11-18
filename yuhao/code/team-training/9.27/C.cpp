#include<bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rept(i,x,y) for(int i=x;i<=y;i++)
#define mes(a,b) memset(a,b,sizeof a)
#define dd(x) cout<<#x<<"="<<x<<" "
#define de(x) cout<<#x<<"="<<x<<"\n"
typedef long long ll;
const int mod=1e9+7;
const int maxn=15;
int n;
int cnt[maxn][maxn];
int ans[maxn];
bool vis[maxn];
int p[maxn];

void dfs(int id,int n)
{
	if(id>n)
	{
		return ;
	//	cout<<"?";
		ll val=1;
		for(int i=1;i<=n/2;i++)
		{
			val=val*cnt[p[i*2-1]][p[i*2]]%mod;
			ans[i]=(ans[i]+val)%mod;
		}
		return ;
	}
	if(id==1)
	{
		rep(i,1,n)
		{
			vis[i]=1;
			p[id]=i;
			dfs(id+1,n);
			vis[i]=0;
		}
	}
	else if(id%2==1)
	{
		rep(i,p[id-2]+1,n)
		{
			if(!vis[i])
			{
				vis[i]=1;
				p[id]=i;
				dfs(id+1,n);
				vis[i]=0;
			}
		}
	}
	else
	{
		rept(i,p[id-1]+1,n)
		{
			if(!vis[i])
			{
				vis[i]=1;
				p[id]=i;	
				ll val=1;
				for(int i=1;i<=id/2;i++)
				{
					val=val*cnt[p[i*2-1]][p[i*2]]%mod;
				}
				//dd(id);de(val);
				ans[id/2]=(ans[id/2]+val)%mod;
				
				dfs(id+1,n);
				vis[i]=0;
			}
		}
	}
}

void test()
{
	int n,q;
	n=10;q=30000;
	//cin>>n>>q;
	while(q--)
	{
		char op;
		int a,b;
	//	cin>>op>>a>>b;
		op='+';
		a=1;
		b=3;
		mes(ans,0);
		if(op=='-') cnt[a][b]--,cnt[b][a]--;
		else cnt[a][b]++,cnt[b][a]++;
		dfs(1,n);
	/*	rept(i,1,n/2)
		{
			cout<<ans[i];
			if(i==n/2) cout<<"\n";
			else cout<<" ";
		}*/
	}
	cout << "!!" << endl;
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
