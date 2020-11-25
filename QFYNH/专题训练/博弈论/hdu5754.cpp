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
int sg1[1010][1010];
int sg2[1010][1010];
int get1(int n, int m){
	if(sg1[n][m] != -1) return sg1[n][m];
	if(n == 1 && m == 1) return sg1[n][m] = 0;
	int vis[10];
	memset(vis, false, sizeof(vis));
	if(n > 1) vis[sg1[n - 1][m]] = true;
	if(m > 1) vis[sg1[n][m - 1]] = true;
	if(n > 1 && m > 1) vis[sg1[n - 1][m - 1]] = true;
	rep(i, 0, 5){
		if(!vis[i]) return sg1[n][m] = i;
	}
}
int get2(int n, int m){
	if(sg2[n][m] != -1) return sg2[n][m];
	if(n == 1 && m == 1) return sg2[n][m] = 0;
	int vis[3010];
	memset(vis, false, sizeof(vis));
	rep(i, 1, n){
		vis[get2(i, m)] = true;
	}
	rep(i, 1, m){
		vis[get2(n, i)] = true;
	}
	rep(i, 1, min(n, m)){
		vis[get2(n - i, m - i)] = true;
	}
	rep(i, 0, 1000){
		if(!vis[i]) return sg2[n][m] = i;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
//	memset(sg2, -1, sizeof(sg2));
	// rep(i, 1, 10){
	// 	rep(j, 1, 10){
	// 		cout << get2(i, j) << " ";
	// 	}
	// 	cout << endl;
	// }
// 	rep(i, 1, 100){
// 		rep(j, i, 100){
// 			if(get2(i, j) == 0){
// 				cout << "4 " << i << " " << j  << endl;
// 			}
// 		}
// //		cout << endl;
// 	}
	int T;
	cin >> T;
	// memset(sg1, -1, sizeof(sg1));
	// rep(i, 1, 10){
	// 	rep(j, 1, 10){
	// 		cout << get1(i, j) << " ";
	// 	}
	// 	cout << endl;
	// }
	while(T --){
		int op, n, m;
		cin >> op >> n >> m;
		if(op == 1){
			if(n % 2 != 0 && m % 2 != 0){
				cout << "G" << endl;
			}
			else{
				cout << "B" << endl;
			}
		}
		else if(op == 2){
			if(n == m){
				cout << "G" << endl;
			}
			else{
				cout << "B" << endl;
			}
		}
		else if(op == 3){
			if(n == m && n % 3 == 1){
				cout << "G" << endl;
			}
			else {
				if(abs(m -n)== 1 && abs(n+ m) % 3 == 2) {
					cout << "B" << endl;
				}
				else{
					cout << "D" << endl;
				}
			}
		}
		else{
			if(n > m) swap(n, m);
			int x = 0.618 * m;
			//cout << x << " " << n << " ";
			int  k = abs(m-n);
            if((int)(k*(1+sqrt(5))/2) + 1== min(n,m))  cout<<"G"<<endl;
            else cout << "B" << endl;
		}
	}
	return 0;
}
/*
16
1 1 1
2 1 1
3 1 1
4 1 1
1 1 2
2 1 2
3 1 2
4 1 2
1 2 2
2 2 2
3 2 2
4 2 2
1 3 3
2 3 3 
3 3 3
4 3 33
*/