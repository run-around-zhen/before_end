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
int k;
int sg[1010][1010];
int N, M;
int get(int n, int m){
	if(sg[n][m] != - 1) return sg[n][m];
	if(n == N && m == M) return sg[n][m] = 0;
	bool vis[5000];
	memset(vis, false, sizeof(vis));
	if(n < N) vis[get(n + 1, m)] = true;
	if(m < M) vis[get(n, m + 1)] = true;
	rep(i, 1, 2){
		int x = n + k * i;
		int y = m + k * i;
		if(x > N || y > M) break;
		vis[get(x, y)] = true;
	}
	rep(i, 0, 5010){
		if(!vis[i]){
			return sg[n][m] = i;
		}
	}
	return sg[n][m];
}
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	//  cin >> k;
	// rep(i, 1, 31){
	// 	rep(j, 1, 31){
	// 		memset(sg, -1, sizeof(sg));
	// 		N = i;
	// 		M = j;
	// 	if(j < i)  cout << "  ";
	// 	else 	cout << get(1, 1) << " ";
	// 	}
	// 	cout << endl;
	// }
	// memset(sg, -1, sizeof(sg));
	int T;
	cin >> T >> k;
	while(T --){
		int n, m;
		cin >> n >> m;
		if(n > m) swap(n, m);
		if(k == 1){
			if(n % 2 == 0 || (n + m) % 2 == 1){
				cout << "+" << endl;
			}
			else{
				cout << "-" << endl;
			}
			continue;
		}
		int t = n / (k + 1);
		n -= t * (k + 1);
		m -= t * (k + 1);
		if(n == 0){
			cout << "+" << endl;
		}
		else if((n + m + t) % 2 == 1){
			cout << "+" << endl;
		}
		else{
			cout << "-" << endl;
		}
	}
	return 0;
}