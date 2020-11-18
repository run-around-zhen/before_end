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
int cnt = 1;
int minn[20000 + 10][250], maxn[20000 + 10][250];
int a, b;
string s;
void dfs(int l, int r, int rt){
	int tmp = 0;
	int pos = -1;
	rep(i, l, r + 1){
		if(s[i] == '(') tmp ++;
		if(s[i] == ')') tmp --;
		if(s[i] == '?' && tmp == 0){
			pos = i;
			break;
		} 
	}
	if(s[l] == '(' && s[r] == ')' && tmp == 0 && pos == -1){
		dfs(l + 1, r - 1, rt);
		return ;
	}
	rep(i, 0, 210) {
		maxn[rt][i] = -1e9;
		minn[rt][i] = 1e9;
	}
	if(pos == -1){
		maxn[rt][0] = s[l] - '0';
		minn[rt][0] = s[l] - '0';
		return ;
	}
	int rt1 = ++cnt, rt2 = ++ cnt;
	dfs(l, pos - 1, rt1);
	dfs(pos + 1, r, rt2);
	rep(i, 0, 101){
		rep(j, 0, 101){
			if(a <= b){
				maxn[rt][i + j + 1] = max(maxn[rt][i + j + 1], maxn[rt1][i] + maxn[rt2][j]);
				minn[rt][i + j + 1] = min(minn[rt][i + j + 1], minn[rt1][i] + minn[rt2][j]);
				maxn[rt][i + j] = max(maxn[rt][i + j], maxn[rt1][i] - minn[rt2][j]);
				minn[rt][i + j] = min(minn[rt][i + j], minn[rt1][i] - maxn[rt2][j]);
			}
			else{
				maxn[rt][i + j] = max(maxn[rt][i + j], maxn[rt1][i] + maxn[rt2][j]);
				minn[rt][i + j] = min(minn[rt][i + j], minn[rt1][i] + minn[rt2][j]);
				maxn[rt][i + j + 1] = max(maxn[rt][i + j + 1], maxn[rt1][i] - minn[rt2][j]);
				minn[rt][i + j + 1] = min(minn[rt][i + j + 1], minn[rt1][i] - maxn[rt2][j]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> s;
	cin >> a >> b;
	dfs(0, s.size() - 1, 1);
	cout << maxn[1][min(a, b)] << endl;
	return 0;
}