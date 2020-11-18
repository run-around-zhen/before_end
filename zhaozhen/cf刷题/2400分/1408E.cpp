#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

ll a[maxn],b[maxn],parent[2*maxn];

int find(int p)
{
    if( p == parent[p] ) return p;
    return parent[p] = find(parent[p]);
}

struct node{
    ll x,y,val;
    bool operator<(const node&n)const
    {
        return val > n.val;
    }
}edge[2*maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m,n;
    cin >> m >> n;
    for (int i = 1; i <= n+m; i++) parent[i] = i;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            int y;
            cin >> y;
            cnt ++;
            edge[cnt].x = i+n;
            edge[cnt].y = y;
            edge[cnt].val = a[i] + b[y];
        } 
    }
    sort(edge+1,edge+1+cnt);
    ll ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        //cout << "asd" << '\n';
        int x = edge[i].x,y = edge[i].y;
        int fx = find(x),fy = find(y);
        if( fx == fy ) ans += edge[i].val;
        else parent[fx] = fy;
    }
    cout << ans << '\n';
    return 0;
}
