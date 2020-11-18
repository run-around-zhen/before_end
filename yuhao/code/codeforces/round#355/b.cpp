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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n,m,x,y;
int vis[510][510];
bool check(int x,int y){
	return x>0&&y>0&&x<=n&&y<=m;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> x >> y;
	int sum=0;
	string s;
	cin >> s;
	cout<<"1 ";
	vis[x][y]=1;
	sum++;
	rep(i,0,s.size()-1){
		if(s[i]=='U'){
			if(check(x-1,y)) x--;
		}
		if(s[i]=='D'){
			if(check(x+1,y)) x++;
		}
		if(s[i]=='L'){
			if(check(x,y-1)) y--;
		}
		if(s[i]=='R'){
			if(check(x,y+1)) y++;
		}
		if(!vis[x][y]) {
			sum++;
			if(i!=s.size()-1)cout<<"1 ";
		}
		else{
			if(i!=s.size()-1)cout<<"0 ";
		}
		vis[x][y]=1;
		//cout<<sum<<endl;
	}
	cout<<n*m-sum<<endl;
	return 0;
}