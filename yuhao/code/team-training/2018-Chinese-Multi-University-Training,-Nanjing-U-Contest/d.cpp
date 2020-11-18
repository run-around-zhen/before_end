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
char a[100][100], b[100][100];
char c[2] = {'(', ')'};
int n, m;
ll res = 0;
void check(){
	int ans = 0;
	/*rep(i, 0, n){
		rep(j, 0, m){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/
	rep(i, 0, n){
		int sum = 0;
		int flag = 1;
		rep(j, 0, m){
			if(a[i][j] == '(') sum ++;
			else sum --;
			if(sum < 0) flag = 0; 
		}
		if(sum == 0)ans += flag;
	}
	rep(i, 0, m){
		int sum = 0;
		int flag = 1;
		rep(j, 0, n){
			if(a[j][i] == '(')sum ++;
			else sum --;
			if(sum < 0) flag =0;
		}
		if(sum == 0)ans += flag;
	}
	//cout << ans << endl;
	if(ans > res){
		res = ans;
		rep(i, 0, n){
			rep(j, 0, m){
				b[i][j] = a[i][j];
			}
		}
	}
}
void dfs(int i){
	if(i == n * m){
		//cout << i << endl;
		check();
		return ;
	}
	a[i / m][i % m] = '('; 
	dfs(i + 1);
	a[i / m][i % m] = ')';
	dfs(i + 1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	cin >> n >> m;
	dfs(0);
	
	int cnt = 0;
	/*while(cnt <= 1e6){
		cnt ++;
		rep(i, 0, n){
			rep(j, 0, m) a[i][j] = c[rand()% 2];
		}
		check();
	}*/cout << res << endl;
	rep(i, 0, n){
		rep(j, 0, m ){
			cout << b[i][j] <<" ";
		}
		cout << endl;
	}
	return 0;
}