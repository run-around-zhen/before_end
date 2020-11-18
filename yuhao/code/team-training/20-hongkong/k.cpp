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
const int N=5e3+5;
const int M=65;
const int mod=1e9+7;
char c1[N],c2[N];
int f[N][M];
int dp[N][M][M][2];
int cal(int m,char *c){
	int len=strlen(c+1);
	for(int i=1;i<=len;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<m;k++){
				dp[i][j][k][0]=dp[i][j][k][1]=0;
			}
		}
	}
	for(int i=0;i<c[1]-'0';i++){
		dp[1][i*f[len][m]%m][i%m][0]=1;
	}
	for(int i=c[1]-'0';i<=c[1]-'0';i++){
		dp[1][i*f[len][m]%m][i%m][1]=1;
	}
	for(int i=1;i<len;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<m;k++){
				for(int l=0;l<=9;l++){
					dp[i+1][((j+l*f[len-i][m]-k*l)%m+m)%m][(k+l)%m][0]+=dp[i][j][k][0];
					dp[i+1][((j+l*f[len-i][m]-k*l)%m+m)%m][(k+l)%m][0]%=mod;
					if(l<c[i+1]-'0'){
						dp[i+1][((j+l*f[len-i][m]-k*l)%m+m)%m][(k+l)%m][0]+=dp[i][j][k][1];
						dp[i+1][((j+l*f[len-i][m]-k*l)%m+m)%m][(k+l)%m][0]%=mod;
					}
					else if(l==c[i+1]-'0'){
						dp[i+1][((j+l*f[len-i][m]-k*l)%m+m)%m][(k+l)%m][1]+=dp[i][j][k][1];
						dp[i+1][((j+l*f[len-i][m]-k*l)%m+m)%m][(k+l)%m][1]%=mod;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<=1;j++){
			ans+=dp[len][0][i][j];
			ans%=mod;
		}
	}
//	de(ans);
	return ans;
}

int main()
{
	for(int j=2;j<=60;j++){
		f[1][j]=1;
	}
	for(int i=2;i<N;i++){
		for(int j=2;j<=60;j++){
			f[i][j]=f[i-1][j]*10%j;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s%s",c1+1,c2+1);
		int len=strlen(c1+1);
		for(int i=len;i>=1;i--){
			if(c1[i]=='0'){
				c1[i]='9';
			}
			else{
				c1[i]--;
				break;
			}
		}
		int m;
		scanf("%d",&m);
		int a=cal(m,c2);
		int b=cal(m,c1);
		printf("%d\n",(a-b+mod)%mod);
	}
}