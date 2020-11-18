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
int dir[8][2] = {1, 1, 1, 0, 1, -1, 0, 1, 0, -1, -1, 1, -1, 0, -1, -1};
map<pair<ll, ll >, bool>ma;
bool check(ll x, ll y){
	return __gcd(x, y) > 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    /*for(int i=0;i<8;++i){
		for(int j=0;j<2;j++){
    		cout<<dir[i][j]<<'\n';
		}
    }*/
   	int T;
   	cin >> T;
   	while(T --){
   		ll x, y;
   		cin >> x >> y;
   		ma.clear();
   		ma[mp(x, y)] = 1;
   		queue<pair<ll, ll > >q;
   		q.push(mp(x, y));
   		ma[mp(x, y)] = 1;
   		int cnt = 0;
   		int flag = 0;
   		while( !q.empty()){
   			ll xx = q.front().fi;
   			ll yy = q.front().se;
   			cnt ++;
   			if(xx == yy) {
   				flag = 1;
   				break;
   			}
   			q.pop();
   			rep(i, 0, 8){
   				ll xxx = xx + dir[i][0];
   				ll yyy = yy + dir[i][1];
   				if(check(xxx, yyy)){
   					if(!ma[mp(xxx, yyy)]){
   						q.push(mp(xxx, yyy));
   						ma[mp(xxx, yyy)] = 1;
   					}
   					cnt ++;
   				}
   			}
   		}
   		if(flag) {
   			cout <<"0/1" << endl;
   			while(!q.empty()){
   				q.pop();
   			}
   			continue;
   		}
   			int sum = 0;
   			rep(i, 0, 8){
   				ll xx = x + dir[i][0];
   				ll yy = y + dir[i][1];
   				//cout << xx << " " << yy <<endl;
   				if(check(xx, yy)) sum ++;
   			}
   			int gcd = __gcd(sum + 1, cnt);
   			cout << (sum  + 1) / gcd<< "/" << cnt / gcd << endl;
   	}
    return 0;
}