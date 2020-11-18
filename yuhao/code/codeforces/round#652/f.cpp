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
const int N = 2e5 + 10;
int f[N], g[N], a[N + 1], b[N + 1];
int get(ll s, ll e) {
    if(2 * s > e) {
        return 1;
    } 
    else {
        e /= 2;
        if (e & 1) {
            return (e - s) & 1;
        }
        else if (2 * s > e) {
            return (e - s) & 1;
        } 
        else {
            return get(s, e / 2);
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		ll s, e;
		cin >> s >> e;
		f[i] = get(s, 2 * e);
		g[i] = get(s, e);
	}
	b[1] = 1;
	rep(i ,1, n + 1){
		if(f[i]) a[i + 1] = b[i];
		else a[i + 1] = a[i];
		if(g[i]) b[i + 1] = b[i];
		else b[i + 1] = a[i];

	}
	cout << a[n + 1] << " " << b[n + 1] << endl;
	return 0;
}