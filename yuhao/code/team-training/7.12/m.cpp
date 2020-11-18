18计5-张咏真  00:56:11
改了
18-苏锦程  00:56:14
之前题目不是很水吗
18计5-张咏真  00:56:21
一个集合n个数、
18计5-张咏真  00:56:24
1-n
18计5-张咏真  00:56:32
然后现在有一个序列了
18计5-张咏真  00:56:41
在往里面加数字
18计5-张咏真  00:57:18
然后达到上升子序列长度达到k的话游戏结束
18计5-张咏真  01:02:43
我先睡了
18计5-张咏真  01:02:49
不肝了
18-苏锦程  02:03:09
心态有点崩
18-苏锦程  02:03:13
改了一堆
18-苏锦程  02:03:26
我他妈居然还是整段红的
Augest  02:04:17
郑晨阳还在王者
Augest  02:04:24
还没发我题面
Augest  02:04:29
我他妈
18-苏锦程  11:54:21
《因为太困了就让咏真AK了》
18计5-张咏真  11:54:32
？？？
Augest  11:55:27
晚上还有视频讲解？
18计5-张咏真  11:58:08
【链接】如何评价知乎用户@ftiasch？
https://www.zhihu.com/question/325527248/answer/808477277
18计5-张咏真  13:01:15
abaab
0 0 2 1 2
0 0 1 2
0 1 0
0 0
0
18-苏锦程  13:15:10
1/2772
Augest  13:36:19
[图片]
Augest  14:35:44
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
typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int q = 10;
	while(q--){
	int n = 100000;
	cout << n << endl;
	rep(i, 1, n + 1){
		cout << (char)(rand() % 2 + 'a');
	}
	cout << endl;
}
	return 0;
}
18-苏锦程  14:36:11
// [0,n) , init!! , inf modify
template<class U,class V>
struct MCMF{
    static const int N = 6000, M = 201010;
    int h[N], ing[N], pre[N], to[M], ne[M], e, s, t, n;
    U cap[M]; V dis[N], cost[M];
    void ini(int _n = N){ fill(h , h + (n=_n) , -1);e = 0;}
    void liu(int u,int v,U c,V w){ to[e] = v;ne[e] = h[u];cap[e] = c;cost[e] = w;h[u] = e++;}
    void link(int u,int v,U c,V w){ liu(u,v,c,w);liu(v,u,0,-w); }
    bool spfa(){
        queue<int> Q;
        fill(dis, dis+n, inf);
        Q.push(s), ing[s] = 1, dis[s] = 0;
        while(!Q.empty()){
            int c = Q.front(); Q.pop(); ing[c] = 0;
            for(int k = h[c]; ~k; k = ne[k]) if (cap[k] > 0) {
                int v = to[k];
                if(dis[c] + cost[k] < dis[v]){
                    dis[v] = dis[c] + cost[k];
                    pre[v] = k;
                    if(!ing[v]) Q.push(v) , ing[v] = 1;
                }
            }
        }
        return dis[t] != inf;
    }
    U flow; V mincost;
    pair<U, V> run(int _s,int _t){
        s = _s , t = _t;
        flow = mincost = 0;
        while(spfa()){
            U pl = inf; int p, k;
            for(p = t;p != s;p = to[k^1]) pl = min(pl, cap[k = pre[p]]);
            for(p = t;p != s;p = to[k^1]) cap[k = pre[p]] -= pl, cap[k^1] += pl;
			mincost += pl * dis[t];
            flow += pl;
        }
        return mp(flow, mincost);
    }
};
Augest  14:47:51
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
typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int inf = 1e9;
template<class U, class V>
struct MCMF{
	static const int N = 6000, M = 201010;
	int h[N], ing[N], pre[N], to[M], ne[M], e, s, t, n;
	U cap[M]; V dis[N], cost[M];
	void ini(int _n = N){ fill(h, h + (n =_n), -1); e = 0;}
	void liu(int u, int v, U c, V w){
		to[e] = v;
		ne[e] = h[u];
		cap[e] = c;
		cost[e] = w;
		h[u] = e++;
	}
	void link(int u, int v, U c, V w){
		liu(u, v, c, w);
		liu(v, u, 0, -w);
	}
	bool spfa(){
		queue<int> Q;
		fill(dis, dis + n, inf);
		Q.push(s),ing[s] = 1, dis[s] = 0;
		while(!Q.empty()){
			int c = Q.front(); Q.pop(); ing[c] = 0;
			for(int k = h[c]; ~k; k = ne[k]) if(cap[k] > 0){
				int v = to[k];
				if(dis[c] + cost[k] < dis[v]){
					dis[v] = dis[c] + cost[k];
					pre[v] = k;
					if(!ing[v]) Q.push(v), ing[v] = 1;
				}
			}
		}
		return dis[t] != inf;
	}
	U flow; V mincost;
	pair<U, V> run(int _s, int _t){
		s = _s, t = _t;
		flow = mincost = 0;
		while(spfa()){
			U pl = inf; int p, k;
			for(p = t; p != s; p = to[k ^ 1]) pl = min(pl, cap[k = pre[p]]);
			for(p = t; p != s; p = to[k ^ 1]) cap[k = pre[p]] -= pl, cap[k ^ 1] += pl;
			mincost += pl * dis[t];
			flow += pl;
		}
		return mp(flow, mincost);
	}

};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	return 0;
}
Augest  14:54:51
[图片]
Augest  15:02:39
[图片]
Augest  15:03:46
[图片]
18计5-张咏真  15:04:21
8
bbaaaaab
10
abaabbbbaa
4
bbba
4
baab
8
aababbbb
2
ba
Augest  15:04:28
[图片]
18计5-张咏真  15:04:55
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
int n,m;
int tax[maxn],rak[maxn],tp[maxn],sa[maxn];
char s[maxn];
int nex[maxn];
vector<int> v[maxn];

