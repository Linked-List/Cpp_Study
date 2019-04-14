#include "People.h"

int People::count = 0;

int People::getCount(){return count;}

People::People(){
    this->age = 10;
    count++;
}
People::People(int age): age(age){count++;}

void People::setAge(int age){
    this->age = age;
}

int People::getAge(){
    return this->age;
}

bool People::isPerson(People *p){
    return (this==p);
}

People::~People(){
    count--;
    std::cout << "[°íÀÎ]" << this->age << std::endl;
}