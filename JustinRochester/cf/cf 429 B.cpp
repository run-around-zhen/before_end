#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int N,A[MAXN],Add[MAXN];
inline bool win(){
	for(int i=1;i<=N;i++) if(A[i]&1) return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) cin>>A[i];
	if( win() ) cout<<"First";
	else cout<<"Second";
	cout.flush();
	return 0;
}
