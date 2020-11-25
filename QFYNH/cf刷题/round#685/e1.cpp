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
int sum[1000000 + 10], res[1000000 + 10], a[1000000 + 10];
int A[1000000 + 10];
vi v;
int qryxor(int a, int b){
	cout << "XOR" << " " << a << " " << b << endl;
	//return (A[a] ^ A[b]);
	int t;
	cin >> t;
	return t;
}
int qryand(int a, int b){
	cout << "AND" << " " << a << " " << b << endl;
	//return (A[a] & A[b]) ;
	int t;
	cin >> t;
	return t;
}
int get_ans(int a, int b, int c, int d, int e){
	int ans1, ans2, ans3;
	if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0) {
		ans1 = 0;
		ans2 = 0;
		ans3 = 0;
	}
	else if(a == 0 && b == 0 && c == 0 && d == 1 && e == 1) {
		ans1 = 0;
		ans2 = 0;
		ans3 = 1;
	}
	else if(a == 0 && b == 0 && c == 1 && d == 0 && e == 1) {
		ans1 = 0;
		ans2 = 1;
		ans3 = 0;
	}
	else if(a == 0 && b == 1 && c == 1 && d == 0 && e == 1) {
		ans1 = 1;
		ans2 = 0;
		ans3 = 1;
	}
	else if(a == 1 && b == 0 && c == 0 && d == 1 && e == 1) {
		ans1 = 1;
		ans2 = 1;
		ans3 = 0;
	}
	else if(a == 1 && b == 1 && c == 0 && d == 0 && e == 0) {
		ans1 = 1;
		ans2 = 1;
		ans3 = 1;
	}
	return ans1;
}
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a ;
		}
		a = a * a ;
		b >>= 1;
	}
	return res;
}
int get(int a, int b){
	if(a > b) swap(a, b);
	int ans = res[a];
	rep(i, a + 1, b){
		ans ^= res[i];
	}
	return ans;
}
int main(){
	////ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	srand(time(0));
	int n ;
	cin >> n;
	//rep(i, 1, n + 1) cin >> A[i];
	rep(i, 1, n){
		res[i] = qryxor(i, i + 1);
	//	de(res[i]);
	}
	rep(i, 1, n + 1) a[i] = i;
	int tt = 0;
	int tt1 = n;
	while(tt1){
		tt1 /= 2;
		tt ++;
	}tt --;
	//de(tt);

	while(1){
		random_shuffle(a + 1, a + 1 + n);
		v.clear();
		v.pb(a[1]);
		v.pb(a[2]);
		v.pb(a[3]);
		//sort(all(v));
		int id1 = v[1];
		int id2 = v[2];
		int id3 = v[0];
		int xor1 = get(id1, id2);
		int xor2 = get(id1, id3);
		int xor3 = (xor1 ^ xor2);
		int flag = 0;
		rep(i, 0, tt){
			if(((xor1 >> i) & 1) == 1 && ((xor2 >> i) & 1) == 1){
				flag = 1;
				break;
			}
			
		}
	//	break;
		if(!flag){
			int and12 = qryand(id1, id2);
			int and13 = qryand(id1, id3);
			//dd(id1);dd(id2);dd(id3);dd(xor1);dd(xor2);dd(xor3);dd(and12);de(and13);
			rep(i, 0, tt){
				sum[id1] += qpow(2, i) * get_ans((and12 >> i) & 1, (and13 >> i) & 1, (xor1 >> i) & 1, (xor2 >> i) & 1, (xor3 >> i) & 1);
			}
			//cout << id1 << " " << sum[id1] << endl;
			rep(i, id1 + 1, n + 1){
				sum[i] = (sum[i - 1] ^ res[i - 1]);
			}
			per(i, 1, id1){
				sum[i] = (sum[i + 1] ^ res[i]);
			}
			//cout << id1 << " " << sum[id1] << endl;
			cout << "! " ;
			rep(i, 1, n + 1) cout << sum[i] << " ";
			cout << endl;
			break;
		}
	}
	return 0;
}
/*
16
2 3 4 8 2 5 13 5 8 9 10 2 4 2 5 6
*/