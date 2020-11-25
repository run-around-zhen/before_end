#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAXN=2e5+10;
int M,A[MAXN],B[MAXN],C[MAXN];
priority_queue<pii> pq;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>M;
	for(int i=1;i<=M;i++) cin>>A[i];
	for(int i=1;i<=M;i++) cin>>B[i],pq.push( pii(B[i],i) );
	sort(A+1,A+1+M);
	for(int i=1;i<=M;i++) C[ pq.top().second ]=A[i],pq.pop();
	for(int i=1;i<=M;i++) cout<<C[i]<<' ';
	cout.flush();
	return 0;
}
