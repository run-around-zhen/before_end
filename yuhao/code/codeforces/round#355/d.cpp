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
struct point{
	int x,y,pos;
}a[1000000+10];
int b[1000000+10],c[1000000+10];
pair<int,int>ans[1000000+10];
struct node{
	int sum,a,b;
};
struct cmp1 {
    bool operator()(node ttt,node tttt) {
        return a[c[ttt.b]].x>a[c[tttt.b]].x;
    }
};
bool cmp(int l,int r){
	return a[l].x<a[r].x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	int t1=0,t2=0;
	rep(i,1,m+1){
		cin >> a[i].x >> a[i].y;
		a[i].pos=i;
		if(a[i].y==0) b[++t1]=i;
		else c[++t2]=i;
	}
	if(t2!=n-1){
		cout<<"-1";
		return 0;
	}
	sort(c+1,c+t2+1,cmp);
	sort(b+1,b+t1+1,cmp);
	priority_queue<node,vector<node>,cmp1 >q;
	rep(i,1,t2+1){
		//q.push({a[c[1]].x+a[c[i]].x,1,i});
		ans[c[i]]=mp(n,i);
	}
	rep(i,2,t2+1){
		q.push({a[c[1]].x+a[c[i]].x,1,i});
		//cout<<a[c[1]].x+a[c[i]].x<<"!!"<<endl;
	}
//	cout<<q.top().sum<<endl;
	rep(i,1,t1+1){
		//cout<<a[c[q.top().a]].x<<endl;
		while(q.size()!=0&&a[b[i]].x<a[c[q.top().b]].x){
			node now=q.top();
			q.pop();
			ans[b[i]]=mp(now.a,now.b);
		//	cout<<now.sum<<" "<<now.a<<" "<<now.b<<endl;
			if(now.a<now.b-1){
				q.push({a[c[now.a+1]].x+a[c[now.b]].x,now.a+1,now.b});
			}
		}
		if(q.size()==0){
			cout<<"-1"<<endl;
			return 0;
		}
		node now=q.top();
		q.pop();
		ans[b[i]]=mp(now.a,now.b);
		//cout<<now.sum<<" "<<now.a<<" "<<now.b<<endl;
		if(now.a<now.b-1){
			q.push({a[c[now.a+1]].x+a[c[now.b]].x,now.a+1,now.b});
		}
	}
	rep(i,1,m+1){
		cout<<ans[i].fi<<" "<<ans[i].se<<endl;
	}
	return 0;
}