void sor(int a[],int b[]){
    for(int i=0;i<=m;i++)tax[i]=0;
    for(int i=1;i<=n;i++)tax[a[i]]++;
    for(int i=1;i<=m;i++)tax[i]+=tax[i-1];
    for(int i=n;i>=1;i--)sa[tax[a[b[i]]]--]=b[i];
}

bool comp(int r[],int a,int b,int k){
    return r[a]==r[b]&&r[a+k]==r[b+k];
}

void get_sa(int a[],int b[]){
	m=1e5+5;
    /*for(int i=1;i<=n;i++)
    	a[i]=s[i],b[i]=i;
    	*/
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
		b[i]=i;
	}
    sor(a,b);
    for(int p=0,j=1;p<n;j<<=1,m=p)
	{
        p=0;
        for(int i=1;i<=j;i++) b[++p]=n-j+i;
        for(int i=1;i<=n;i++)
			if(sa[i]>j) b[++p]=sa[i]-j;
        sor(a,b);
        int *t=a;a=b;b=t;
        a[sa[1]]=p=1;
        for(int i=2;i<=n;i++)
        	a[sa[i]]=comp(b,sa[i],sa[i-1],j)?p:++p;
    }
}

bool comp2(int a,int b)
{
	return rak[a]<rak[b];
}

int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n)
	{
		rept(i,0,n*3) tax[i]=rak[i]=tp[i]=sa[i]=0;
		cin>>(s+1);
		rept(i,0,n) v[i].clear();
		get_sa(rak,tp);
		for(int i=1;i<=n;i++) rak[sa[i]]=i;
		rak[n+1]=0;
		rak[n+2]=-1;
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
				v[n-i].pb(i);
				//dd(i);de(n-i);
			}
			else
			{
				v[nex[i]-i-1].pb(i);
				//dd(i);de(nex[i]-i-1);
			}
		}
		bool flag=0;
		rept(i,0,n)
		{
			if(!v[i].size()) continue;
			rep(j,0,v[i].size())
			{
//				dd(i);de(v[i][j]);
				v[i][j]+=i+2;
			}
			sort(all(v[i]),comp2);
			rep(j,0,v[i].size())
			{
				if(flag) cout<<" ";
				else flag=!flag;
				cout<<v[i][j]-i-2;
			}
		}
		cout<<"\n";
	}
	return 0;
}
18计5-张咏真  15:05:18
2
aa
3
aba
3
aab
5
bbbbb
2
ab
18计5-张咏真  15:05:22
8
bbaaaaab
10
abaabbbbaa
4
bbba
4
baab
8
aababbbb
2
ba
Augest  15:05:35
[图片]
18计5-张咏真  15:05:57
[图片]
Augest  15:09:09
[图片]
Augest  15:10:22
[图片]
18计5-张咏真  15:13:01
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

