#include <iostream>
#include "People.h"
#include "C.h"
#include "AddressBook.h"

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
    People peoples1[10];
    AddressBook addBook1;
    for(int i=0;i<10;i++){
        peoples1[i].setAge(20+i);
    }
    cout << addBook1.setAverage(peoples1,10) << endl;

    People *peoples2 = new People[5]{People(5),People(3),People(2),People(0),People(20)};

    cout << addBook1.setAverage(peoples2,5) << endl;
    cout << People::getCount() << endl;

    delete[] peoples2;
    cout << People::getCount() << endl;
}