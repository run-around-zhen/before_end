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
	double t1, h1, t2, h2;
	cin >> h1 >> t1 >> h2 >> t2;
	double tmp = sqrt(h1 / h2);
	//cout << tmp << endl;
	cout<<fixed<<setprecision(10)<< (t1 - tmp * t2 ) / (1 - tmp);
	int j=2;
		rep(i,0,num+1){
			while(getdis_(v[i], v[j])<Cross(v[i],v[i+1],v[j+1])){
				j=(j+1)%num;
			}
			max_dis=max(max_dis,max(dis(v[j],v[i]),dis(v[j],v[i+1])));
		}
	return 0;
}