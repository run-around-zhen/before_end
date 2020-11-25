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
ll a[40], b[40], c[50];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	int n, q;
	cin >> n >> q;
	rep(i, 0, n) cin >> a[i];
	c[0] = 1;
	rep(i, 1, 40) c[i] = c[i - 1] * 2;
	rep(cas, 1, q + 1){
		int op;
		cin >> op;
		if(op == 1){
			ll pos, val;
			cin >> pos >> val;
			a[pos] = val; 
		}
		else{
			ll x, k;
			cin >> x >> k;
			ll tot_min = 0;
			rep(i, 0, x + 1){
				tot_min += a[i];
			}
			if(tot_min >= k){
				cout << "0" << endl;
				continue;
			}
			else{
				rep(i, 0, n) b[i] = a[i];
				ll sum = 0;
				rep(i, 0, n){
					sum += b[i] * c[i];
				}
				if(sum < k){
					cout << "-1" << endl;
					continue;
				}
				ll tot = 0;
				rep(i, 0, x + 1) tot += (c[i] )* b[i];
				ll ans = 0;
				//rep(i, 0, x + 1) k -= b[i];
				
				//	rep(i, 0, n){
				//		cout << b[i] << " ";
				//	}
				//	cout << endl;
			//	if(cas == q)de(sum);
				ll tot1 = 0;
				rep(i, 0, x + 1) tot1 += b[i];
				//de(tot1); 
				rep(i, x + 1, n){
					ll use =  min(b[i],  (k  - tot1)/(c[i - x]) );
					//ll can_use = use * c[i - x];
				//	if(cas == q)dd(i);dd(ans);dd(use);dd(k);dd((k - 1) / c[i - x]);dd(b[i]);de(tot);
					if(use < b[i]){
					//	if(cas == q)dd(i);dd(use);dd(tot);de(can_use);
						tot1 += use * c[i - x];
						tot += use * c[i];
					//	k -= use * c[i - x];
						ans += use * (c[i - x] - 1);
						for(int j = i - 1; j > x; j --){
							//if(cas == q)dd(j);dd(ans);de(k);
							if(tot >= k) {
								break;
							}
							ans ++;
							if(tot1 +  c[j - x] <= k){
							//	k -=  c[j - x];
								ans += (c[j - x] - 1);
								tot +=  c[j];
								tot1 +=  c[j - x];
							}
						}
						break;
					} 
					else {
						tot += b[i] * c[i];
						tot1 += b[i] * c[i - x];
						ans += b[i] * (c[i - x]- 1);
					}
				}
				//if(cas == q) de(tot);
				//dd(ans);dd(tot);de(k);
			//	dd(ans);dd(k);de(tot1);
				//cout << ans + k - tot1 << endl;
				cout << ans + k - tot1 << endl;
			//	if(k >= 0)cout << ans + k  << endl;
			//	else cout << ans - min(abs(k), tot1) << endl;
			}
		}
	}
	return 0;
}
/*
10 11
947459 389393 330193 923905 563960 633984 527070 812251 467236 366443
2 8 66247915
1 7 817458
1 7 251377
2 5 746482941
1 4 793058
1 4 586112
2 4 878251711
1 6 879912
1 7 105167
2 9 579210592
2 4 304758765
*/