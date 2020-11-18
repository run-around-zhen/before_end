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
ll dis[110][110];
int a[110];
struct node{
	int x, y;
}b[110];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, d;
	cin >> n >> d;
	rep(i ,2, n) cin >> a[i];
	rep(i, 1, n + 1){
		cin >> b[i].x >> b[i].y;
	}
	rep(i, 1, n + 1){
		rep(j, 1, n + 1){
			dis[i][j] = 1e9;
			if(i != j )dis[i][j] = d * (abs(b[i].x - b[j].x) + abs(b[i].y - b[j].y)) - a[i];
		}
	}
	//queue<int>q;
	//q.push(1);
	rep(i, 1, n + 1){
		rep(j, 1, n + 1){
			rep(k, 1, n + 1){
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
			}
		}
	}
	cout << dis[1][n];
	return 0;
}