#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int MAXN=1e5+10;
int N,A[MAXN],Cnt[MAXN],CntNum;
bool Vis[MAXN];
inline void add(int a){
	if(!Cnt[a]) ++CntNum;
	++Cnt[a];
}
inline void sub(int a){
	--Cnt[a];
	if(!Cnt[a]) --CntNum;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) cin>>A[i],add(A[i]);
	ll Ans=0;
	for(int i=1;i<=N;i++){
		sub(A[i]);
		if(!Vis[ A[i] ]){
			Vis[ A[i] ]=1;
			Ans+=CntNum;
		}
	}
	cout<<Ans;
	cout.flush();
	return 0;
}
