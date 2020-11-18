#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxn=2e5+5;
bool flag=0;
long long tot=0;
int f[maxn];
int find_father(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find_father(f[x]);
}

void test()
{
	int n=inf.readInt(1,100000);
	inf.readSpace();
	int s=inf.readInt(1,n);
	inf.readSpace();
	int c=inf.readInt(1,100000);
	inf.readSpace();
	int d=inf.readInt(1,100000);
	inf.readEoln();
	tot+=n;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<n;i++)
	{
		int u=inf.readInt(1,n);
		inf.readSpace();
		int v=inf.readInt(1,n);
	//	inf.readSpace();
		//int w=inf.readInt(0,1000000000);
		inf.readEoln();
		int fu=find_father(u),fv=find_father(v);
		f[fu]=f[fv];
	}
	for(int i=2;i<=n;i++)
		ensuref(find_father(i)==find_father(1), "The graph is not connected" );
	for(int i = 1; i <= n; i++){
		int cc=inf.readInt(1,100000);
		inf.readSpace();
		int dd=inf.readInt(1,100000);
		inf.readEoln();
	}
}

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
	test();
    inf.readEof();
    return 0;
}