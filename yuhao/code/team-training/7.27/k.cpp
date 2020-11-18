#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#define PI acos(-1)
#define pb push_back
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define dd(x) cout<<#x<<" = "<<x<<","
#define de(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=5e5+5;
int cnt[N],cnt2[N];
int a[N],b[N],ok[N];
int main()
{
	srand(time(0)); 
    int t = 1;
    //scanf("%d",&t);
    while(t--){
        int n = 500000,k = 1e9;
       // scanf("%d%d",&n,&k);
        int flag=1;
        for(int i=1;i<=n;i++){
         //   scanf("%d",&a[i]);
        	a[i] = rand() % k + 1;
            if(a[i]>k){
                flag=0;
            }
            b[i]=a[i];
            
            cnt[i]=cnt2[i]=0;
        }
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++){
        	a[i]=lower_bound(b+1,b+n+1,a[i])-b;
		}
        if(flag==0){
            printf("NO\n");
            continue;
        }
        int sum=0;
        for(int i=1;i<=min(n,k);i++){
            if(cnt[a[i]]>0){
                sum++;
            }
            cnt[a[i]]++;
        }
        if(sum==0){
            ok[1]=1;
        }
        else{
            ok[1]=0;
        }
        for(int i=2;i<=n;i++){
            if(i+k-1<=n){
                if(cnt[a[i+k-1]]>0)
                sum++;
                cnt[a[i+k-1]]++;
            }
            cnt[a[i-1]]--;
            if(cnt[a[i-1]]>0){
                sum--;
            }
            if(sum==0){
                ok[i]=1;
            }
            else{
                ok[i]=0;
            }
        }
        for(int i=1;i<=min(n,k);i++){
            if(cnt2[a[i]]>0)
            break;
            cnt2[a[i]]++;
            int j=i+1;
            flag=1;
            while(j<=n){
                if(ok[j]){
                    j+=k;
                }
                else{
                    flag=0;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}