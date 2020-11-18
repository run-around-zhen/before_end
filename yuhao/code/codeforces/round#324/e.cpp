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
typedef vector<pii> vi;
int pos[1000000 + 10];
int a[1000000 + 10];
int b[1000000 + 10];
vi res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n + 1){
		cin >> b[i];
		pos[b[i]] = i;
	}
	ll ans = 0;
	rep(i, 1, n + 1){
		if(a[i] == b[i]) continue;
		int pos_2 = -1;
        rep(j, i + 1, n + 1){
            if(a[j] == b[i]){
                pos_2 = j;
                break;
            }
        }
        while(1){
            rep(j, i, pos_2){
                if(pos[a[j]]>=pos_2){
                    ans += abs(pos_2 - j);
                    res.pb(mp(pos_2, j));
                    swap(pos_2,j);
                    swap(a[pos_2],a[j]);
                    break;
                }
            }
            if(pos_2 == i) break; 
        }
	}
	cout << ans << endl;
	cout << res.size() << endl;
	for(auto i :res){
		cout << i.fi << " " << i.se << endl;
	}
	return 0;
}