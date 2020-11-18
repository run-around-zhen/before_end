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
int ans = 0;
int cnt[11];
int get(int i){
	memset(cnt, 0, sizeof(cnt));
	int maxn = 0;
	while(i){
		cnt[i % 10] ++;
		maxn = max(maxn, cnt[i % 10]);
		i /= 10;
	}
	int flag = -1;
	rep(i, 0, 10){
		if(maxn == cnt[i]){
			if(flag == -1) flag = i;
			else return 10;
		}
	}
	//cout << flag << endl;
	return flag;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int l, r, d;
	cin >> l >> r >> d;
	rep(i, l, r + 1){
		if(get(i) == d){
			ans ++;
		} 
	}
	cout << ans << endl;
	return 0;
}