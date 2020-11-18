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
set<int>s;
vi v;
int a[1000000 + 10], b[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	memset(b, -1, sizeof(b));
	rep(i, 1, n + 1){
		cin >> a[i];
		s.insert(i - 1);
	}
	s.insert(n);
	rep(i, 1, n + 1){
		if(a[i] != a[i - 1]){
			b[i] = a[i - 1];
			s.erase(a[i - 1]);
		}
	}
	s.erase(a[n]);
	for(auto i:s) v.pb(i);
	int t = 0;
	rep(i, 1, n + 1){
		if(b[i] == -1){
			cout << v[t] << " ";
			t ++ ;
		}
		else{
			cout << b[i] << " ";
		}
	}
	return 0;
}