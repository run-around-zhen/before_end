#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int MAXN=128;
int N,D,X[MAXN];
set<int> s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>D;
	for(int i=1;i<=N;i++) cin>>X[i];
	sort(X+1,X+1+N);
	s.insert(X[1]-D);
	s.insert(X[N]+D);
	for(int i=1;i<N;i++) if( abs(X[i]+D-X[i+1])>=D ) s.insert(X[i]+D);
	for(int i=2;i<=N;i++) if( abs(X[i]-D-X[i-1])>=D ) s.insert(X[i]-D);
	cout<<s.size();
	cout.flush();
	return 0;
}
