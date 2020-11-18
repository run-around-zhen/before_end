#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
int cnt=1;
vector<pair<int, int> > edge[100000 + 10];
int id[100000 + 10], a[100000 + 10];
ll ans = 0;
vi v1, v2;
class Tree
{
    public:
        int leftson,rightson;
        Tree(){
            leftson=rightson=-1;
        }
} tree[3200000];
 
void insert(int x);
int solve(int x);
void insert(int x)
{
    int p=0;
    for(int i=30;i>=0;i--)
    {
        int xx;
        xx=(x&(1<<i))? 1:0;
        if(xx==1)
        {
            if(tree[p].rightson==-1)
                tree[p].rightson=cnt++;
            p=tree[p].rightson;
        }
        else
        {
            if(tree[p].leftson==-1) tree[p].leftson=cnt++;
            p=tree[p].leftson;
        }
    }
}
int solve(int x)
{
    int p=0,ans=0;
    if(tree[0].leftson==-1&&tree[0].rightson==-1) return 0;
    for(int i=30;i>=0;i--)
    {
        int xx=(x&(1<<i))? 1:0;
        if(xx==1)
        {
            if(tree[p].rightson!=-1)
                p=tree[p].rightson;
            else ans+=(1<<i),p=tree[p].leftson;
        }
        else
        {
        	if(tree[p].leftson!=-1)
                p=tree[p].leftson;
            else ans+=(1<<i),p=tree[p].rightson;
        }
    }
    return ans;
}
void dfs(int rt, int fi){
    for(auto i : edge[rt]){
        if(i.fi == fi) continue;
        a[i.fi] = (a[rt] ^ i.se);
        dfs(i.fi, rt);
    }
}
void cal(int l, int r, int bit){
    if(bit < 0) return ;
    if(l >= r) return ;
  //  cout << l << " " << r << " " << bit << " " << ans << endl;
    rep(i, 0, cnt + 1){
        tree[i].leftson = tree[i].rightson = -1;
    }
    cnt = 1;
    rep(i, l, r + 1){
        if((a[id[i]] >> bit) & 1){
            v1.pb(id[i]);
            insert(a[id[i]]);
           // cout << a[id[i]] << "!!!" << endl;
        }
        else{
            v2.pb(id[i]);
        }
    }
    //cout << v1.size() << " " << v2.size() << endl;
    rep(i, 0, v1.size()) id[l + i] = v1[i];
    rep(i, 0, v2.size()) id[l + v1.size() + i] = v2[i];
    int minn = 2e9;
    rep(i, l + v1.size(), r + 1){
    	//cout << a[id[i]] << "???" << endl;
        minn = min(minn, solve(a[id[i]]));
    }
    if(v1.size() != 0 && v2.size() != 0) ans += minn;
    int mid = l + v1.size();
    v1.clear();
    v2.clear();
    cal(l, mid - 1, bit - 1);
    cal(mid, r, bit - 1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //cout << setiosflags(ios::fixed);
    //cout << setprecision(2);
    cin >> n;
    rep(i, 1, n){
        int u, v, w;
        cin >> u >> v >> w;
        u ++;
        v ++;
        edge[u].pb(mp(v, w));
        edge[v].pb(mp(u, w));
    }
    rep(i, 1, n + 1) id[i] = i;
    a[1] = 0;
    dfs(1, 0);
    //rep(i, 1, n + 1) cout << a[i] << " ";
    //cout << endl;
    cal(1, n, 30);
    cout << ans << endl;
    return 0;
}