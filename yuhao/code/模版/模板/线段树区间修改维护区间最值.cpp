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
ll num[2000000+10],laze[2000000+10];
int a[1000000+10],pos[1000000+10],tag[1000000+10];
void pushup(int rt){
	num[rt]=max(num[rt*2],num[rt*2+1]);
}
void pushdown(int rt){
	if(laze[rt]){
		num[rt*2]+=laze[rt];
		num[rt*2+1]+=laze[rt];
		laze[rt*2]+=laze[rt];
		laze[rt*2+1]+=laze[rt];
		laze[rt]=0;
	}
}
void build(int l,int r,int rt){
	if(l==r){
		return ;
	}
	int mid=(l+r)/2;
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	pushup(rt);
}
void updata(int l,int r,int ql,int qr,int val,int rt){
	if(l>=ql&&r<=qr){
		laze[rt]+=val;
		num[rt]+=val;
		return ;
	}
	pushdown(rt);
	int mid=(l+r)/2;
	if(ql<=mid) updata(l,mid,ql,qr,val,rt*2);
	if(qr>mid) updata(mid+1,r,ql,qr,val,rt*2+1);
	pushup(rt);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i,1,n+1) {
		cin >> a[i];
		pos[a[i]]=i;
	}
	rep(i,1,n+1) cin >> tag[i];
	updata(1,n,1,pos[n],1,1);
	int ans=n;
	rep(i,1,n+1){
		cout<<ans<<" ";
		if(i==n) break;
		updata(1,n,1,tag[i],-1,1);
		while(num[1]<=0){
			ans--;
			updata(1,n,1,pos[ans],1,1);
		}
	}
	return 0;
}


