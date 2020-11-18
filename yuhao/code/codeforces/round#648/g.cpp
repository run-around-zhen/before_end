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
int a[10000], b[10000];
bool vis[500 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		int flag = 0;
		memset(vis,false,sizeof(vis));
		rep(i, 1, n + 1){
			cin >> a[i];
		}
		rep(i, 1, n + 1){
			cin >> b[i];
		}
		if(n % 2 == 1 && a[(n + 1) / 2] != b[(n + 1) / 2]){
			cout <<"No" << endl;
			continue;
		}
		rep(i, 1, n / 2 + 1){
			int flag1 = 0;
			rep(j ,1, n + 1){
				if(a[j] == b[i] && a[n - j + 1] == b[n - i + 1] && !vis[j] && !vis[n - j + 1]) {
					vis[j] = true;
					vis[n - j + 1] = true;
					flag1 = 1;
					break;
				}
			}
			if(!flag1){
				flag = 1;
				break;
			}
		}
		/*sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		rep(i, 1, n + 1){
			if(a[i] != b[i]){
				flag = 1;
				break;
			}
		}*/
		if(flag == 0){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	return 0;
}