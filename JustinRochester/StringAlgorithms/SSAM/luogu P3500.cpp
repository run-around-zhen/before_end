https://www.luogu.com.cn/problem/P3500

#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
vector<int> Pos[MAXN];
int M,A,N,L,B;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>M;
    for(int i=1;i<=M;i++) cin>>A,Pos[A].push_back(i);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>L;
        bool finded=1;
        int lastpos=-1;
        for(int j=1;j<=L;j++){
            cin>>B;
            if(!finded) continue;
            auto pos=upper_bound(Pos[B].begin(),Pos[B].end(),lastpos);
            if(pos==Pos[B].end()) finded=0;
            else lastpos=*pos;
        }
        if(finded) cout<<"TAK\n";
        else cout<<"NIE\n";
    }
    cout.flush();
    return 0;
}