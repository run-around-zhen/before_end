//https://www.luogu.com.cn/problem/P5826

#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10,INF=0x7f7f7f7f;
int Type,N,Q,M,L,A,B;
vector<int> Pos[MAXN];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>Type>>N>>Q>>M;
    for(int i=1;i<=N;i++) cin>>A,Pos[A].push_back(i);
    for(int i=1;i<=M;i++) Pos[i].push_back(INF);
    for(int i=1;i<=Q;i++){
        cin>>L;
        int lstpos=-1;
        for(int j=1;j<=L;j++){
            cin>>B;
            if(lstpos==INF) continue;
            lstpos=*upper_bound(Pos[B].begin(),Pos[B].end(),lstpos);
        }
        if(lstpos!=INF) cout<<"Yes\n";
        else cout<<"No\n";
    }
    cout.flush();
    return 0;
}