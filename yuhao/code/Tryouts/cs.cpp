#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    cout << rnd.next("[0-1]{1,100000}") << endl;
    cout << rnd.next("[0-1]{1,100000}") << endl;
}