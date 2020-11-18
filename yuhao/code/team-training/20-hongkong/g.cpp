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
const int N=1e5+5;
int c=1e9;
int fa[N],tag[N],cost[N];
int main()
{
	int k;
	scanf("%d",&k);
	int cnt=1;
	cost[1]=c;
	while(k>0){
		if(k&1){
			fa[cnt+1]=cnt;
			if(tag[cnt])
			cost[cnt+1]=cost[cnt];
			else
			cost[cnt+1]=cost[cnt]-1;
			
			tag[cnt+1]=1;
			
			cnt++;
			
			k--;
		}
		else{
			fa[cnt+1]=cnt;
			cost[cnt+1]=1;
			fa[cnt+2]=cnt+1;
			cost[cnt+2]=1;
			
			k/=2;
			k--;
			fa[cnt+3]=cnt;
			if(tag[cnt])
			cost[cnt+3]=cost[cnt]-1;
			else
			cost[cnt+3]=cost[cnt]-2;
			
			cnt+=3;
		}
	}
	printf("%d\n",cnt);
	for(int i=2;i<=cnt;i++){
		printf("%d ",fa[i]);
	}
	printf("\n");
	for(int i=1;i<=cnt;i++){
		printf("%d ",cost[i]);
	}
}