#include <iostream>
#include "People.h"
#include "C.h"

using namespace std;

People& newPeopleF(int num){
    static People p;
    p.setAge(num);
    return p;
}
People& newPeopleF2(int num){
    People* p = new People();
    p->setAge(num);
    return *p;
}


int main(int argc, char const *argv[])
{
    C c;
    C c2(-100);
    c.printAll();
    c2.printAll();

    return 0;
}