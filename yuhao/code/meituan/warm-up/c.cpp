#include"find.h"
using namespace std;
int find_pos(int n,int x)
{
	int l = 1, r = n;
	while(l <= r){
		int  mid = (l + r ) / 2;
		if(query(mid) <= x) l = mid;
		else r = mid - 1;
	}
	return l;
}