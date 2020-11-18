#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll,ll> pii;
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
int ans;
string s;
int n;

void solve1(int len)
{
	int minv,maxv;
	int val=10*(s[len-2]-'0')+s[len-1]-'0';
	minv=maxv=val;
	for(int i=len;i<n;i+=len)
	{
		for(int j=i;j<i+len-2;j++)
		{
			if(s[j]!=s[j-len]) return ;
		}
		val=10*(s[i+len-2]-'0')+s[i+len-1]-'0';
		maxv=max(maxv,val);
		minv=min(minv,val);
	}
//	dd(len);dd(maxv);de(minv);
	ans=min(ans,maxv-minv);
}
void solve2()
{
	int i;
	int maxv=0,minv=99;
	for(i=0;i<n;)
	{
		if(s[i]=='1')
		{
			if(i+1==n) return ;
			maxv=max(maxv,10+s[i+1]-'0');
			minv=min(minv,10+s[i+1]-'0');
			i+=2;
		}
		else
		{
			maxv=max(maxv,s[i]-'0');
			minv=min(minv,s[i]-'0');
			i++;
		}
	}
	ans=min(ans,maxv-minv);
}

void solve3(int len)//len and len+1
{
	if(len==n||(len==n-1&&s[0]=='1')) return ;
	int i,minv=10,maxv=0;
	for(i=0;i<n;)
	{
	//	dd(i);
		if(s[i]=='1')
		{
			for(int j=i+1;j<i+len;j++) if(s[j]!='0') return ;
			i+=len;
			if(i>n) return ;
			maxv=max(maxv,s[i]-'0');
			i++;
		}
		else if(s[i]=='9')
		{
			for(int j=i;j<i+len-1;j++) if(s[j]!='9') return ;
			i+=len;
			if(i>n) break;
			minv=min(minv,s[i-1]-'0');
		}
		else return ;
	}
//	dd(maxv);de(minv);
	ans=min(ans,10+maxv-minv);
}

void test()
{
	ans=10;
	cin>>n>>s;
	if(n==2)
	{
		cout<<abs(s[0]-s[1])<<"\n";
		return ;
	}
	int minv=9,maxv=0;
	rep(i,0,n)
	{
		minv=min(minv,s[i]-'0');
		maxv=max(maxv,s[i]-'0');
	}
	ans=maxv-minv;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			solve1(i);
			solve1(n/i);
		}
	}
	solve2();
	rep(p1,0,n)
	{
		if(s[p1]=='0')
		{
			if(p1==0||s[p1-1]!='1') break;
			int p2=p1;
			while(p2<n&&s[p2]=='0') p2++;
			if(p2==n||s[p2]=='9') solve3(p2-p1);
			else solve3(p2-p1+1);
			break;
		}
	}
	cout<<ans<<"\n";
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