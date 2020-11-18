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
int res[1000 + 10];
vi v[1000 + 10];
int check(int l, int r){
	int sum = 0;
	//cout << "!!!" << l << " " << r << endl;
	rep(i, l, r + 1){
		sum += v[i].size();
	}
	cout <<"? " << sum<< " ";
	rep(i, l, r + 1){
		for(auto j : v[i]){
			cout << j << " ";
		}
	}
	cout << endl;
	int x;
	cin >> x;
	return x;
}
void cal(int l, int r, int ans){
	rep(i, l, r + 1){
		res[i] = ans;
	}
}
int main(){
	int T;
	cin >> T;
	while(T --){
		cin >> n >> k;
		rep(i, 1, k + 1){
			int x;
			cin >> x;
			rep(j, 1, x + 1){
				int y;
				cin >> y;
				v[i].pb(y);
			}
			
		}
		int l = 1, r = k;
		int ans2 = check(1, k);
		if(k == 1){
			res[1] = 0;
		}
		else{
		while(l < r){
			int mid = (l + r) / 2;
			int ans1 = check(l, mid);
			if(l == r){
				
				break;
			}
			if(ans1 < ans2){
				cal(l, mid, ans2);
				l = mid + 1;
			}
			else{
				cal(mid + 1, r, ans2);
				ans2 = ans1;
				r = mid ;
			}if(l == 1) cal(l , r ,check(l + 1, k));
				else if(r == k) cal(l , r,check(1, r - 1));
				else{
					int t = check(1, r - 1);
					int t1 = check(r + 1, k);
					cal(l, r, max(t, t1));
				}
			
		}
	}
		cout << "! ";
		rep(i, 1, k + 1) cout <<res[i] << " ";
		cout << endl;
		string s;
		cin >> s;
		fflush(stdout);
		rep(i, 1, k + 1) v[i].clear();
	}
	return 0;
}
/*
1
10 10
1 1
1 2
1 3
1 4
1 5
1 6
1 7 
1 8
1 9 
1 10
*/