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
ll n, a, b, c;
ll h[1000000 + 10];
ll get(int rt){
	ll maxn = 0, minn = 0;
	rep(i, 1, n + 1){
		if(h[i] > rt) maxn += h[i] - rt;
		else minn += rt - h[i];
	}
	if(a + b >  c) {
		if(maxn > minn){
			return minn * c + (maxn - minn) * a;
		}
		else{
			return maxn * c + (minn - maxn) * b;
		}
	}
	else{
		return maxn * a + minn * b;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> b >> a >> c;
	rep(i ,1, n + 1) cin >> h[i];
	int l = 0, r = 1e9;
	while(l + 1 < r){
    	int lm=(l + r) >> 1,rm = (lm + r ) >> 1;
    	//cout << lm << " " << rm << " " << get(lm) << " " << get(rm) << endl;
    	if(get(lm)>get(rm)){
       		l = lm;
    	}
    	else{
        	r = rm;
		}
	}
	//cout << l << " " << r << endl;
	cout << min(get(l) , get(r)) << endl;
	//cout << get(8) << endl;
	return 0;
}