#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int MAXN=3e3+20,INF=0x7f7f7f7f;
inline int getID(char c) { return (c<='Z')?(c-'A'):(c-'a'+26); }
inline char getChar(int id) { return (id<26)?(id+'A'):(id+'a'-26); }
struct Bignum{
	const static int Lim=1e9;
	int Num[20],Siz;
	Bignum() { memset(Num,0,sizeof(Num)); Siz=1; }
	inline void carry() {
		for(int i=0;i<Siz;i++) if(Num[i]>=Lim) ++Num[i+1],Num[i]-=Lim;
		while(Num[Siz]) ++Siz;
	}
	Bignum operator + (const Bignum &x) const {
		Bignum y;
		y.Siz=max(Siz,x.Siz);
		for(int i=0;i<y.Siz;i++) y.Num[i]=Num[i]+x.Num[i];
		y.carry();
		return y;
	}
	Bignum operator ++ () {
		++this->Num[0];
		this->carry();
		return *this;
	}
    inline void print(){
    	printf("%d",Num[Siz-1]);
    	for(int i=Siz-2;i>=0;i--) printf("%09d",Num[i]);
	}
};
map<pii,Bignum> Dp;
int N,M,Type,Nx[MAXN][52],Ny[MAXN][52];
bool Vis[MAXN][MAXN];
char ans[MAXN],*pans=ans;
void dfs(int px,int py){
	if(!Type&&Vis[px][py]) return ;
	Vis[px][py]=1;
	Dp[pii(px,py)]=Bignum();
	for(int i=0;i<52;i++)
		if(Nx[px+1][i]!=INF&&Ny[py+1][i]!=INF){
			if(Type) *(pans++)=getChar(i),puts(ans);
			dfs(Nx[px+1][i],Ny[py+1][i]);
			if(Type) *(--pans)=0;
			if(!Type) Dp[pii(px,py)]=Dp[pii(px,py)]+Dp[ pii(Nx[px+1][i],Ny[py+1][i]) ];
		}
	if(!Type) ++Dp[pii(px,py)];
	else ++Dp[pii(0,0)];
}
inline void pre(){
    scanf("%d %d\n%s\n",&N,&M,ans);
	for(int j=0;j<52;j++)
		Nx[N+1][j]=Ny[M+1][j]=INF;
	for(int i=N;i>=1;i--){
		for(int j=0;j<52;j++)
			Nx[i][j]=Nx[i+1][j];
		Nx[i][ getID(ans[i-1]) ]=i;
	}
    scanf("%s",ans);
    scanf("%d",&Type);
	for(int i=M;i>=1;i--){
		for(int j=0;j<52;j++)
			Ny[i][j]=Ny[i+1][j];
		Ny[i][ getID(ans[i-1]) ]=i;
	}
    memset(ans,0,sizeof(ans));
	Dp[pii(0,0)]=Bignum();
}
int main(){
	pre(); 
	if(Dp[pii(0,0)].Siz==1&&Dp[pii(0,0)].Num[0]==0&&Type==1) putchar('\n');
	dfs(0,0);
	Dp[pii(0,0)].print();
	return 0;
}
