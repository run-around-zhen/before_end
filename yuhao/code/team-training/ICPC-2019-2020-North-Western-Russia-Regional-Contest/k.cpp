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
const int maxn=1005;
char str[maxn][maxn];
int high[maxn],down[maxn];
bool vis[maxn][maxn];
vector<pair<int, int> > v ;
int main()
{
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ans=0;
	int n,m;
	int x,y;
	cin>>n>>m;
	rep(i,0,n) cin>>str[i];
	rep(i,0,n) rep(j,0,m)
		if(str[i][j]=='A') x=i,y=j;
	//dd(x);de(y);
	high[y]=x;
	while(high[y]-1>=0&&str[high[y]-1][y]=='.') high[y]--;
	down[y]=x;
	while(down[y]+1<n&&str[down[y]+1][y]=='.') down[y]++;
//	dd(high[y]);de(down[y]);
	//dd(x);de(y);
	
	for(int i=y-1;i>=0;i--)
	{
		if(str[x][i]!='.'||down[i+1]==-1)
		{
			down[i]=high[i]=-1;
			continue;
		}
		high[i]=x;
		while(high[i]-1>=0&&str[high[i]-1][i]=='.') high[i]--;
		down[i]=x;
		while(down[i]+1<n&&str[down[i]+1][i]=='.') down[i]++;
		high[i]=max(high[i],high[i+1]);
		down[i]=min(down[i],down[i+1]);
	}
	for(int i=y+1;i<m;i++)
	{
		if(str[x][i]!='.'||down[i-1]==-1)
		{
			down[i]=high[i]=-1;
			continue;
		}
		high[i]=x;
		while(high[i]-1>=0&&str[high[i]-1][i]=='.') high[i]--;
		down[i]=x;
		while(down[i]+1<n&&str[down[i]+1][i]=='.') down[i]++;
		high[i]=max(high[i],high[i-1]);
		down[i]=min(down[i],down[i-1]);
	}
	int s=0,l,r;
	rept(i,0,y)
	{
		if(down[i]==-1) continue;
		rep(j,y,m)
		{
			if(down[j]==-1) continue;
			int u1=max(high[i],high[j]),d1=min(down[i],down[j]);
			if((d1-u1+1)*(j-i+1)>s)
			{
				s=(d1-u1+1)*(j-i+1);
				l=i;
				r=j;
			}
		}
	}
	//dd(l);dd(r);
	//dd(high[l]);dd(high[r]);dd(down[l]);de(down[r]);
	
	rept(j,l,r)
	{
		rept(i,max(high[l],high[r]),min(down[l],down[r]))
		{
			if(i==x&&j==y) continue;
			str[i][j]='a';
		}
	}
	
//	rep(i,0,n) cout<<str[i]<<"\n";
	rep(i, 0, n){
		rep(j, 0, m){
			if(str[i][j] >= 'B' && str[i][j] <='Z'){
				v.pb(mp(i, j));
			}
		}
	}
	random_shuffle(all(v));
	for(auto tt : v){

		int i = tt.fi;
		int j = tt.se;
		//cout << i << " " << j << endl;
			if(str[i][j]>='B'&&str[i][j]<='Z')
			{
				int up=i,down=i;
				while(up-1>=0&&str[up-1][j]=='.') up--;
				while(down+1<n&&str[down+1][j]=='.') down++;
				int l=j,r=j;
				for(int ii=l-1;ii>=0;ii--)
				{
					bool flag=1;
					rept(jj,up,down)
					{
						if(str[jj][ii]!='.')
						{
							flag=0;
							break;
						}
					}
					if(!flag) break;
					l=ii;
				}
				for(int ii=r+1;ii<m;ii++)
				{
					bool flag=1;
					rept(jj,up,down)
					{
						if(str[jj][ii]!='.')
						{
							flag=0;
							break;
						}
					}
					if(!flag) break;
					r=ii;
				}
			//	if(str[i][j]=='L') dd(up),dd(down),dd(l),de(r);
				rept(jj,l,r)
					rept(ii,up,down)
					{
						if(ii==i&&jj==j) continue;
						str[ii][jj]=str[i][j]-'A'+'a';
					}
			}
		
	}
	
	rep(i,0,n) cout<<str[i]<<"\n";
	return 0;
}