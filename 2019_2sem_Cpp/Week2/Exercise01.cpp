#include <iostream>
using namespace std;

namespace X{
    int i,j,k;
}

int k;

void f1(){
    using namespace X;
    i++;
    j++;
    k++; // X::k 인지 ::k인지 모호하여 컴파일 되지않음

    X::k++;
    ::k++;
}

void f2(){
    int i=0;

    using X::i;
    i++;
    // 위의 두줄모두 첫번째와 같은 이유로 i++은 f2의 지역변수 i인지 X::i인지 컴파일러가 구분이 어려움
    // 또한 X::i를 using 해버리면 f2의 지역변수 i에 접근할 방법이 없어질 것이라 판단.

    using X::j;
    using X::k;
    j++;
    k++;
}

int main(){
    f1();
    cout << "i, j, k in namespace X : " << X::i << X::j << X::k << endl;
    cout << "Global variable k : " << ::k << endl << endl;
    f2();
    cout << "i, j, k in namespace X : "<< X::i << X::j << X::k << endl;

    return 0;
}