#include<bits/stdc++.h>
using namespace std;
#define int long long
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
signed  main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int T;
	cin >> T;
	while(T --){
		int d, k;
		cin >> d >> k;
		if(k > d){
			cout << "Utkarsh" << endl;
			continue;
		}
		rep(i, 1, d + 1){
			int dis = i * k;
			if(dis * dis + dis * dis > d * d){
				if(dis * dis + (dis - k) * (dis - k) > d * d){
					cout << "Utkarsh" << endl;
				}
				else{
					cout << "Ashish" << endl;
				}
				break;
			}
		}
		
	}
	return 0;
}