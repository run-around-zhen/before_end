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
const int N=2e5+5;
vector<int> v[N];
int x[N],y[N],del[N],d[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			del[i]=0;
			v[i].clear();
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x[i],&y[i]);
			v[x[i]].pb(y[i]);
			d[x[i]]++;
			d[y[i]]++;
		}
		priority_queue<pii> q;
		for(int i=1;i<=n;i++){
			sort(v[i].begin(), v[i].end());
			q.push(make_pair(d[i], i));
		}
		while(!q.empty()){
			int i = q.top().second;
			q.pop();
			if(del[i])
			continue;
			for(int j=0;j<v[i].size();j++){
				int to=v[i][j];
				if(del[to])
				continue;
				for(int k=0;k<v[to].size();k++){
					del[v[to][k]]=1;
				}
				v[to].clear();
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(del[i])
			ans++;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			if(del[i]){
				printf("%d ",i);
			}
		}
		printf("\n");
	}
}
/*
1
6 6
4 6
5 6
4 5
3 5
2 4
1 4
*/