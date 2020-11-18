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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b,c;
	cin >>  a >> b >> c;
	int x,y,z;
	cin >> x >> y >> z;
	int res=0,sum=0;
	if(a>x){
		res+=(a-x)/2;
	}
	else{
		sum+=x-a;
	}
	if(b>y){
		res+=(b-y)/2;
	}
	else{
		sum+=y-b;
	}
	if(c>z){
		res+=(c-z)/2;
	}
	else{
		sum+=z-c;
	}
	if(sum>res){
		cout<<"No"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
	}
	return 0;
}