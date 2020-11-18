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
map<string, int> ma;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	//freopen("1.in","write", stdout);
	srand(time(0));
	int n = 50000, q = 100;
	cout << n << " " << q << endl;
	rep(i, 1, q + 1){
		int op =  rand() % 3 + 1;
		if(op == 1){
			string s = "aaaa";
			while(ma[s] == 1){
				s.clear();
				rep(j, 0, 4){
					s += (char)(rand() % 26 + 'a');
				} 
			}
			ma[s] = 1;
			cout << op << " " << s << " " << rand() % 200 + 1 << endl;
		}
		else if(op == 2){
			int flag = 0;
			int cnt ;
			if(ma.size() != 0) cnt = rand() % (int)ma.size();
			else cnt = 0;
			int time = 0;
			for(auto i : ma){
				if(time == cnt){
					cout << op << " " << i.fi << endl;
					flag = 1;
					break;
				}
				time ++;
			}
			if(!flag){
				cout << op << " " << "fuck" << endl;
			}
		}
		else if(op == 3){
			int flag = 0;
			int cnt ;
			if(ma.size() != 0) cnt = rand() % (int)ma.size();
			else cnt = 0;
			int time = 0;
			for(auto i : ma){
				if(time == cnt){
					cout << op << " " << i.fi << endl;
					flag = 1;
					break;
				}
				time ++;
			}
			if(!flag){
				cout << op << " " << "fuck" << endl;
			}
		}
	}
	return 0;
}