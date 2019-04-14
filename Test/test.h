#pragma once
#include <iostream>

class test{
public:
    int num1, num2;
    test(int num1=20, int num2=10) : num1(num1), num2(num2){
        std::cout << "세개 들어간 생성자" << std::endl;
    }
    void print(int n=10);
};