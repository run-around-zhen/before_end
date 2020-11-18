#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

typedef __int128 ll;

unordered_map<string,ll> dp[2];
ll dp1[70][1<<10],dp2[70][1<<16];
vector<char> num;

string out(ll ans,char x)
{
	if( ans == 0 ) return "0";
    string res;
    int base = 0;
    if( x == 'd' ) base = 10;
    else base = 16;
    while( ans )
    {
        int t = ans % base;
        //cout << t << '\n';
        ans /= base;
        if( t >= 10 ) res += t - 10 + 'a';
        else res += t + '0';
    } 
    string z;
    for (int i = res.length()-1; i >= 0; i--) z += res[i];
    return z;
}

int convert(char x)
{
    if( x >= 'a' && x <= 'z' ) return x - 'a' + 10;
    return x - '0';  
} 

ll dfs1(ll pos,ll state,int flag,int lead)
{
    ll max_num;
    if( pos == -1 ) return 1;
    if( !flag && dp1[pos][state] != -1 ) return dp1[pos][state]; 
    if( flag ) max_num = convert(num[pos]);
    else max_num = 9;
    ll res = 0;
    for (int i = 0; i <= max_num; i++)
    {
    	if( lead )
    	{
    		if( i == 0 ) res += dfs1(pos-1,state,flag&&(i==max_num),lead&&(i==0));
    		else res += dfs1(pos-1,state|(1<<i),flag&&(i==max_num),lead&&(i==0));
		}else if( !(state & (1<<i)) )
        {
            res += dfs1(pos-1,state|(1<<i),flag&&(i==max_num),lead&&(i==0));
        }
    }
    if( !flag && state != 0 ) dp1[pos][state] = res;
    return res;
}

ll dfs2(ll pos,ll state,int flag,int lead)
{
    ll max_num;
    if( pos == -1 ) return 1;
    if( !flag && dp2[pos][state] != -1 ) return dp2[pos][state]; 
    if( flag ) max_num = convert(num[pos]);
    else max_num = 15;
    ll res = 0;
    for (int i = 0; i <= max_num; i++)
    {
        if( lead )
    	{
    		if( i == 0 ) res += dfs2(pos-1,state,flag&&(i==max_num),lead&&(i==0));
    		else res += dfs2(pos-1,state|(1<<i),flag&&(i==max_num),lead&&(i==0));
		}else if( !(state & (1<<i)) )
        {
            res += dfs2(pos-1,state|(1<<i),flag&&(i==max_num),lead&&(i==0));
        }
    }
    if( !flag && state != 0 ) dp2[pos][state] = res;
    return res;
}

ll slove(string top,char x)
{
    num.clear();
    for (int i = top.size()-1; i >= 0; i--) num.push_back(top[i]);
    if( x == 'd' ) return dfs1(num.size()-1,0,1,1);
    else return dfs2(num.size()-1,0,1,1);
} 

int vis[500];

bool check(string a)
{
    memset(vis,0,sizeof(vis));
    for (int i = 0; i < a.length(); i++)
    {
        if( vis[a[i]] ) return false;
        vis[a[i]] = 1;
    }
    return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    //cout << slove("1d8c",'h') << '\n';
    //cout << slove("1b36",'h') << '\n'; 
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char x;
        int kind;
        cin >> x >> kind;
        //cout << 
        int c;
        if( x == 'd' ) c = 0;
        else c = 1;
        if( kind == 0 )
        {
            string l1,r1;
            cin >> l1 >> r1;
            //cout << slove(r1,x) << '\n';
            //cout << slove(l1,x) << '\n';
            ll ans = slove(r1,x) - slove(l1,x);
            if( check(l1) ) ans ++;
            //cout << ans << '\n';
            cout << out(ans,x) << '\n';
        }else
        {
            string top;
            cin >> top;
            ll base;
            if( x == 'd' ) base = 10;
            else base = 16;
            ll res = 0;
            for (int i = 0; i < top.size(); i++)
            {
                res *= base;
                if( top[i] >= 'a' && top[i] <= 'z' ) res += top[i] - 'a' + 10;
                else res += top[i] - '0';
            }
            //cout << res << '\n';
            ll l = 0,r = ((ll)1<<64)-1;
            ll ans = -1;
            while( l <= r )
            {
                ll mid = ( l + r ) / 2;
                string t = out(mid,x);
                //cout << t << '\n';
                ll tmp;
                if( dp[c][t] != 0 ) tmp = dp[c][t];
				else
				{
					tmp = slove(t,x);
					dp[c][t] = tmp;
				} 
                if( tmp >= res ) 
				{
					ans = mid;
					r = mid - 1; 
				}
                else l = mid + 1;
            } 
            //cout << ans << '\n';
            if( ans == -1 ) cout << '-' << '\n';
            else cout << out(ans,x) << '\n';
        }
    }
    return 0;
}

