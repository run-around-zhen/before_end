https://codeforces.com/contest/1295/problem/B

#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int N,X,Bal[MAXN];
string s;
inline int ans(){
	(cin>>N>>X).get();
	getline(cin,s);
	for(int i=0;i<N;i++) Bal[i+1]=Bal[i]+(s[i]=='0')-(s[i]=='1');
	if(!Bal[N]){
		for(int i=1;i<=N;i++) if(Bal[i]==X) return -1;
		return 0;
	}
	int Cnt=0;
	for(int i=1;i<=N;i++) Cnt+=((X-Bal[i])%Bal[N]==0)*((X-Bal[i])/Bal[N]>=0);
	return Cnt+(X==0);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--) cout<<ans()<<'\n';
	cout.flush();
	return 0;
}