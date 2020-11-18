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
int n, k;
int a[2000000 + 10];
bool check(int cos){
	int res = 0;
	int per_pos = -1;
	rep(i, 1, n + 1){
		if(i == per_pos + 1) continue;
		else {
			if(a[i] <= cos){
				per_pos = i;
				res ++;
			}
		}
	}
	if(k % 2 == 0){
		return res >= k / 2 && per_pos!= n;
	}
	else{
		return res >= (k + 1)/ 2;
	}
}
bool check1(int cos){
	int res = 0;
	int per_pos = -1;
	rep(i, 2, n + 1){
		if(i == per_pos + 1) continue;
		else {
			if(a[i] <= cos){
				per_pos = i;
				res ++;
			}
		}
	}
	if(k % 2 == 0){
		return res >= k / 2 ;
	}
	else{
		return res >= k / 2 && per_pos!= n;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n + 1){
		cin >> a[i];
	}
	int l = 1, r = 1e9;
	int ans = 1e9;
	while(l <= r){
		int mid = (l + r) /2 ;
		if(check(mid) || check1(mid)) {
			r = mid - 1;
			ans = min(ans ,mid);
		}
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}