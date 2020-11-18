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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m, x, y, a, b;
	cin >> n >> m >> x >> y >> a >> b;
	int	gcd = __gcd(a, b);
	a /= gcd;
	b /= gcd;
	int use = min(n / a, m / b);
	a = a * use ;
	b = b * use;
	int ansx = x - ( a + 1) / 2;
	ansx = max(ansx, 0);
	ansx = min(ansx, n - a);
	int ansy = y - (b + 1) / 2;
	ansy = max(ansy, 0);
	ansy = min(ansy ,m - b);
    cout << ansx <<" " << ansy << " " << ansx + a << " " << ansy + b << endl;
	return 0;
}