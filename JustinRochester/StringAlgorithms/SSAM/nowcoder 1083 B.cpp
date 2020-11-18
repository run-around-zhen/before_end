//https://ac.nowcoder.com/acm/contest/1083/B

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int MAXN=1e5+10,INF=0x7f7f7f7f;
int Nxtpos[MAXN][26];
string s,t;
int N,Q;
inline bool issubseq(const string &t){
	int lstpos=-1;
	for(int i=0;i<t.size()&&lstpos!=INF;i++)
		lstpos=Nxtpos[lstpos+1][ t[i]-'a' ];
	return lstpos!=INF;
}
inline void pre(){
	for(int j=0;j<26;j++)
		Nxtpos[s.size()][j]=INF;
	for(int i=s.size()-1;i>=0;i--){
		for(int j=0;j<26;j++)
			Nxtpos[i][j]=Nxtpos[i+1][j];
		Nxtpos[i][ s[i]-'a' ]=i;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	(cin>>N>>Q).get();
	getline(cin,s);
	pre();
	while(Q--){
		getline(cin,t);
		if( issubseq(t) ) cout<<"YES\n";
		else cout<<"NO\n";
	}
	cout.flush();
	return 0;
}
