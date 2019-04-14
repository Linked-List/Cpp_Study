#pragma once
#include <iostream>

class People{
private:
    int age;
public:
static int count;
static int getCount();
    People();
    People(int age);
    ~People();
    void setAge(int age);
    int getAge();
    bool isPerson(People* p);
};