const int maxn=3e5+5;
int n,m;
int tax[maxn],rak[maxn],tp[maxn],sa[maxn];
char s[maxn];
int nex[maxn];
vector<int> v[maxn];

void sor(int a[],int b[]){
    for(int i=0;i<=m;i++)tax[i]=0;
    for(int i=1;i<=n;i++)tax[a[i]]++;
    for(int i=1;i<=m;i++)tax[i]+=tax[i-1];
    for(int i=n;i>=1;i--)sa[tax[a[b[i]]]--]=b[i];
}

bool comp(int r[],int a,int b,int k){
    return r[a]==r[b]&&r[a+k]==r[b+k];
}

void get_sa(int a[],int b[]){
	m=1e5+5;
    /*for(int i=1;i<=n;i++)
    	a[i]=s[i],b[i]=i;
    	*/
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
		b[i]=i;
	}
    sor(a,b);
    for(int p=0,j=1;p<n;j<<=1,m=p)
	{
        p=0;
        for(int i=1;i<=j;i++) b[++p]=n-j+i;
        for(int i=1;i<=n;i++)
			if(sa[i]>j) b[++p]=sa[i]-j;
        sor(a,b);
        int *t=a;a=b;b=t;
        a[sa[1]]=p=1;
        for(int i=2;i<=n;i++)
        	a[sa[i]]=comp(b,sa[i],sa[i-1],j)?p:++p;
    }
}

bool comp2(int a,int b)
{
	return rak[a]<rak[b];
}

int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n)
	{
		rept(i,0,n*3) tax[i]=rak[i]=tp[i]=sa[i]=0;
		rept(i,0,n) v[i].clear();
		cin>>(s+1);
		get_sa(rak,tp);
		for(int i=1;i<=n;i++) rak[sa[i]]=i;
		rak[n+1]=0;
		rak[n+2]=-1;
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
				v[n-i].pb(i);
				//dd(i);de(n-i);
			}
			else
			{
				v[nex[i]-i-1].pb(i);
				//dd(i);de(nex[i]-i-1);
			}
		}
		bool flag=0;
		rept(i,0,n)
		{
			if(!v[i].size()) continue;
			rep(j,0,v[i].size())
			{
//				dd(i);de(v[i][j]);
				v[i][j]+=i+2;
			}
			sort(all(v[i]),comp2);
			rep(j,0,v[i].size())
			{
				if(flag) cout<<" ";
				else flag=!flag;
				cout<<v[i][j]-i-2;
			}
		}
		
		cout<<"\n";
	}
	return 0;
}
18计5-张咏真  15:21:05
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

const int maxn=3e5+5;
int n,m;
int tax[maxn],rak[maxn],tp[maxn],sa[maxn];
char s[maxn];
int nex[maxn];
vector<int> v[maxn];

void sor(int a[],int b[]){
    for(int i=0;i<=m;i++)tax[i]=0;
    for(int i=1;i<=n;i++)tax[a[i]]++;
    for(int i=1;i<=m;i++)tax[i]+=tax[i-1];
    for(int i=n;i>=1;i--)sa[tax[a[b[i]]]--]=b[i];
}

bool comp(int r[],int a,int b,int k){
    return r[a]==r[b]&&r[a+k]==r[b+k];
}

void get_sa(int a[],int b[]){
	m=0;
    /*for(int i=1;i<=n;i++)
    	a[i]=s[i],b[i]=i;
    	*/
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
		m=max(m,a[i]+1);
		b[i]=i;
	}
    sor(a,b);
    for(int p=0,j=1;p<n;j<<=1,m=p)
	{
        p=0;
        for(int i=1;i<=j;i++) b[++p]=n-j+i;
        for(int i=1;i<=n;i++)
			if(sa[i]>j) b[++p]=sa[i]-j;
        sor(a,b);
        int *t=a;a=b;b=t;
        a[sa[1]]=p=1;
        for(int i=2;i<=n;i++)
        	a[sa[i]]=comp(b,sa[i],sa[i-1],j)?p:++p;
    }
}

