#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vi;
const int maxn=3e5;
map<pii,int>tim;
int fa[maxn*2+10];
vi p[maxn*4+10];
int x[maxn*2+10];
int y[maxn*2+10];
int siz[maxn*2+10];
ll ans=0;
ll res[maxn+10];
const int N=3e5;
void init(){
	for (int i=1;i<=N;++i)
		fa[i]=i,siz[i]=x[i]=1;
	for (int i=N+1;i<=2*N;++i)
		fa[i]=i,siz[i]=y[i]=1;
}
int find(int x){
	return fa[x]==x?x:find(fa[x]);
}
void updata(int l,int r,int ql,int qr,pair<int,int>point,int rt){
	if(l>=ql&&r<=qr){
		p[rt].pb(point);
	//	cout<<l<<" "<<r<<" "<<ql<<" "<<qr<<endl;
		return ;
	}
	int mid=(l+r)/2;
	if(ql<=mid) updata(l,mid,ql,qr,point,rt*2);
	if(qr>mid) updata(mid+1,r,ql,qr,point,rt*2+1);
}
void qry(int l,int r,int rt){
	stack<int> s;
	for (auto i:p[rt]){
		int fx=find(i.fi),fy=find(i.se);
		if (fx==fy)
			continue;
		ans+=ll(x[fx])*y[fy]+ll(x[fy])*y[fx];
		if (siz[fx]>siz[fy])
			swap(fx,fy);
		s.push(fx);
		fa[fx]=fy;
		siz[fy]+=siz[fx];
		x[fy]+=x[fx];
		y[fy]+=y[fx];
	}
	if (l==r)
		res[l]=ans;
	else{
		int m=(l+r)>>1;
		qry(l,m,rt<<1);
		qry(m+1,r,rt<<1|1);
	}
	while (s.size()!=0){
		int fx=s.top();
		s.pop();
		int fy=fa[fx];
		fa[fx]=fx;
		siz[fy]-=siz[fx];
		x[fy]-=x[fx];
		y[fy]-=y[fx];
		ans-=ll(x[fx])*y[fy]+ll(x[fy])*y[fx];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	init();
	rep(i,1,n+1){
		int x,y;
		cin >> x >> y;
		y+=maxn;
		pair<int,int> point=mp(x,y);
		if(tim[point]){
			updata(1,n,tim[point],i-1,point,1);
			tim[point]=0;
		}
		else tim[point]=i;
	}
	for(auto i:tim){
		if(i.se){
			updata(1,n,i.se,n,i.fi,1);
			//cout<<i.se<<" "<<endl;
		}
	}
	qry(1,n,1);
	rep(i,1,n+1){
		cout<<res[i]<<" ";
	}
	return 0;
}