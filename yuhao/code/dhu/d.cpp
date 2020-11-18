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
int sum;
int n;
int a[100000 + 10];
int t[100000 + 10];
int res[1000 + 10];
bool check(int rt){
	rep(i, 1, n + 1){
		if((sum - a[i] + rt) >= 0 && (sum - a[i] + rt) % n == 0){
			t[i] = (sum - a[i] + rt) / n;
			continue;
		}
		else return false;
	}
	return true;
}
bool check1(){
	priority_queue<pii, vector<pii>, greater<pii> > q;
	rep(i, 1, n + 1) q.push(mp(a[i], t[i]));
	int tt = 0;
	while(!q.empty()){
		int x = q.top().fi;
		int y = q.top().se;
		q.pop();
		if(x - tt < 0) return false;
		x += n;
		if(y > 0) tt ++ ;
		if(y > 1) q.push(mp(x, y - 1));
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		
		cin >> n;
		sum = 0;
		int tt = 0;
		rep(i, 0, 1001) res[i] = 0;
		rep(i, 1, n + 1) {
			cin >> a[i];
			sum += a[i];
			res[a[i]] ++ ;
		}
		int flag1 = 1;
		int ans = 0;
		/*rep(i, 0, n){
			ans += res[i];
			// /cout << ans << " " << i << endl;
			if(i + 1 < ans) {
				flag1 = 0;
				break;
			}
		}*/
		if(!flag1){
			cout << "No" << endl;
			continue;
		}
		//cout<< "!!" << endl;
		if(sum % n != 0){
			cout <<"No" << endl;
			continue;
		}
		sum /= n ;
		int flag = 0;
		rep(i, 0, 1001){
			if(check(i)){
				if(check1()){
					flag = 1;
				//cout << sum << " " << i << endl;
					break;
				}
			}
		}
		//rep(i, 1, n + 1) cout << t[i] << " ";
		//cout << endl;
		if(flag){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	return 0;
}