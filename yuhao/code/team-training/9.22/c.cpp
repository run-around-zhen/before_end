#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	while(n --){
		long long x1, y1,x2, y2, x3, y3;
		scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &x3, &y3);
		if((x1- x2)* (y3 - y2) - (x3 - x2) * (y1 - y2) > 0 ){
			printf("Clockwise\n");
		}
		else{
			printf("Counterclockwise\n");
		}
	}
}
