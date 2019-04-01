#pragma once

class Person{
public:
    void setAge(unsigned n);
    unsigned getAge();
private:
    unsigned age;
};

//void Person::setAge(unsigned n){ age = n; }
//unsigned Person::getAge(){ return age; }