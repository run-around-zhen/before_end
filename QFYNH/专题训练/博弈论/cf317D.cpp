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
int sg[1010];
bool vis[5000000];
int n;
int get(int x){
	//de("!!!");
	bool vis1[1010];
	memset(vis1, false, sizeof(vis1));
	//de("A");
	rep(i, 1, x + 1){
		//de("B");
		if(!vis[i]){
			//de(i);
			vi v;
			v.clear();
	//		vis[i] = true;
			if(i != 1)for(int j = i; j <= n; j *= i) {
				if(vis[j]){
					v.pb(j);
				}
				vis[j] = true;
			}
			vis[i] = true;
			// rep(j, 1, n + 1){
			// 	cout << vis[j] << " ";
			// }
			// cout << endl;
			vis1[get(n)] = true;
			vis[i] = false;
			if(i != 1)for(int j = i; j <= n; j *= i) vis[j] = false;
			for(auto j : v){
				vis[j] = true;
			}
			// de(i);
			// rep(j, 1, n + 1){
			// 	cout << vis[j] << " ";
			// }
			// cout << endl;
		}
	}
	rep(i, 0, 1010){
		if(!vis1[i]){
			// rep(j, 1,  n + 1){
			// 	cout << vis[j] << " ";
			// }
			// cout << i << endl;
			return i;
		}
	}
}
int get1(int x){
	if(x == 0 ) return 0;
	bool vis1[1000];
	memset(vis, false , sizeof(vis));
	rep(i, 1, x + 1){
		vis1[get1(i - 1)] = true;
	}
	rep(i, 0, 1010){
		if(!vis1[i]) return i;
	}

}
int cnt[50];
int res[40]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14};
int main(){
	//ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	int ans = 0;
	for(int i = 2; i * i <= n ; i ++){
		if(vis[i]) continue;
		int sum = 0;
		for(ll j = i; j <= n; j *= i){
if(j <= 1000000){
			vis[j] = true;}
			sum ++;
		}
		cnt[sum] ++;
	}
	rep(i, 2, 40){
		n -= cnt[i] * i;
		if(cnt[i] % 2 == 1) ans ^= res[i];
	}
	if(n % 2 == 1){
		ans ^= 1;
	}
	if(ans){
		cout << "Vasya" << endl;
	}
	else{
		cout << "Petya" << endl;
	}
	return 0;
}