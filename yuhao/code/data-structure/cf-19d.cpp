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
const int maxn=2e5+10;
int now_x[maxn*4];
int pos_x[maxn*4];
set<int>s[maxn*4];
int num[maxn*4];
int number=0;
struct node {
	int x,y;
	string s;
}a[maxn];
int f(int x){
	return (lower_bound(pos_x+1,pos_x+number+1,x)-pos_x);
}
void build(int l,int r,int rt){	
	num[rt]=-1;
	if(l==r){
		now_x[rt]=pos_x[l];
		return ;
	}
	int mid=(l+r)/2;
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
}
void updata(int l,int r,int pos,int val,int type,int rt){
	if(l==r) {
		if(type==1){
			s[rt].insert(val);
			num[rt]=*(--s[rt].end());
			//cout<<val<<" "<<num[rt]<<endl;
		}
		else{
			s[rt].erase(val);
			if(s[rt].size()==0) num[rt]=-1;
			else num[rt]=*(--s[rt].end());
		//	cout<<num[rt]<<" "<<val<<"!!!"<<endl;
		}
		return ;
	}
	int mid=(l+r)/2;
	if(pos<=mid) updata(l,mid,pos,val,type,rt*2);
	else updata(mid+1,r,pos,val,type,rt*2+1);
	num[rt]=max(num[rt*2],num[rt*2+1]);
}
pair<int,int>qry(int l,int r,int pos,int val,int rt){
//	cout<<l<<" "<<r <<" "<<pos<<" "<<val<<" "<<num[rt]<<" "<<num[rt*2]<<" "<<num[rt*2+1]<<endl;
	if(l==r){
		if(num[rt]<=val){
			return mp(-1,-1);
		}
		else {
			return mp(now_x[rt],*s[rt].lower_bound(val+1));
		}
	}
	int mid=(l+r)/2;
	pair<int,int>ans=mp(-1,-1);
	if(pos<=mid&&num[rt*2]>val) ans=qry(l,mid,pos,val,rt*2);
	if(num[rt*2+1]>val&&ans.fi==-1) ans= qry(mid+1,r,pos,val,rt*2+1);
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i,1,n+1){
		cin >> a[i].s >> a[i].x >> a[i].y;
		pos_x[++number]=a[i].x;
	}
	sort(pos_x+1,pos_x+1+number);
	number=unique(pos_x+1,pos_x+1+number)-pos_x-1;
	build(1,number,1);
	/*cout<<number<<endl;
	rep(i,1,number+1){
		cout<<pos_x[i]<<" ";
	}
	cout<<endl;
	rep(i,1,n+1){
		cout<<f(a[i].x)<<" "<<a[i].x<<endl;
	}*/
	rep(i,1,n+1){
		if(a[i].s=="add"){
			updata(1,number,f(a[i].x),a[i].y,1,1);
		}
		else if(a[i].s=="find"){
			pair<int,int>ans=mp(-1,-1);
			if(f(a[i].x)!=number) ans=qry(1,number,f(a[i].x)+1,a[i].y,1);
			if(ans.fi==-1) cout<<"-1"<<endl; 
			else cout<<ans.fi<<" "<<ans.se<<endl;
		}
		else{
			updata(1,number,f(a[i].x),a[i].y,0,1);
		}
	}
	return 0;
}