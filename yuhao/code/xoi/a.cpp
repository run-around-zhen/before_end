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
	int n;
	while(scanf("%d", &n) != EOF){
		char ans1[1000000 + 10], ans2[1000000 + 10],s[1000000 + 10];
		scanf("%s%s", ans1, ans2);
		int len = strlen(ans1);
		rep(i, 1, n + 1){
			scanf("%s", s); 
			int num1 = 0, num2 = 0;
			rep(j, 0, len){
				if(s[j] == ans1[j]) num1 ++ ;
				if(s[j] == ans2[j]) num2 ++;
			}
			cout << max(num1, num2) << endl;
		}
	}
	return 0;
}