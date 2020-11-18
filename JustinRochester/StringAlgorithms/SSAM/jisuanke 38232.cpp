https://nanti.jisuanke.com/t/38232

#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10,INF=0x7f7f7f7f;
string s;
int Nxtpos[MAXN][26];
inline bool issubstr(const string &t){
    int lstpos=-1;
    for(int i=0;i<t.size()&&lstpos!=INF;i++)
        lstpos=Nxtpos[lstpos+1][ t[i]-'a' ];
    return lstpos!=INF;
}
inline void pre(){
    for(int j=0;j<26;j++) Nxtpos[s.size()][j]=INF;
    for(int i=s.size()-1;i>=0;i--){
        for(int j=0;j<26;j++) Nxtpos[i][j]=Nxtpos[i+1][j];
        Nxtpos[i][s[i]-'a']=i;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin,s);
    pre();
    int T;
    (cin>>T).get();
    while(T--&&getline(cin,s))
        if(issubstr(s)) cout<<"YES\n";
        else cout<<"NO\n";
    cout.flush();
    return 0;
}