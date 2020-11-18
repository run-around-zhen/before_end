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
bool check(int i);
int a[1000000 + 10];
int n;
bool vis[1000000 + 10];
bool dfs(int i, int j, int sum){
	if(sum == 0) return check(j + 1);
	if(i == 0) return false;
	if(vis[i]) return dfs(i - 1, j , sum);
	if(a[i] <= sum){
		vis[i] = true;
		if(dfs(i - 1, j, sum - a[i])) return true;
		vis[i] = false;
	}
	return dfs(i - 1, j, sum);
}
bool check(int i){
	if(a[i] == 1) return check(i + 1);
	if(i == n + 1) return true;
	int pos = - 1;
	for(int j = i; j >= 1; j --){
		if(a[j] < a[i] - 1) {
			pos = j;
			break;
		}
	}
	if(pos == -1) return false;
	return dfs(pos, i, a[i] - 1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	sort(a + 1, a + 1 + n);
	if(a[n] == n && check(1)){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}