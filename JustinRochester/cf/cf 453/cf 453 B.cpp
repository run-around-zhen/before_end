#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int MAXN=1e4+10;
int N,Color[MAXN];
vector<int> Son[MAXN];
int dfs(int root,int color){
	int ans=0;
	if(color!=Color[root]) ++ans;
	for(auto s : Son[root])
		ans+=dfs(s,Color[root]);
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=2,p;i<=N;i++) cin>>p,Son[p].push_back(i);
	for(int i=1;i<=N;i++) cin>>Color[i];
	cout<<dfs(1,0);
	cout.flush();
	return 0;
}
 