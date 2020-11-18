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
struct node1{
	int r, y, t = 10000;
}a[2][100 + 10];
struct node{
	int t, num;
	char flag, type;
}b[100000], c[10000];
bool cmp(node a, node b){
	return a.t < b.t;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s, s1;
	cin >> s >> s1;
	int n;
	cin >> n;
	rep(i, 1, n + 1){
		cin >> b[i].t >> b[i].flag >> b[i].num >> b[i].type;
	}
	sort(b + 1,b + 1 + n, cmp);
	rep(i, 1, n + 1){
		//cin >> t >> flag >> num >> type;
		int t = b[i].t;
		char flag = b[i].flag;
		int num = b[i].num;
		char type = b[i].type;
	//	cout << "??" << t << " " << flag << " " << num << " " << type << endl;
		if(flag == 'h'){
			if(type == 'r') {
				a[0][num].r ++ ;
				a[0][num].t = min(a[0][num].t, t);
				//cout << "??? " << num << " " <<a[0][num].t << endl;
			}
			else{
				a[0][num].y ++;
				if(a[0][num].y >= 2){
					a[0][num].t = min(a[0][num].t, t);
				}
			}
		}
		else{
			if(type == 'r') {
				a[1][num].r ++ ;
				a[1][num].t = min(a[1][num].t, t);
			}
			else{
				a[1][num].y ++;
				if(a[1][num].y >= 2){
					a[1][num].t = min(a[1][num].t, t);
				}
			}
		}
	}
	int cnt = 0;
	rep(i, 0, 2){
		rep(j, 1, 101){
			//cout << i << " " << j << " "<< a[i][j].t << endl;
			if(a[i][j].t != 10000){
				c[++cnt].t = a[i][j].t;
				if(i == 0) c[cnt].flag = 'h';
				else c[cnt].flag = 'a';
				c[cnt].num = j;
			}
		}
	}
	sort(c + 1, c + 1 + cnt, cmp);
	//cout << cnt << endl;
	rep(i, 1, cnt + 1){
		if(c[i].flag == 'h'){
			cout << s << " ";
		}
		else{
			cout << s1 << " ";
		}
		cout << c[i].num <<" " << c[i].t << endl;
	}
	return 0;
}