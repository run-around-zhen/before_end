#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int  i = (a); i < b; i ++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); i++)
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int a[1000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n + 1) {
		cin >> a[i];
	}
	int flag = 0, pos = -1, pos1 = -1;
	rep(i, 1, n){
		if(a[i] > a[i + 1]){
			if(flag == 0) {
				int j = i;
				while(a[j] >=a[j + 1 ]&& j +1 <=  n){
					j ++;
				}
				int k = j;
				pos = i;
				pos1 = j;
				j = i;
				while(a[j - 1] >= a[j]&& j -1 >= 1){
					j --;
				}
				pos = j;
				i = k;
				flag = 1;
			}
			else{
				flag = 2;
			}
		}
	}
	if(flag == 0){
		cout << "1 1" << endl;
	}
	else if(flag == 1){
		rep(i, pos,  (pos1 + pos) / 2 + 1){
			swap(a[i], a[pos1 - i + pos]);
		}
		int ans = 0;
		rep(i, 1, n){
			if(a[i] > a[i + 1]){
				ans = 1;
			}
		}
		if(!ans)cout << pos << " " << pos1 << endl;
		else cout << "impossible" << endl;
	}
	else{
		cout << "impossible" << endl;
	}
}
