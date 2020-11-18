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
map<int, int>cnt, ma;
int ans[10000],  d[10000];
int dd[10];
int qry(int l, int r){
	cout << "?" << " " << d[l] << " " << d[r] << endl;
	int t;
	cin >> t;
	return t;
	//return dd[d[l]]|dd[d[r]];
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	srand(time(0));
	int n ;
	cin >> n;
	dd[1] = 5;
	dd[2] = 1;
	dd[3] = 3;
	dd[4] = 4;
	dd[5] = 2;
	dd[6] = 0;
	rep(i, 1, n + 1) d[i] = i;
	int pos = -1;
	random_shuffle(d + 1, d + 1 + n);
	int sum;
	int a = 1, b = 2;
	sum = qry(a, b); 
	rep(i, 3, n + 1){
		int sum1 = qry(a, i);
		if(sum1 < sum) {
			b = i;
			sum = sum1;
		}
		else if(sum1 == sum) {
			a = i;
			sum = qry(a, b);
		}
	}
	rep(i, 1, n + 1){
		if(i != a && i != b){
			int cnt1 = qry(a, i);
			int cnt2 = qry(b, i);
			if(cnt1 == cnt2) continue;
			if(cnt1 < cnt2) pos = a;
			else pos = b;
			break;
		}
	}
	//cout << pos <<" "<< d[pos] << endl;
	rep(i, 1, n + 1){
		if(i == d[pos] ) continue;
		cout << "? " << d[pos] << " " << i << endl;
	//	int x;
		cin >> ans[i];
		//ans[i] = dd[d[pos]]|dd[i];
	//	ma[b[i]] ++;
	}
	cout <<"! ";
	rep(i, 1, n + 1){
		cout << ans[i] << " ";
	}
	return 0;
}