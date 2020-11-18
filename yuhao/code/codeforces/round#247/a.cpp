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
int sum = 0;
int a[10], b[10];
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	rep(i, 0, 4) cin >> a[i];
	string s;
	cin >> s;
	rep(i, 0, s.size()){
		b[s[i] - '1'] ++;
	}
	rep(i, 0, 4) sum += b[i] * a[i];
	cout << sum << endl;
	return 0;
}