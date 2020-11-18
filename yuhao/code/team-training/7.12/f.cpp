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

const int maxn=1e6+5;
int n;
int x[maxn],y[maxn],c[maxn],sa[maxn],rk[maxn];
//unordered_map<int,int> x,y,c,sa,rk;
int a[maxn];
char s[maxn];
int nex[maxn];
vector<int> v[maxn];


void get_sa()
{
	int m=0;
	int lasta=-1,lastb=-1;
	rept(i,1,n)
	{
		if(s[i]=='a')
		{
			if(lasta==-1) a[i]=0;
			else a[i]=i-lasta;
			lasta=i;
		}
		else
		{
			if(lastb==-1) a[i]=0;
			else a[i]=i-lastb;
			lastb=i;
		}
		m=max(m,a[i]);
	}
	for(int i=1;i<=n;i++) ++c[x[i]=a[i]];
	for(int i=2;i<=m;i++) c[i]+=c[i-1];
	for(int i=n;i>=1;i--) sa[c[x[i]]--]=i;
	for(int k=1;k<=n;k<<=1)
	{
		int num=0;
		for(int i=n-k+1;i<=n;i++) y[++num]=i;
		for(int i=1;i<=n;i++) if(sa[i]>k) y[++num]=sa[i]-k;
		for(int i=1;i<=m;i++) c[i]=0;
		for(int i=1;i<=n;i++) ++c[x[i]];
		for(int i=2;i<=m;i++) c[i]+=c[i-1];
		for(int i=n;i>=1;i--) sa[c[x[y[i]]]--]=y[i],y[i]=0;
		swap(x,y);
		x[sa[1]]=1;
		num=1;
		for(int i=2;i<=n;i++)
			x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]);
		if(num==n) break;
		m=num;
	}
}

bool comp2(int a,int b)
{
	return rk[a]<rk[b];
}

int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	ios::sync_with_stdio(false);
	int qq = 0;
//	cin.tie(0);
	while(1)
	{
	qq ++;
		//x.clear();y.clear();sa.clear();rk.clear();c.clear();
		n = 20;
		//cout << qq << endl;
		int start = clock();
		rept(i,0,n) v[i].clear();
		rep(i, 1, n + 1) s[i] = (char)(rand()% 2 + 'a');
		//scanf("%s",s+1);
		//cin>>(s+1);
		get_sa();
		if(1.0 *(clock() - start) / CLOCKS_PER_SEC > 0.1){
			cout << "!!!!!" << endl;
			return 0;
		}
		for(int i=1;i<=n;i++) rk[sa[i]]=i;
		rk[n+1]=0;
		rk[n+2]=-1;
	//	rept(i,1,n) cout<<rak[i]<<" ";cout<<"\n";
		int nexta=-1,nextb=-1;
		for(int i=n;i>=1;i--)
		{
			if(s[i]=='a')
			{
				nex[i]=nextb;
				nexta=i;
			}
			else
			{
				nex[i]=nexta;
				nextb=i;
			}
			if(nex[i]==-1)
			{
				v[n-i].pb(n+2);
				//dd(i);de(n-i);
			}
			else
			{
				v[nex[i]-i-1].pb(nex[i]+1);
				//dd(i);de(nex[i]-i-1);
			}
		}
		bool flag=0;
		rept(i,0,n)
		{
			if(!v[i].size()) continue;
			sort(all(v[i]),comp2);
			rep(j,0,v[i].size())
			{
				if(flag) printf(" ");
				else flag=!flag;
				printf("%d",v[i][j]-i-2);
				//cout<<v[i][j]-i-2;
			}
		}
		
		printf("\n");
		rept(i,0,4 * n) nex[i] = x[i]=y[i]=sa[i]=rk[i]=c[i]=0;
	}
	return 0;
}