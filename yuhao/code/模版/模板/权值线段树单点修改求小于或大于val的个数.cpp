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
typedef vector<int> vi;
map<int,int>ma;
struct node{
	ll x,v;
}a[200000+10];
bool cmp(node a,node b){
	return a.x<b.x;
}
ll num[1000000+10],sum[1000000+10],x[200000+10];
void build(int l,int r,int rt){
	if(l==r){
		sum[rt]=ma[x[l-1]];
		return ;
	}
	int mid=(l+r)/2;
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}
void updata1(int l,int r,int pos,int rt){
	if(l==r){
		sum[rt]--;
		return ;
	}
	int mid=(l+r)/2;
	if(mid>=pos) updata1(l,mid,pos,rt*2);
	else updata1(mid+1,r,pos,rt*2+1);
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}
ll qry1(int l,int r,int val,int rt){
	int mid=(l+r)/2;
	if(l>=val) return sum[rt];
	if(r<val) return 0;
	if(mid>=val){
		return qry1(l,mid,val,rt*2)+sum[rt*2+1];
	}
	else{
		return qry1(mid+1,r,val,rt*2+1);
	}
}
void updata(int l,int r,int pos,int rt){
	if(l==r){
		num[rt]++;
		return ;
	}
	int mid=(l+r)/2;
	if(mid>=pos) updata(l,mid,pos,rt*2);
	else updata(mid+1,r,pos,rt*2+1);
	num[rt]=num[rt*2]+num[rt*2+1]; 
}
ll qry(int l,int r,int val,int rt){
	int mid=(l+r)/2;
	if(r<=val) return num[rt];
	if(l>val) return 0;
	if(mid>=val){
		return qry(l,mid,val,rt*2);
	}
	else{
		return num[rt*2]+qry(mid+1,r,val,rt*2+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int t=0;
	rep(i,1,n+1){
		cin >> a[i].x ;
	}
	rep(i,1,n+1) {
		cin >> a[i].v;
		x[t++]=a[i].v;
		ma[a[i].v]++;
	}	
	sort(x,x+t);
	t=unique(x,x+t)-x;
	build(1,t,1);
	sort(a+1,a+1+n,cmp);
	ll ans=0;
	rep(i,1,n+1){
		ll v=a[i].v;
		int pos_v=(lower_bound(x,x+t,v)-x)+1;
		ans+=a[i].x*qry(1,t,pos_v,1);
		updata(1,t,pos_v,1);
		updata1(1,t,pos_v,1);
		ans-=a[i].x*(qry1(1,t,pos_v,1)); 
	}
	cout<<ans<<endl;
	return 0;
}