bool comp2(int a,int b)
{
	return rak[a]<rak[b];
}

int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n)
	{
		rept(i,0,n*3) tax[i]=rak[i]=tp[i]=sa[i]=0;
		rept(i,0,n) v[i].clear();
		cin>>(s+1);
		get_sa(rak,tp);
		for(int i=1;i<=n;i++) rak[sa[i]]=i;
		rak[n+1]=0;
		rak[n+2]=-1;
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
				v[n-i].pb(i);
				//dd(i);de(n-i);
			}
			else
			{
				v[nex[i]-i-1].pb(i);
				//dd(i);de(nex[i]-i-1);
			}
		}
		bool flag=0;
		rept(i,0,n)
		{
			if(!v[i].size()) continue;
			rep(j,0,v[i].size())
			{
//				dd(i);de(v[i][j]);
				v[i][j]+=i+2;
			}
			sort(all(v[i]),comp2);
			rep(j,0,v[i].size())
			{
				if(flag) cout<<" ";
				else flag=!flag;
				cout<<v[i][j]-i-2;
			}
		}
		
		cout<<"\n";
	}
	return 0;
}
Augest  15:29:32
struct ST{
	int n,log[N],dp[25][N]; int *a;
	int h(int x,int y) { return a[x]<=a[y] ? x:y; }
	void Init(int _n,int *_a){
		n=_n,a=_a,log[0]=-1; rep(i,1,n) log[i]=log[i>>1]+1,dp[0][i]=i;
		rep(i,1,log[n]) rep(j,1,n+1-(1<<i)) dp[i][j]=h(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
	}
	int Q(int l,int r) { int L=log[r-l+1]; return h(dp[L][l],dp[L][r+1-(1<<L)]); }
}; 

struct SA{
	int t1[N],t2[N],cc[N],x[N],sa[N],R[N],H[N],h[N],n,m,cnt,str_cnt,num0; char *s; int num[1005],home[N]; //ST T;
	inline bool cmp(int *y,int a,int b,int k){
		return y[a]==y[b] && (a+k>=n ? -1:y[a+k])==(b+k>=n ? -1:y[b+k]);
	}
	inline void init_sa() {
		int *x=t1,*y=t2;
		rep(i,0,m-1) cc[i]=0;
		rep(i,0,n-1) ++cc[x[i]=s[i]];
		rep(i,1,m-1) cc[i]+=cc[i-1];
		per(i,n-1,0) sa[--cc[x[i]]]=i;
		for(int k=1,p=0; k<=n; k<<=1,p=0){
			rep(i,n-k,n-1) y[p++]=i;
			rep(i,0,n-1) if(sa[i]>=k) y[p++]=sa[i]-k;
			rep(i,0,m-1) cc[i]=0;
			rep(i,0,n-1) ++cc[x[y[i]]];
			rep(i,1,m-1) cc[i]+=cc[i-1];
			per(i,n-1,0) sa[--cc[x[y[i]]]]=y[i];
			swap(x,y),m=1,x[sa[0]]=0;
			rep(i,1,n-1) x[sa[i]]=cmp(y,sa[i],sa[i-1],k) ? m-1:m++;
			if(m>=n) break;
		}
	}
	inline void init_H(){
		rep(i,0,n-1) R[sa[i]]=i;
		int k=H[0]=s[n]=0;
		rep(i,0,n-1) {
			if (!R[i]) continue;
			int j=sa[R[i]-1];
			if (k) k--;
			while (s[i+k]==s[j+k]) k++;
			h[i]=H[R[i]]=k;
		}
	}
	/*inline int Q_lcp(int x,int y) {
		if (R[x]>R[y]) swap(x,y);
		return x==y ? n-x : H[T.Q(R[x]+1,R[y])];
	}*/
	/*inline int Q_lcs(int x,int y) {
		int ans=0,px=-1,py=-1;
		rep(i,0,n-1) {
			if (home[sa[i]]==x) {
				px=i; if (py!=-1) ans=max(ans,H[T.Q(py+1,i)]);
			}
			if (home[sa[i]]==y) {
				py=i; if (px!=-1) ans=max(ans,H[T.Q(px+1,i)]);
			}
		}
		return ans;
	} */
	inline void divide_group(int k,int x[]) {
		x[0]=cnt=0; rep(i,1,n-1) if (H[i]<k) x[++cnt]=i; x[++cnt]=n;
	}
	inline void count(int l,int r) {
		mem(num,0); num0=0; rep(i,l,r) num0+=!(num[home[sa[i]]]++); num0-=(num[0]>0);
	} 
	inline bool check_group(int l,int r) {
		//...
	}
	inline bool check(int ans){
		divide_group(ans,x);
		rep(i,1,cnt) if (check_group(x[i-1],x[i]-1)) return true; return false;
	}
	inline int binary(int l,int r) {
		int ans=-1,mid;
		while (l<=r) {
			mid=(l+r)>>1;
			if (check(mid)) {
				ans=mid;
				l=mid+1;
			} else r=mid-1;
		}
		return ans;
	}
	inline int Q(){
		//...
	}
	inline void Insert(char _s[],int op=0,int _n=0){
		if (n) home[n]=0,s[n++]=str_cnt+' '; if (!_n) _n=strlen(_s); ++str_cnt;
		if (!op) rep(i,0,_n-1) home[n]=str_cnt,s[n++]=_s[i]; else
				 per(i,_n-1,0) home[n]=str_cnt,s[n++]=_s[i];
	}
	SA(){ s=new char[N]; }
	inline void Clear() { n=str_cnt=0; }
	inline void Init(char _s[]=NULL,int _n=0,int _m='z'+1005){
		if (_s!=NULL) s=_s,n=_n ? _n : strlen(s);  m=_m;
		init_sa(); init_H(); //T.Init(n-1,H);
	}
};
Augest  15:29:58
struct SA{
	int t1[N],t2[N],cc[N],x[N],sa[N],R[N],H[N],h[N],n,m; char *s;
	inline bool cmp(int *y,int a,int b,int k){
		return y[a]==y[b] && (a+k>=n ? -1:y[a+k])==(b+k>=n ? -1:y[b+k]);
	}
	inline void init_sa() {
		int *x=t1,*y=t2;
		rep(i,0,m-1) cc[i]=0;
		rep(i,0,n-1) ++cc[x[i]=s[i]];
		rep(i,1,m-1) cc[i]+=cc[i-1];
		per(i,n-1,0) sa[--cc[x[i]]]=i;
		for(int k=1,p=0; k<=n; k<<=1,p=0){
			rep(i,n-k,n-1) y[p++]=i;
			rep(i,0,n-1) if(sa[i]>=k) y[p++]=sa[i]-k;
			rep(i,0,m-1) cc[i]=0;
			rep(i,0,n-1) ++cc[x[y[i]]];
			rep(i,1,m-1) cc[i]+=cc[i-1];
			per(i,n-1,0) sa[--cc[x[y[i]]]]=y[i];
			swap(x,y),m=1,x[sa[0]]=0;
			rep(i,1,n-1) x[sa[i]]=cmp(y,sa[i],sa[i-1],k) ? m-1:m++;
			if(m>=n) break;
		}
	}
	inline void init_H(){
		rep(i,0,n-1) R[sa[i]]=i;
		int k=H[0]=s[n]=0;
		rep(i,0,n-1) {
			if (!R[i]) continue;
			int j=sa[R[i]-1];
			if (k) k--;
			while (s[i+k]==s[j+k]) k++;
			h[i]=H[R[i]]=k;
		}
	}
	inline void Init(char _s[],int _n,int _m='z'+1){
		s=_s,n=_n,m=_m; init_sa(); init_H();
	}
};
18计5-张咏真  15:41:36
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

const int maxn=3e5+5;
int n,m;
//int x[maxn],y[maxn],c[maxn],sa[maxn],rk[maxn];
unordered_map<int,int> x,y,c,sa,rk;
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n)
	{
		x.clear();y.clear();sa.clear();rk.clear();c.clear();
		rept(i,0,n) v[i].clear();
		cin>>(s+1);
	//	cout<<(s+1)<<"\n";
		get_sa();
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
				v[n-i].pb(i);
				//dd(i);de(n-i);
			}
			else
			{
				v[nex[i]-i-1].pb(i);
				//dd(i);de(nex[i]-i-1);
			}
		}
		bool flag=0;
		rept(i,0,n)
		{
			if(!v[i].size()) continue;
			rep(j,0,v[i].size())
			{
//				dd(i);de(v[i][j]);
				v[i][j]+=i+2;
			}
			sort(all(v[i]),comp2);
			rep(j,0,v[i].size())
			{
				if(flag) cout<<" ";
				else flag=!flag;
				cout<<v[i][j]-i-2;
			}
		}
		
		cout<<"\n";
	}
	return 0;
}
18计5-张咏真  15:45:47
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

