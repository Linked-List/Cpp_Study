#pragma once
#include <iostream>

class People{
private:
    int age;
public:
    People();
    People(int age);
    ~People();
    void setAge(int age);
    int getAge();
    bool isPerson(People* p);
};