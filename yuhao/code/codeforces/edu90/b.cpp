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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		string s;
		cin >> s;
		int n = s.size();
		stack<char>st;
		int ans = 0;
		rep(i, 0, s.size()){
			if(s[i] == '0' && st.size() != 0 && st.top() == '1') {
				st.pop();
				ans ++;
			}
			else if(s[i] == '1' && st.size() != 0 && st.top() == '0') {
				st.pop();
				ans ++;
			}
			else st.push(s[i]);
		}
		if(ans % 2 == 1){
			cout << "DA" << endl;
		}
		else{
			cout <<"NET" << endl;
		}
	}
	return 0;
}