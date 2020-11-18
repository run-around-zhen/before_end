#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxn=2e5+5;


int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    string s = inf.readToken();
    inf.readEoln();
    string t = inf.readToken();
    inf.readEoln();
    int n = s.size();
    int m = s.size();
    ensuref(n >= 1, "???");
    ensuref(m >= 1, "???");
    ensuref(n <= 1000000, "???");
    ensuref(m <= 1000000, "???");
    for(int i = 0; i < n; i ++ ){
    	ensuref(s[i] == '0' || s[i] == '1', "???");
    }
	for(int i = 0; i < m; i ++ ){
    	ensuref(t[i] == '0' || t[i] == '1', "???");
    }
    return 0;
}