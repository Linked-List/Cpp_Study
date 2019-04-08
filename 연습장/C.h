#pragma once
#include <iostream>

class C{
private:
    int x;
    const int num1;
    const int num2;
    const int num3 = 10;

public:
    C(): num1(0),num2(-1){
        x = 5;
        std::cout << "made" << std::endl;
    }
    C(int x): num1(55), num2(110){
        this->x = x;
    }
    ~C(){
        std::cout << "delete" << std::endl;
    }
    void printAll(){
        std::cout << x << " " << num1 << " " << num2
        << " " << num3 << std::endl;
    }
};