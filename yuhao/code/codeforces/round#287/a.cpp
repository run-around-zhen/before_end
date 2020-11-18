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
struct node{
	int val,pos;
}a[1000000 + 10];
bool cmp(node a, node b){
	return a.val < b.val;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, k ;
	cin >> n >> k;
	rep(i, 1, n + 1){
		cin >> a[i].val;
		a[i].pos = i;
	}
	sort(a + 1, a + 1 + n, cmp);
	ll sum = 0;
	int  tot = 0;
	rep(i, 1, n + 1){
		
		sum += a[i].val;
		if(sum > k) break;
		tot ++;
	}
	cout << tot << endl;
	rep(i, 1, tot + 1){
		cout << a[i].pos << " ";
	}
	return 0;
}