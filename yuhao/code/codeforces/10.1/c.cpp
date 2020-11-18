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
struct node{
	int a[100][100];
}acc, B;
node mul(node a, node b){
	node res;
	rep(i, 0, 60){
		rep(j, 0, 60){
			res.a[i][j] = 0;
		}
	}
	rep(i, 0, 60){
		rep(j, 0, 60){
			rep(k, 0, 60){
				res.a[i][j] += a.a[i][k] * b.a[k][j];
			}
		}
	}
	return res;
}
node qpow(node a, int k){
	node res;
	rep(i, 0, 60) res.a[i][i] = 1;
	while(k){
		if(k & 1){
			res = mul(res, a); 
		}
		k >>= 1;
		a = mul(a, a);
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, m ,a, b, c, t;
	while(cin >> n >> m >> a >> b >> c >> t){
		if(n == 0) break;
		rep(i, 0, n){
			cin >> acc.a[0][i];
		}
		B.a[0][0] = a;
		B.a[1][0] = b;
		B.a[2][0] = c;
		//acc = mul(acc, qpow(B, t));
		acc =  mul(acc, B);
		rep(i, 0, n){
			cout << acc.a[0][i] << " ";
		}
		cout << endl;
	}
	return 0;
}