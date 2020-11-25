#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int MAXN=2e5+10;
int H,A[MAXN],CntNode,Pa1[MAXN],Pa2[MAXN];
inline bool perfect(){
	int pos=-1;
	for(int i=0;i<H&&pos==-1;i++)
		if(A[i]>1&&A[i+1]>1)
			pos=i;
	if(pos==-1) return 1;
	
	int Cnt=0;
	for(int i=0;i<=pos;i++){
		for(int j=1;j<=A[i];j++)
			Pa1[Cnt+j]=Cnt,Pa2[Cnt+j]=Cnt;
		Cnt+=A[i];
	}
	for(int j=1;j<=A[pos+1];j++)
		Pa1[Cnt+j]=Cnt,Pa2[Cnt+j]=Cnt;
	--Pa2[Cnt+1];
	Cnt+=A[pos+1];
	for(int i=pos+2;i<=H;i++){
		for(int j=1;j<=A[i];j++)
			Pa1[Cnt+j]=Cnt,Pa2[Cnt+j]=Cnt;
		Cnt+=A[i];
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>H;
	for(int i=0;i<=H;i++) cin>>A[i],CntNode+=A[i];
	if( perfect() ) cout<<"perfect";
	else{
		cout<<"ambiguous\n";
		for(int i=1;i<=CntNode;i++) cout<<Pa1[i]<<' ';
		cout<<'\n';
		for(int i=1;i<=CntNode;i++) cout<<Pa2[i]<<' ';
	}
	cout.flush();
	return 0;
}