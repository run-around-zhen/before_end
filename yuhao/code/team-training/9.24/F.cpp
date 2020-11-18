#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int  i = (a); i < b; i ++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); i++)
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
const int maxn=2e5+5;
map<int,int> m;
int f[maxn];
queue<int> ans;

int find_father(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find_father(f[x]);
}

void add(int a,int b,int x)
{
	int fa=find_father(a),fb=find_father(b);
	if(fa==fb) return;
	f[fa]=fb;
	ans.push(a);
	ans.push(b);
	ans.push(x);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	rep(i,1,n+1) f[i]=i;
	rep(i,1,n+1)
	{
		int q;
		cin>>q;
		while(q--)
		{
			int t;
			cin>>t;
			if(m[t]) add(m[t],i,t);
			m[t]=i;
		}
	}
	rep(i,2,n+1) if(find_father(i)!=find_father(1))
	{
		cout<<"impossible\n";
		return 0;
	}
	while(!ans.empty())
	{
		cout<<ans.front()<<" ";
		ans.pop();
		cout<<ans.front()<<" ";
		ans.pop();
		cout<<ans.front()<<"\n";
		ans.pop();
	}
	return 0;
}
