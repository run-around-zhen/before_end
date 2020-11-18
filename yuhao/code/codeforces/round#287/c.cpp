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
ll sum[100 + 10];
ll h, id;
ll ans = 0;
void dfs(int deep, int flag){
	//cout << deep << " " << flag << " " << id<< " " << ans << endl;
	if(deep == h){
		cout << ans << endl;
		return ;
	}
	ans ++ ;
	if(flag == 1){
		if(sum[h - deep - 1] >= id) dfs(deep + 1, flag ^ 1);
		else{
			ans += sum[h - deep] - 1;
			id -= sum[h - deep - 1];
			dfs(deep + 1, flag);
		}
	}
	else{
		if(sum[h - deep - 1] < id){
		//	ans += sum[h - deep] - 1;
			id -= sum[h - deep - 1] ;
			dfs(deep + 1, flag ^ 1);
		}
		else{
			ans += sum[h - deep] - 1;
			dfs(deep + 1, flag);
		}
	}
}	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> h >> id;
	h ++;
	sum[1] = 2;
	sum[0] = 1;
	rep(i, 2 ,100) sum[i] = sum[i - 1] * 2;
	dfs(1, 1);
	return 0;
}