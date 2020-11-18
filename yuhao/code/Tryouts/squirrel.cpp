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
ll c, d;
int deep[100000 + 10];
vi edge[100000 + 10];
struct Mat{
	ll m[3][3];
};
struct node{
	ll l, r;
}a[100000 + 10];
Mat e;
ll mod = 1e9 + 7;
Mat mul(Mat x,Mat y)
{
	Mat c;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
			c.m[i][j]=0;
	}
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			for(int k=1;k<=2;k++)
			{
				c.m[i][j]+=x.m[i][k]*y.m[k][j];
				c.m[i][j]%=mod;
			}
		}
	}
	return c;
}

Mat qPow(Mat x,ll k)
{
	//cout << k << "!!!" << endl;
	Mat ans=e;//单位元
	while( k )
	{
		if( k&1 )
			ans=mul(ans,x);//矩阵乘法
		x=mul(x,x);
		k>>=1;
	}
	return ans;
}
void dfs(int rt, int fi){
	deep[rt] = deep[fi] + 1;
	for(auto i: edge[rt]){
		if(i == fi) continue;
		dfs(i, rt);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, s;
	cin >> n >> s >> c >> d;
	rep(i, 1, n){
		int u, v;
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	dfs(s, 0);	
	rep(i, 1, n + 1){
		cin >> a[i].l >> a[i].r;
	//	cout << "!!" << a[i].l << " " << a[i].r << endl;
	}
	ll ans = 0;
	e.m[1][1] = 1;
	e.m[1][2] = c;
	e.m[2][1] = d;
	e.m[2][2] = 1;
	rep(i, 1, n + 1){
		Mat res = qPow(e, deep[i] - 1);
	//	cout << i <<  " " << deep[i] - 1<< endl;
	//	cout << res.m[1][1] * a[i].l<< " " << res.m[1][2] * a[i].l << " " << res.m[2][1] * a[i].r << " " << res.m[2][2] * a[i].r  << endl;
		ans = (ans + res.m[1][1] * a[i]. l + res.m[1][2] * a[i].r + res.m[2][1] * a[i].l + res.m[2][2] * a[i].r) % mod;
	}
	cout << ans << endl;
	return 0;
}
