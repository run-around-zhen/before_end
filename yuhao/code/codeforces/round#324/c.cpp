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
int ans[200000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, t;
	cin >> n >> t;
	string s1, s2;
	cin >> s1 >> s2;
	int num = 0;
	int last = n - t;
	int t1 = 0 , t2 = 0;
	rep(i, 0, s1.size()) ans[i] = -1;
	rep(i, 0, s1.size()){
		if(s1[i] == s2[i]) num ++;
	}
	rep(i, 0, s1.size()){
		if(s1[i] == s2[i]) {
			continue;
		}
		else{
			if(t1 == t2 && t1 + num >= last) continue;
			if(t1 < last || t2 < last){
				if(t1 < t2){
					ans[i] = s1[i] - 'a';
					t1 ++;
				}
				else{
					ans[i] = s2[i] - 'a';
					t2 ++;
				}
			//	cout << i <<"!!" <<endl;
			}
		}
	}
	//cout << t1 << " " << t2 << endl;
	if(t1 != t2){
		cout << "-1" << endl;
		return 0;
	}
	rep(i, 0 ,s1.size()){
		if(ans[i] != -1) continue;
		if(s1[i] == s2[i]){
			if(t1 == last){
				rep(j, 0, 26){
					if(s1[i] - 'a' != j && s2[i] - 'a' != j){
						ans[i] = j;
						break;
					}
				}
			}
			else{
				t1 ++;
				t2 ++;
				ans[i] = s1[i] - 'a';
			}
		}
		else{
			rep(j, 0, 26){
				if(s1[i] - 'a' != j && s2[i] - 'a' != j){
					ans[i] = j;
					break;
				}
			}
		}
	}
	if(t1 == t2 && t2 == last){
		int sum = 0, sum1 = 0;
		rep(i, 0, s1.size()){
			if(ans[i] + 'a' != s1[i]) sum++;
			if(ans[i] + 'a' != s2[i]) sum1++;
		}
		//if(sum != sum1 || sum != t) while(1);
		rep(i, 0, s1.size()){
			cout << (char)(ans[i] + 'a');
		}
	}
	else{
		cout << "-1" << endl;
	}
	
	return 0;
}