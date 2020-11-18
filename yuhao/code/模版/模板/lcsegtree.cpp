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
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn=2e5+10;
int lef[maxn],righ[maxn],a[maxn];
struct line{
	double k,b;
	int l,r,flag;
	line(double a=0,double c=0,int d=0,int e=0,int f=0){
		k=a;b=c;l=d;r=e;flag=f;
	}
}seg[maxn<<2];
struct lcseg{
	int inf=1e18;
	#define lson rt << 1
	#define rson lson | 1
	const double eps=1e-8;
	inline double(calc(line l1,int pos)) {return l1.k*pos+l1.b;}
	inline int cross(line l1,line l2){ return floor((l1.b-l2.b)/(l2.k-l1.k));}
	void build(int l,int r,int rt){
		seg[rt].l=1;seg[rt].r=maxn;seg[rt].flag=0;
		if(l==r) return ;
		int mid=(l+r)/2;
		build(l,mid,lson);
		build(mid+1,r,rson);
	}
	void insert(int l,int r,int rt,line ins){
		if(ins.l<=l&&ins.r>=r){
			if(!seg[rt].flag){ seg[rt]=ins;seg[rt].flag=1;}
			else if((calc(ins,l)-calc(seg[rt],l))>eps&&(calc(ins,r)-calc(seg[rt],r))>eps){seg[rt]=ins;}
			else if((calc(ins,l)-calc(seg[rt],l))>eps||(calc(ins,r)-calc(seg[rt],r))>eps){
				int mid=(l+r)>>1;
				if(calc(ins,mid)-calc(seg[rt],mid)>eps) swap(seg[rt],ins);
				if(cross(seg[rt],ins)-mid<-eps) insert(l,mid,lson,ins);
				else if(cross(seg[rt],ins)-mid>eps) insert(mid+1,r,rson,ins);
				else{
					if(calc(seg[rt],l)<calc(ins,l)) insert(l,mid,lson,ins);
					else insert(mid+1,r,rson,ins); 
				}
			}
		}else{
			int mid=(l+r)>>1;
			if(ins.l<=mid) insert(l,mid,lson,ins);
			if(ins.r>mid) insert(mid+1,r,rson,ins);
		}
	}
	double query(int l,int r,int rt,int pos){ 
		if(l==r) return seg[rt].flag?calc(seg[rt],pos):-inf;
		int mid=(l+r)>>1;double res=seg[rt].flag?calc(seg[rt],pos):-inf;
		if(pos<=mid) res=max(res,query(l,mid,lson,pos));
		else res=max(res,query(mid+1,r,rson,pos));
		return res;
	}
}lc;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		if(s[0]=='P'){
		 	double  k,b;
		 	cin >> b >> k;
		 	b=b-k;
		 	lc.insert(1,50000,1,line(k,b,1,50000,1));
		}
		else{
			int pos;
			cin >> pos;
			cout<<lc.query(1,50000,1,pos)<<endl;
		}
	}
			
	return 0;
}


