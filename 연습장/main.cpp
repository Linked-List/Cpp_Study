#include <iostream>
#include "Person.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Person a;

    a.setAge(22);
    cout << a.getAge() << endl;
    cout << "Hello World!" << endl;
    // this test
    return 0;
}
