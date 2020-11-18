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
string s;
struct node{
	int a[5][5];
	node operator +(node x){
        node ans;
       	rep(i,0,5){
       		rep(j,0,5){
       			ans.a[i][j]=1e8;
       			rep(k,0,5){
       				ans.a[i][j]=min(a[i][k]+x.a[k][j],ans.a[i][j]);
       			}
       		}
       	}
        return ans;
    }
}num[2000000+10];
void build(int l,int r,int rt){
	if(l==r){
		rep(i,0,5){
			rep(j,0,5){
				if(i==j) num[rt].a[i][j]=0;
				else num[rt].a[i][j]=1e8;
			}
		}
		if(s[l-1]=='2'){
			num[rt].a[0][0]=1;
			num[rt].a[0][1]=0;
		}
		else if(s[l-1]=='0'){
			num[rt].a[1][2]=0;
			num[rt].a[1][1]=1;
		}
		else if(s[l-1]=='1'){
			num[rt].a[2][2]=1;
			num[rt].a[2][3]=0;
		}
		else if(s[l-1]=='7'){
			num[rt].a[3][3]=1;
			num[rt].a[3][4]=0;
		}
		else if(s[l-1]=='6'){
			num[rt].a[4][4]=1;
			num[rt].a[3][3]=1;
		}
		return ;
	}
	int mid=(l+r)/2;
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	num[rt]=num[rt*2]+num[rt*2+1];
}
node qry(int l,int r,int ql,int qr,int rt){
	if(l>=ql&&r<=qr){
		return num[rt];
	}
	int mid=(l+r)/2;
	if(ql<=mid&&qr>mid) return qry(l,mid,ql,qr,rt*2)+qry(mid+1,r,ql,qr,rt*2+1);
	if(ql<=mid) return qry(l,mid,ql,qr,rt*2);
	if(qr>mid) return qry(mid+1,r,ql,qr,rt*2+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	cin >> s;
	build(1,n,1);
	rep(i,0,m){
		int l,r;
		cin >> l >> r;
		ll res=qry(1,n,l,r,1).a[0][4];
		if(res<1e8){
			cout<<res<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}


