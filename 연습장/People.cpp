#include "People.h"

People::People(){
    this->age = 0;
}
People::People(int age): age(age){}

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
    std::cout << "[°íÀÎ]" << this->age << std::endl;
}