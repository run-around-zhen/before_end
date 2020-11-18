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
map<int,int>ma,may;
vi v,v1;
struct node{
	int x, y;
}a[100000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	rep(i, 0, 8){
		cin >> a[i]. x >> a[i].y;
		ma[a[i].x] ++;
		may[a[i].y] ++;
	}
	if(ma.size() == 3 && may.size() == 3){
		for(auto i :ma){
			v.pb(i.fi);
		}
		for(auto i:may){
			v1.pb(i.fi);
		}
		rep(i, 0, 3){
			rep(j, 0, 3){
				if(i == 1 && j == 1) continue;
				int flag = 0;
				rep(k, 0, 8){
					if(a[k].x == v[i] && a[k].y == v1[j]) flag = 1;
				}
				if(!flag){
					cout << "ugly"<<endl;
					return 0;
				}
			}
		}
		/*rep(i, 0, 8){
			if(a[i].x == v[1] && a[i].y == v1[1]){
				cout << "ugly"<<endl;
				return 0;
			}
		}
		if(ma[v[0]] != 3 || ma[v[1]] != 2 || ma[v[2]] != 3||may[v[0]] != 3 || may[v[1]] != 2 || may[v[2]] != 3){
			cout << "ugly"<<endl;
			return 0;
		}*/
		cout <<"respectable" << endl;
		return 0;
	}
	cout << "ugly"<< endl;
	return 0;
}
