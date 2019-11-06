#include <iostream>

class Parent{
protected:
    int data;

public:
    void method(int param){
        data = param;
    }
    void display(){
        printf("%d\n",data);
    }
};

class Child : public Parent{
protected:
    int data1;

public:
    void method1(int param){
        data1 = param;
    }
    void display1(){
        printf("%d, %d\n", data, data1);
    }
};

class GrandChild : public Child{
protected:
    int data2;

public:
    void method2(int param){
        data2 = param;
    }
    void display2(){
        printf("%d, %d, %d\n", data, data1, data2);
    }
};

int main(){
    GrandChild obj;
    
    obj.method(10);
    obj.display();
    obj.method1(20);
    obj.display1();
    obj.method2(30);
    obj.display2();
    return 0;
}