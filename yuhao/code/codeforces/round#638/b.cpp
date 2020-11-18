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
int a[1000000+10],b[1000000+10];
set<int> s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n,k;
		s.clear();
		cin >> n >> k;
		rep(i,1,n+1){
			cin >> a[i];
			s.insert(a[i]);
		}
		if(s.size()>k ){
			cout<<"-1"<<endl;
		}
		else{
			cout<<100*k<<endl;
			rep(i,0,100){
				int t=0;
				for(auto j:s){
					cout<<j<<" ";
					t++;
				}
				while(t<k){
					cout<<a[1]<<" ";
					t++;
				}

			}
			cout<<endl;
		}
	}
	return 0;
}
/*
1
4 3
2 2 3 4
*/