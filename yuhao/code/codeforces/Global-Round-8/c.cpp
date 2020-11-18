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
int dir[8][2] ={0, 0, 0, 1, 0, 2, 1, 0, 1, 2, 2, 0, 2, 1, 2, 2};
map<pii,int >ma;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int x = 0, y = 0;
	rep(i, 1, n + 2){
		rep(j, 0, 8) ma[mp(x + dir[j][0], y + dir[j][1])] = 1;
		x += 2;
		y += 2;
	}
	cout << ma.size() << endl;
	for(auto i:ma){
		cout << i.fi.fi << " " << i.fi.se << endl;
	}
	return 0;
}