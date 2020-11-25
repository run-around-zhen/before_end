#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int MAXN=256;
int N,C[MAXN][MAXN];
inline void pre(){
	C[0][0]=1;
	C[1][1]=1;
	for(int i=2;i<=150;i++){
		for(int j=0;j<i;j++) C[i][j+1]=C[i-1][j];
		for(int j=0;j<i-1;j++) C[i][j]+=C[i-2][j];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pre();
	cin>>N;
	cout<<N<<'\n';
	for(int i=0;i<=N;i++) cout<<(C[N][i]&1)<<' ';
	cout<<'\n'<<N-1<<'\n';
	for(int i=0;i<=N-1;i++) cout<<(C[N-1][i]&1)<<' ';
	cout.flush();
	return 0;
}
 