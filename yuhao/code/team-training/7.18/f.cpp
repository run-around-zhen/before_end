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
const int N=2e6+5;
__int128 ex_gcd(__int128 a, __int128 b, __int128 &x, __int128 &y){
	__int128 t, d;
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	d = ex_gcd(b, a % b, x, y);
	t = x;
	x = y;
	y = t - a / b * y;
	return d;
}
void print(__int128 x){
	if(x>=10){
		print(x/10);
	}
	printf("%d",x%10);
}
int vis[N];
vector<int> v[N];
int main()
{
	for(int i=2;i<N;i++){
		if(!vis[i]){
			vis[i]=1;
			for(int j=i;j<N;j+=i){
				if(!vis[j])
				v[j].pb(i);
				vis[j]=1;
			}
		}
	}
	int t;
	scanf("%d",&t);
	__int128 aa = t;
	print(aa);
	/*while(t--){
		int a,b;
		scanf("%d%d",&a,&b);
		__int128 d,f;
		if(v[b].size()==0){
			printf("-1 -1 -1 -1\n");
			continue;
		}
		else{
			d=v[b][0];
			while(b/d%v[b][0]==0){
				d*=v[b][0];
			}
			if(d==b){
				printf("-1 -1 -1 -1\n");
				continue;
			}
		}
		f=b/d;
		__int128 x,y; 
		ex_gcd(f,d,x,y);
		y=-y;
		if(x<=0){
			__int128 re=(d-x)/d;
			x+=re*d;
			y+=re*f;
		}
		else if(y<=0){
			__int128 re=(f-y)/f;
			x+=re*d;
			y+=re*f;
		}
		x*=a;
		y*=a;
		print(d);
		print(f);
		__int128 re=min((x-1)/d,(y-1)/f);
		x-=re*d;
		y-=re*d;

		print(x);
		printf(" ");
		print(d);
		printf(" ");
		print(y);
		printf(" ");
		print(f);
		printf("\n");
	}*/
}