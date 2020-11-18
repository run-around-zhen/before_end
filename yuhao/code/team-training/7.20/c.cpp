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
const int M=11;
char c[N];
int pos[M],Next[N][M];
vector<pii> v[M],vv;
ll ans=0;
bool cmp(pii a,pii b){
	return a.second>b.second;
}
struct Trie{
	map<int,int> next[8 * N][M];
	int cnt,rt;
	int newnode(){
		++cnt;
		for(int i=0;i<M;i++){
			next[cnt][i].clear();
		}
		return cnt;
	}
	void init(){
		cnt=0;
		rt=newnode();
	}
	void insert(){
		int now=rt,len=vv.size();
		for(int i=1;i<len;i++){
			if(next[now][vv[i].first][vv[i].second]==0)
			next[now][vv[i].first][vv[i].second]=newnode();
			now=cnt;
		}
	}
	int query(){
		int re=0;
		int now=rt,len=vv.size();
		for(int i=1;i<len;i++){
			if(next[now][vv[i].first].find(vv[i].second)!=next[now][vv[i].first].end()){
				re+=vv[i].second;
				now=next[now][vv[i].first][vv[i].second];
			}
			else if(next[now][vv[i].first].size()>=1){
				auto it=next[now][vv[i].first].end();
				it--;
				re+=(*it).second;
				break;
			}
			else{
				break;
			}
		}
		return re;
	}
};
Trie ac;
int vis[M];
int main()
{
	scanf("%s",c+1);
	int n=strlen(c+1);
	for(int i=0;i<M;i++){
		pos[i]=-1;
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<M;j++){
			Next[i][j]=pos[j];
		}
		pos[c[i]-'a']=i;
		int mx=n-i+1;
		for(int j=c[i]-'a'+1;j<M;j++){
			if(Next[i][j]!=-1){
				mx=Next[i][j]-i;
				break;
			}
		}
		v[c[i]-'a'].pb({i,mx});
	}
	for(int i=0;i<M;i++){
		sort(v[i].begin(),v[i].end(),cmp);
	}
	for(int i=0;i<M;i++){
		ac.init();
		for(int j=0;j<v[i].size();j++){
			vv.clear();
			int pos=v[i][j].first;
			while(pos<=n){
				int mx=n-pos+1;
				for(int k=c[pos]-'a'+1;k<M;k++){
					if(Next[pos][k]!=-1){
						mx=Next[pos][k]-pos;
						break;
					}
				}
				vv.pb({c[pos]-'a',mx});
				pos=pos+mx;
			}
			ans+=1ll*vv[0].second*(n-v[i][j].first+1-vv[0].second+1);
//			de(ans);
			int re=ac.query();
			if(j>=1)
			ans-=1ll*vv[0].second*(re+1);
			else
			ans-=1ll*vv[0].second*re;
//			de(ans);
			ac.insert();
		}
	}
	printf("%lld",ans);
}