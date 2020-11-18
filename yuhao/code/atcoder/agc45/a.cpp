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
char s[10000];
ll a[100000 + 10];
ll d[200 + 10];
bool dfs(int l, int r, ll sum){
	//cout << l << " " << r << " " << sum << endl;
	if(sum == 0) return true;
	if(l > r) return false;
	rep(i, l, r + 1){
		if(dfs(i + 1, r, sum ^ a[i])) return true;
	}
	return false;
}
void add(ll x)
{
    for(int i=62;i>=0;i--)
    {
        if(x&(1ll<<i))
        {
            if(d[i])x^=d[i];
            else
            {
                d[i]=x;
                break;
            }
        }
    }
}
bool check(ll x){
	for(int i=62;i>=0;i--)
    {
        if(x&(1ll<<i))
        {
            if(d[i])x^=d[i];
            else
            {
                return false;
            }
        }
    }
    return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T --){
		int n;
		cin >> n;
		rep(i, 1, n + 1) cin >> a[i];
		cin >> (s + 1);
		//cout << (s+ 1) << endl;
		int flag = 0;
		rep(i, 1, n + 1){
			if(s[i] == '1'){
				/*int l = i + 1;
				while(s[l] == '1' && l <= n) l ++;
				int r = l;
				while(s[r] == '0' && r <= n) r ++;
				/*if(dfs(l, r, a[i])) continue;
				else {
					flag = 1;
					break;
				}*/
				memset(d, 0, sizeof(d));
				rep(j, i, n + 1) {
					if(s[j] == '0'){
						add(a[j]);
					}
				}
				if(!check(a[i])){
					flag = 1;
					break;
				}
			}
			else continue;
		}
		if(flag == 1){
			cout << "1" << endl;
		}
		else{
			cout << "0" << endl;
		}
	}
	return 0;
}
/*
1 6
8 3 4 5 6 7
111000
*/