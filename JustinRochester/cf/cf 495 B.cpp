#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int MAXN=1024;
int N,M;
pii Seg[MAXN];
string s1,s2;
inline ll calc(const string &s){
	int Add[MAXN]={0};
	for(int i=0;i<N;i++) Add[i+1]=Add[i]+(s[i]&1);
	ll ans=0;
	for(int i=1;i<=M;i++){
		ll tmp1=Add[Seg[i].second]-Add[Seg[i].first-1];
		ll tmp2=Seg[i].second-Seg[i].first+1;
		ans+=tmp1*(tmp2-tmp1);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=M;i++) cin>>Seg[i].first>>Seg[i].second;
	s1="0"; s2="1";
	for(int i=1;i<N;i++) s1.push_back(s1[i-1]^1),s2.push_back(s2[i-1]^1);
	if( calc(s1)<calc(s2) ) cout<<s2;
	else cout<<s1;
	cout.flush();
	return 0;
}
