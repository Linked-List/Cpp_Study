#include <iostream>
#include <cstring>
using namespace std;

class First{
private:
    char* strOne;
public:
    First(char* str){
        strOne = new char[strlen(str)+1];
    }
    ~First(){ // 여기다가 virtual 달면 해결
        cout << "~First()" << endl;
        delete[] strOne;
    }
};

class Second : public First{
private:
    char* strTwo;
public:
    Second(char* str1, char* str2): First(str1){
        strTwo = new char[strlen(str2)+1];
    }
    ~Second(){
        cout << "~Second()" << endl;
        delete[] strTwo;
    }
};

int main(){
    First* ptr = new Second(const_cast<char*>("simple"), const_cast<char*>("complex"));
    delete ptr;
    // 메모리 누수발생 -> 소멸자 가상화 추가해야됨
    return 0;
}