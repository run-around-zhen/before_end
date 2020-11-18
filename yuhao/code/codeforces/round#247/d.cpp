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
int sum[10000][100];
ll m, k;
ll c[100][100];
int check(int i){
	int sum = 0;
	while(i){
		sum += i % 2;
		i /= 2;
	}
	return sum;
}
/*ll cal(ll rt, int k){
	cout << rt <<  " "<< k << "!!" << endl;
	if(rt < 0 || k < 0) return 0;
	if(rt <=1024) return sum[rt][k];
	ll res = 0;
	ll tmp = 1024;
	ll use = 11;
	while(1){
		tmp *= 2;
		
		//cout << tmp << " " << use << " " << rt << endl;
		if(tmp <= rt){
			rep(i, 0, use + 1){
				if(k - i - 1 < 0) break;
				res += c[use][i] * sum[1024][k - i - 1];
				cout << rt << " " <<c[use][i] * sum[1024][k - i - 1]<< " " << use << " " << i << " " << k - i  - 1 << endl;
				//cout << c[use][i] <<" " << " "<<k - i << " "<< sum[1024][k - i] << " ???" << endl;
			}
		}
		else{
			
			while(tmp > rt ){
				tmp /= 2;
			}
			cout << res << "&&&" ;
			res += cal(rt - tmp, k - 1);
			break;
		}
		use ++;
	}
	return res;
}*/
ll cal(ll rt){
	ll res = 0;
    ll cnt = 0;
    per(i, 0, 63){
    	//cout << ( 1ll << i ) << endl;
        if(rt & (1ll << i)){
            if(k - cnt >=0) res+=c[i][k - cnt];
            cnt++;
        }
    }
    return res;
}
ll check(ll i){
	return cal(i * 2) - cal(i);
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	rep(i, 0, 4212 + 1){
		sum[i][check(i)] ++;
	}
	rep(i, 1, 4212 +1){
		rep(j, 0, 65) sum[i][j] += sum[i - 1][j];
	}
	//cout << sum[4212][2] << " "<< sum[1024][1] << endl;
	//rep(i, 1, 110) cout << i << " " << sum[i][2] << endl;
	//p[1] = 1;
	rep(i, 0, 65){
		//c[i][1] = 1;
		c[i][0] = 1;
		rep(j, 1, i + 1){
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	//cout << sum[4212][2] << endl;
	/*rep(i, 0, 10){
		rep(j, 0, i + 1){
			cout << c[i][j] << " ";
		}
		cout << endl;
	}*/
	//rep(i, 1, 65) cout << i << " " << sum[i][2] << " " << endl;
	cin >> m >> k;
	//cout << cal(4212) << endl;
	ll l = 1, r = 1e18;
	while(l <= r){
		ll mid = (l + r) / 2;
		//cout << l << " " << r << " " << mid << " " << cal(mid, k) << endl;	
		if(check(mid) == m){
			cout << mid << endl;
			return 0;
		}
		if(check(mid) > m){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	return 0;
}