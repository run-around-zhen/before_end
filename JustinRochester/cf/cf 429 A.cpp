#include<bits/stdc++.h>
using namespace std;
int N,K,Cnt[26]={0};
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    (cin>>N>>K).get();
    getline(cin,s);
    for(auto c : s) ++Cnt[ c-'a' ];
    for(int i=0;i<26;i++)
        if(Cnt[i]>K){
            cout<<"NO";
            cout.flush();
            return 0;
        }
    cout<<"YES";
    cout.flush();
    return 0;
}