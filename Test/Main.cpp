#include <iostream>
#include "test.h"

using namespace std;

int main(){
    test& T = *(new test());
    cout << T.num1 << " " << T.num2 << endl;

    delete &T;

    return 0;
}