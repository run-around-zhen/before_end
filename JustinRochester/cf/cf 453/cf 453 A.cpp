#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int MAXN=128;
int N,M;
pii Tel[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>Tel[i].first>>Tel[i].second;
	ll pos=0;
	for(int i=1;i<=N;i++) if(pos>=Tel[i].first) pos=max(pos,Tel[i].second);
	if(pos>=M) cout<<"YES";
	else cout<<"NO";
	cout.flush();
	return 0;
}
 