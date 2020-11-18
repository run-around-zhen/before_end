#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#define PI acos(-1)
#define pb push_back
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define dd(x) cout<<#x<<" = "<<x<<","
#define de(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=3e5+5;
const ll mx=1e18+10;
ll f[N];
double ff[N];
char ans[N];
int id[N];
int main()
{
	f[0]=ff[0]=1;
	for(int i=1;i<N;i++){
		f[i]=f[i-1]*2;
		ff[i]=ff[i-1]*2;
		if(ff[i]>=mx){
			ff[i]=mx;
		}
	}
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		ll k;
		scanf("%d%lld",&n,&k);
		if(n&1){
			for(int i=1;i<=n;i++){
				id[i]=n-i+1;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(i&1){
					id[i]=n-i;
				}
				else{
					id[i]=n-i+2;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			dd(i),de(id[i]);
//		}
		int flag=1;
		int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
		for(int i=1;i<=n;i++){
			if(i&1)
			cnt1++;
			else
			cnt3++;
			if(id[i]>=i){
				if(i&1){
					cnt2++;
				}
				else{
					cnt4++;
				}
			}
		}
//		dd(cnt1),dd(cnt2),dd(cnt3),de(cnt4);
		int flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			ll sum1=0,sum2=0;
//			dd(i),dd(flag1),de(flag2);
			if(id[i]<i){
				if(i&1){
					cnt1--;
				}
				else{
					cnt3--;
				}
//				dd(cnt1),dd(cnt2),dd(cnt3),de(cnt4);
				double ss1,ss2;
				if(flag1&&flag2){
					ss1=ss2=0;
					sum1=sum2=0;
				}
				else if(flag1){
					ss1=ss2=ff[cnt1+cnt4];
					sum1=sum2=f[cnt1+cnt4];
					if(i%2==0){
						if(ans[id[i]]=='1'){
							ss2=sum2=0;
						}
						else if(ans[id[i]]=='0'){
							ss1=sum1=0;
						}
					}
				}
				else if(flag2){
					ss1=ss2=ff[cnt2+cnt3];
					sum1=sum2=f[cnt2+cnt3];
					if(i%2==1){
						if(ans[id[i]]=='1'){
							ss2=sum2=0;
						}
						else if(ans[id[i]]=='0'){
							ss1=sum1=0;
						}
					}
				}
				else{
					ss1=ss2=ff[cnt1+cnt4]+ff[cnt2+cnt3]-ff[cnt2+cnt4];
					sum1=sum2=f[cnt1+cnt4]+f[cnt2+cnt3]-f[cnt2+cnt4];
					
					if(i%2==0){
						if(ans[id[i]]=='1'){
							ss2=ff[cnt2+cnt3];
							sum2=f[cnt2+cnt3];
						}
						else if(ans[id[i]]=='0'){
							ss1=ff[cnt2+cnt3];
							sum1=f[cnt2+cnt3];
						}
					}
					if(i%2==1){
						if(ans[id[i]]=='1'){
							ss2=ff[cnt1+cnt4];
							sum2=f[cnt1+cnt4];
						}
						else if(ans[id[i]]=='0'){
							ss1=ff[cnt1+cnt4];
							sum1=f[cnt1+cnt4];
						}
					}
				}
				if(ss1>=mx){
					sum1=1e18;
				}
				if(ss2>=mx){
					sum2=1e18;
				}
			}
			else if(id[i]>=i){
				if(i&1){
					cnt1--;
					cnt2--;
					cnt2=max(cnt2,0);
				}
				else{
					cnt3--;
					cnt4--;
					cnt4=max(cnt4,0);
				}
				double ss=ff[cnt1+cnt4]+ff[cnt2+cnt3]-ff[cnt2+cnt4];
				if(ss>=mx){
					sum1=sum2=1e18;
				}
				else{
					sum1=sum2=f[cnt1+cnt4]+f[cnt2+cnt3]-f[cnt2+cnt4];
				}
			}
			
//			dd(i),dd(k),dd(sum1),de(sum2);
			sum1+=sum2;
			if(k>sum1){
				flag=0;
				break;
			}
			if(k>sum2){
				k-=sum2;
				ans[i]='1';
			}
			else{
				ans[i]='0';
			}
//			dd(i),de(ans[i]);
			if(i>n/2+n%2){
				if(ans[i]!=ans[id[i]]){
					if(i&1){
						flag1=1;
					}
					else{
						flag2=1;
					}
				}
			}
		}
		printf("Case #%d: ",tt);
		if(flag==0){
			printf("NOT FOUND!\n");
		}
		else{
			for(int i=1;i<=n;i++){
				printf("%c",ans[i]);
			}
			printf("\n");
		}
	}
}
/*
10 30
1000000

000011110101000101000110100001
*/