#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
string s;
int Fir[MAXN],Sec[MAXN],Tot[MAXN],SA[MAXN],N;
/*
suff(i) 表示从 i 开始的后缀
SA[i] 表示排名为 i 的后缀起始位置为 SA[i]
Rank[i] 表示 suff(i) 的排名为 Rank[i]
Fir[i] 表示基数排序时，第一关键字（后缀数组求完后，等价于 Rank[i] ）
Sec[i] 表示基数排序时，第二关键字的第 i 个，对应开头位于原串的 Sec[i] 位置
Tot[i] 表示桶 i 内部的元素个数
*/
inline void getSA(){
    N=s.size();//字符串大小
    int num=128;//字符集大小
    for(int i=1;i<=N;i++) ++Tot[Fir[i]=s[i-1]];//初始化 + 装桶
    for(int i=1;i<=num;i++) Tot[i]+=Tot[i-1];//桶求前缀和
    for(int i=N;i>=1;i--) SA[ Tot[Fir[i]]-- ]=i;//求出长度为 1 时的串的 SA 值
    for(int k=1;k<N;k<<=1){//倍增
        int cnt=0;
        for(int i=N-k+1;i<=N;i++) Sec[++cnt]=i;//后 k 个因为长度不足，第二关键字为 0 ，排在最前面
        for(int i=1;i<=N;i++) if(SA[i]>k) Sec[++cnt]=SA[i]-k;
        //按序枚举可能的，满足 SA[i]>k 的后缀串 suff(SA[i]) 。使之可能作为某串的第二关键字

        for(int i=1;i<=num;i++) Tot[i]=0;
        for(int i=1;i<=N;i++) ++Tot[Fir[i]];
        for(int i=1;i<=num;i++) Tot[i]+=Tot[i-1];
        //同上，对第一关键字进行装桶
        for(int i=N;i>=1;i--) SA[ Tot[Fir[Sec[i]]]-- ]=Sec[i],Sec[i]=0;
        /*
        Sec[i] 表示第二关键字排序为 i 的串，起点位置为 Sec[i]
        Fir[Sec[i]] 表示第二关键字排序为 i 的串，对应的第一关键字为 Fir[Sec[i]]
        Tot[Fir[Sec[i]]] 表示第二关键字排序为 i 的串，对应的第一关键字的桶大小（按照基数排序的定义，即对应排序后的序号）
        SA[ Tot[Fir[Sec[i]]] ]=Sec[i]
        表示第二关键字为 i 的串，起点位置为 Sec[i] 。进行该次基数排序后，其对应的序号为 Tot[Fir[Sec[i]]] 。
        故排名为 Tot[Fir[Sec[i]]] 的后缀串，起始位置为 Sec[i] ，即 SA[ Tot[Fir[Sec[i]]] ]=Sec[i]
        */

        swap(Fir,Sec);
        Fir[SA[1]]=1;
        cnt=1;
        /*
        交换顺序后，Sec[i] 表示原 Fir[i] 的含义；Fir[i] 表示该轮排序后 suff(i) 的 SA 值排名为 Fir[i]
        显然，SA 值第一的数，排名为 1，Fir[SA[1]]=1
        cnt 表示上一次的排名数
        */
        for(int i=2;i<=N;i++)
            Fir[SA[i]]=(Sec[SA[i]]==Sec[SA[i-1]]&&Sec[SA[i]+k]==Sec[SA[i-1]+k])?cnt:++cnt;
        /*
        若当前串 suff(SA[i]) ，其第一关键字与第二关键字都与上一个串相同，则排名未增加（同名次），否则排名增加。
        由于第一关键字已 swap 储存至 Sec，故 Sec[SA[i]]==Sec[SA[i-1]] 且 Sec[SA[i]+k]==Sec[SA[i-1]+k]
        */
        if(cnt==N) break;//有 N 种名次，说明排序完比
        num=cnt;//更新字符集大小
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin,s);
    getSA();
    for(int i=1;i<=N;i++) cout<<SA[i]<<' ';
    /*
    for(int i=1;i<=N;i++) cout<<Fir[i]<<' ';
    //Fir[i] 等价于 Rank[i] ，表示 suff(i) 的排名为 Rank[i]
    */
    cout.flush();
    return 0;
}