const int maxn=3e5+5;
int n,m;
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n)
	{
		//x.clear();y.clear();sa.clear();rk.clear();c.clear();
		rept(i,0,n) v[i].clear();
		cin>>(s+1);
	//	cout<<(s+1)<<"\n";
		get_sa();
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
				v[n-i].pb(i);
				//dd(i);de(n-i);
			}
			else
			{
				v[nex[i]-i-1].pb(i);
				//dd(i);de(nex[i]-i-1);
			}
		}
		bool flag=0;
		rept(i,0,n)
		{
			if(!v[i].size()) continue;
			rep(j,0,v[i].size())
			{
//				dd(i);de(v[i][j]);
				v[i][j]+=i+2;
			}
			sort(all(v[i]),comp2);
			rep(j,0,v[i].size())
			{
				if(flag) cout<<" ";
				else flag=!flag;
				cout<<v[i][j]-i-2;
			}
		}
		
		cout<<"\n";
		
		rept(i,0,n*2) x[i]=y[i]=sa[i]=rk[i]=c[i]=0;
	}
	return 0;
}
18计5-张咏真  15:46:21
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

const int maxn=4e5+5;
int n,m;
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n)
	{
		//x.clear();y.clear();sa.clear();rk.clear();c.clear();
		rept(i,0,n) v[i].clear();
		cin>>(s+1);
	//	cout<<(s+1)<<"\n";
		get_sa();
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
				v[n-i].pb(i);
				//dd(i);de(n-i);
			}
			else
			{
				v[nex[i]-i-1].pb(i);
				//dd(i);de(nex[i]-i-1);
			}
		}
		bool flag=0;
		rept(i,0,n)
		{
			if(!v[i].size()) continue;
			rep(j,0,v[i].size())
			{
//				dd(i);de(v[i][j]);
				v[i][j]+=i+2;
			}
			sort(all(v[i]),comp2);
			rep(j,0,v[i].size())
			{
				if(flag) cout<<" ";
				else flag=!flag;
				cout<<v[i][j]-i-2;
			}
		}
		
		cout<<"\n";
		
		rept(i,0,n*4) x[i]=y[i]=sa[i]=rk[i]=c[i]=0;
	}
	return 0;
}
18计5-张咏真  15:50:41
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

const int maxn=4e5+5;
int n,m;
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
//	cin.tie(0);
	while(1)
	{
		//x.clear();y.clear();sa.clear();rk.clear();c.clear();
		n = 100000;
		rept(i,0,n) v[i].clear();
		scanf("%s",s+1);
		//cin>>(s+1);
	//	cout<<(s+1)<<"\n";
		rep(i, 1, n + 1) s[i] = (char)(rand()% 2 + 'a');
		get_sa();
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
				v[n-i].pb(i);
				//dd(i);de(n-i);
			}
			else
			{
				v[nex[i]-i-1].pb(i);
				//dd(i);de(nex[i]-i-1);
			}
		}
		bool flag=0;
		rept(i,0,n)
		{
			if(!v[i].size()) continue;
			rep(j,0,v[i].size())
			{
//				dd(i);de(v[i][j]);
				v[i][j]+=i+2;
			}
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
		
		rept(i,0,n*2) x[i]=y[i]=sa[i]=rk[i]=c[i]=0;
	}
	return 0;
}