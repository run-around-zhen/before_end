#include<bits/stdc++.h>
#define PI acos(-1)
#define pb push_back
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define dd(x) cout<<#x<<" = "<<x<<","
#define de(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
struct node{
	int id,x1,x2;
	int k,b;
};
node a[N];
int n,ans1,ans2;
bool cmp1(node a,node b){
	if(a.x1!=b.x1)
	return a.x1>b.x1;
	return a.id<b.id;
}
bool cmp2(node a,node b){
	if(a.x1!=b.x1)
	return a.x1>b.x1;
	return a.id>b.id;
}
bool cmp3(node a,node b){
	if(a.x2!=b.x2)
	return a.x2>b.x2;
	return a.id<b.id;
}
bool cmp4(node a,node b){
	if(a.x2!=b.x2)
	return a.x2>b.x2;
	return a.id>b.id;
}
bool cmp5(node a,node b){
	return a.id<b.id;
}
pair<pii,int> b[N];
bool cmp6(pair<pii,int> x,pair<pii,int> y){
	pii a=x.first,b=y.first;
	if(1ll*a.first*b.second==1ll*b.first*a.second)
	return x.second<y.second;
	if(a.second<0&&b.second>0)
	return 1ll*a.first*b.second>1ll*b.first*a.second;
	else if(a.second>0&&b.second<0)
	return 1ll*a.first*b.second>1ll*b.first*a.second;
	
	return 1ll*a.first*b.second<1ll*b.first*a.second;
}
bool cmp7(pair<pii,int> x,pair<pii,int> y){
	pii a=x.first,b=y.first;
	if(1ll*a.first*b.second==1ll*b.first*a.second)
	return x.second>y.second;
	if(a.second<0&&b.second>0)
	return 1ll*a.first*b.second>1ll*b.first*a.second;
	else if(a.second>0&&b.second<0)
	return 1ll*a.first*b.second>1ll*b.first*a.second;
	
	return 1ll*a.first*b.second<1ll*b.first*a.second;
}
int cnt;
void solve(){
	cnt=0;
	int cnt1=0,cnt2=0;
	for(int i=2;i<=n;i++){
		if(a[i].k==a[1].k){
			if(a[i].b>a[1].b){
				cnt2++;
			}
			else if(a[i].b<a[1].b){
				cnt1++;
			}
		}
		else{
			if(a[i].k>a[1].k){
				cnt1++;
				b[++cnt]={{a[i].b-a[1].b,a[1].k-a[i].k},1};
			}
			else if(a[i].k<a[1].k){
				cnt2++;
				b[++cnt]={{a[i].b-a[1].b,a[1].k-a[i].k},2};
			}
		}
	}
	int pre1=cnt1,pre2=cnt2;
	sort(b+1,b+cnt+1,cmp6);
	for(int i=1;i<=cnt;i++){
		if(b[i].first.first*b[i].first.second>=0){
			ans1=min(ans1,cnt2+1);
			ans2=max(ans2,n-cnt1);
		} 
		if(b[i].second==1){
			cnt1--;
			cnt2++;
		}
		else if(b[i].second==2){
			cnt2--;
			cnt1++;
		}
	}
	ans1=min(ans1,cnt2+1);
	ans2=max(ans2,n-cnt1);
	cnt1=pre1,cnt2=pre2;
	sort(b+1,b+cnt+1,cmp7);
	for(int i=1;i<=cnt;i++){
		if(b[i].first.first*b[i].first.second>=0){
			ans1=min(ans1,cnt2+1);
			ans2=max(ans2,n-cnt1);
		}
		if(b[i].second==1){
			cnt1--;
			cnt2++;
		}
		else if(b[i].second==2){
			cnt2--;
			cnt1++;
		}
	}
	ans1=min(ans1,cnt2+1);
	ans2=max(ans2,n-cnt1);
//	dd(cnt1),de(cnt2);
//	dd(ans1),de(ans2);
}
int main()
{
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x1,&a[i].x2);
		a[i].id=i;
	}
	ans1=n,ans2=1;
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++){
		if(a[i].id==1){
			ans1=min(ans1,i);
			ans2=max(ans2,i);
		}
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(a[i].id==1){
			ans1=min(ans1,i);
			ans2=max(ans2,i);
		}
	}
	sort(a+1,a+n+1,cmp3);
	for(int i=1;i<=n;i++){
		if(a[i].id==1){
			ans1=min(ans1,i);
			ans2=max(ans2,i);
		}
	}
	sort(a+1,a+n+1,cmp4);
	for(int i=1;i<=n;i++){
		if(a[i].id==1){
			ans1=min(ans1,i);
			ans2=max(ans2,i);
		}
	}
	sort(a+1,a+n+1,cmp5);
	for(int i=1;i<=n;i++){
		a[i].k=a[i].x2;
		a[i].b=a[i].x1;
	}
//	dd(ans1),de(ans2);
	solve();
	for(int i=1;i<=5;i++){
		int x=rand()%100+10;
		for(int j=1;j<=n;j++){
			a[j].k=a[j].x2;
			a[j].b=a[j].x1*x;
		}
		solve();
	}
	printf("%d %d",ans1,ans2);
}